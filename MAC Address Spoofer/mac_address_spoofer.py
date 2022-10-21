#!/usr/bin/env python

import subprocess
import optparse
import re


def arguments_func():
	parser = optparse.OptionParser()
	parser.add_option("-i","--interface",dest="interface",help="Interface to change its MAC address")
	parser.add_option("-m","--mac",dest="new_mac",help="New MAC address")
	(options, arguments) = parser.parse_args()
	if not options.interface:
		parser.error("\033[1;31m [-] Please specify an interface, use --help for more info")
	elif not options.new_mac:
		parser.error("\033[1;31m [-] Please specify a new MAC address, use --help for more info")
	else:
		return options

def mac_changer(interface, new_mac):
	print("\033[1;33m [+] Changing MAC address for " + interface + " to " + new_mac)
	subprocess.call(["ifconfig", interface, "down"])
	subprocess.call(["ifconfig",interface,"hw","ether",new_mac])
	subprocess.call(["ifconfig",interface,"up"])


def get_current_mac(interface):
	ifconfig_result = subprocess.check_output(["ifconfig", interface])
	mac_search_result = re.search(r"\w\w:\w\w:\w\w:\w\w:\w\w:\w\w", ifconfig_result)

	if mac_search_result:
		return mac_search_result.group(0)
	else:
		print("\033[1;31m [-] Could not read MAC address")



(options) = arguments_func()
current_mac = get_current_mac(options.interface)
print("\033[1;34m Your current MAC address is: " + str(current_mac))
mac_changer(options.interface, options.new_mac)
current_mac = get_current_mac(options.interface)
if current_mac == options.new_mac:
	print("\033[1;32m MAC address was successfully changed to " + current_mac)
else:
	print("\033[1;31m [x] MAC address did not get changed")