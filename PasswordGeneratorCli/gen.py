import argparse
import random


class Generator:
    nums = '0123456789'
    alpal = 'abcdefghijklmnopqrstuvwxyz'
    alpau = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    symb =  '!@#$%^&*-_.<>?~'

    def __init__(self,pass_len: int) -> None:
        self.n = pass_len

    def gen(self) -> str:
        password = ''
        for i in range(1,self.n+1):
            ps = random.randint(0,3)
            if ps == 0:
                index = round(abs(random.gammavariate(128e-2,256e-3)*(len(self.alpal)-1)))
                password = password + self.alpal[(index+1)%26]
            elif ps == 1:
                index = round(abs(random.betavariate(128e-2,256e-3)*(len(self.alpau)-1)))
                password = password + self.alpau[(index+1)%26]
            elif ps == 2:
                index = round(abs(random.lognormvariate(128e-2,256e-3)*(len(self.nums)-1)))
                password = password + self.nums[(index+1)%9]
            else:
                index = round(abs(random.gammavariate(128e-2,256e-3)*(len(self.symb)-1)))
                password = password + self.symb[(index+1)%15]
        return password


def main(args):
    if args.l is None or args.l < 0:
        print("Invalid length: length should be positive integer.")
    elif args.l < 5:
        print("TooShort: length should be greater than six.")
    else:
        g = Generator(args.l)
        print(g.gen())

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument(
        '--l',
        type=int,
        default=8,
        help='password length'
    )
    main(args=parser.parse_args())


