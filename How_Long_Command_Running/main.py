from __future__ import print_function

import argparse
import logging
import sys
import os

from datetime import timedelta
from subprocess import Popen
from time import time, sleep, ctime
import psutil

from colorama import init
from termcolor import colored

# use Colorama to make Termcolor work on Windows too
init()


# We can now use Termcolor for all colored text output & also OS independent.


def red(text):
    RED = '\033[91m'
    END = '\033[0m'
    return RED + text + END


def exception_handler(dummy_exception_type, exception, dummy_traceback):
    '''hide traceback'''
    print("%s" % exception)
sys.excepthook = exception_handler


def error_and_exit(*args):
    '''Print each argument to stderr, then exit with non-zero exit code.'''
    for arg in args:
        print(arg, file=sys.stderr)
    sys.exit(-1)


class Process(object):

    def __init__(self, pid=None, command=None):
        self.pid = pid
        if self.pid is None:
            self.process = Popen(command)
            self.start_time = time()
        else:
            self.process = psutil.Process(self.pid)
            self.start_time = self.process.create_time()
            command = self.process.cmdline()
        self.command = ' '.join(command)

    def is_running(self):
        if self.pid is None:
            return self.process.poll() is None
        else:
            return self.process.is_running()


class HowLong(object):

    def __init__(self):
        self.log_level = logging.INFO  # default logging level

        parser = argparse.ArgumentParser(description='Time a process')
        parser.add_argument('-i', type=float, nargs='?', metavar='interval',
                            help='the timer interval, defaults to 1 second')

        group = parser.add_mutually_exclusive_group()
        group.add_argument('-c', metavar='command', type=str, nargs=1,
                           help='a valid command')
        group.add_argument('-p', metavar='pid', type=int, nargs=1,
                           help="a valid process id to monitor - see 'ps aux'")
        parser.add_argument('-f', metavar='file', type=str, nargs=1,
                            help='output to file insted of stdout')
        parser.add_argument('-l', metavar='log level', nargs=1,
                            choices=['ERROR', 'INFO', 'DEBUG'],
                            help='set log level to ERROR/INFO/DEBUG')
        parser.add_argument('command_args', metavar='cmd_args', type=str,
                            nargs=argparse.REMAINDER,
                            help='additional arguments for target command')
        # store_true so we don't need paramaters
        parser.add_argument('-m',
                            help='list history of HowLong',
                            action="store_true")
        parser.add_argument('-mc', action="store_true",
                            help='clear history of HowLong')
        parsed_args = parser.parse_args()

        self.timer_interval = parsed_args.i if parsed_args.i else 1

        command = parsed_args.c if parsed_args.c else None
        cmd_args = parsed_args.command_args or None

        if command is None and cmd_args:
            error_and_exit("Can't have no command but have command args",
                           "usage with command is: "
                           "howlong [options] -c your_command your_options")

        self.log_file = parsed_args.f[0] if parsed_args.f else None
        if self.log_file:
            logging.basicConfig(filename=self.log_file, level=self.log_level,
                                format='%(levelname)s:%(message)s')
        else:
            logging.basicConfig(level=self.log_level,
                                format='%(levelname)s:%(message)s')

        if parsed_args.p:
            self.pid = int(parsed_args.p[0])
            self.command = None
            if self.pid not in psutil.pids():
                error_and_exit("argument p must be a valid pid, "
                               "%d is not one" % self.pid)
        else:

            if parsed_args.m:
                try:
                    with open('history.txt', 'r') as f:
                        history = f.readlines()
                        for line in history:
                            logging.info(line.strip())

                except:
                    logging.warning("No history avaialable\n")
                exit()
            elif parsed_args.mc:
                if os.path.isfile('history.txt'):
                    try:
                        os.remove('history.txt')
                        logging.warning('History deleted!\n')
                    except:
                        logging.warning('Can\'t delete history!\n')
                else:
                    logging.warning('No history avaialable!\n')
                exit()
            else:
                if command is None:
                    error_and_exit("you must use either -p or -c")
                self.pid = None
                cmd_args = [] if cmd_args is None else cmd_args
                self.command = command + cmd_args

        if parsed_args.l == ["ERROR"]:
            self.log_level = logging.ERROR
        elif parsed_args.l == ["DEBUG"]:
            self.log_level = logging.DEBUG

    def run(self):
        process = Process(pid=self.pid, command=self.command)
        readable_command = process.command
        start_time = process.start_time

        logging.debug(colored("Running " + readable_command), 'green')
        # append process starting time to history
        with open('history.txt', 'a') as history:
            history.write("pid #{}  started at  {}\n".format(
                self.pid, ctime(int(start_time))))
        while process.is_running():
            sleep(self.timer_interval)
            elapsed_time = (time() - start_time) * 1000
            logging.info(
                colored(str(timedelta(milliseconds=elapsed_time)), 'blue'))
        logging.debug(colored("Finished " + readable_command), 'red')
        # append process finishing time to history
        with open('history.txt', 'a') as history:
            history.write("pid #{}  finished at  {}\n".format(
                self.pid, ctime(int(time()))))
        logging.debug(colored("Running " + readable_command, 'green'))
        while process.is_running():
            sleep(self.timer_interval)
            elapsed_time = (time() - start_time) * 1000
            logging.info(colored(str(timedelta(milliseconds=elapsed_time)),
                                 'blue'))
        logging.debug(colored("Finished " + readable_command, 'red'))


def howlong():
    HowLong().run()


if __name__ == "__main__":
    howlong()
