
'''Author = Sitam Meur. 
- Implementation of number guesser game with help of Python.
- Python random module is being used.''' 

# importing the python random module. 
## this module implements pseudo-random number generators for various distributions.

import random

# giving user the choice to choose the upper change. 
Upper_range= int(input("Enter the upper range as per your choice. "))

# upper range can not be less than zero.
## - handling the above mentioned condition using if-else or conditional statement. 
## - if user given upper range is less than zero then telling to give the no. greater than zero next time, thereafter stop or quit the programme. 
if Upper_range <=0:
    print("Please type a number greater than zero next time!")
    quit()

# generating random numbers by the help of random.randint() method. 
## random.randint(a, b) = Return a random integer N such that a <= N <= b. Alias for randrange(a, b+1).
random_num = random.randint(0,Upper_range)

# creating the variable 'guess_no' to keep track the no. of times, it took for the user to match the number. 
guess_no =0

# main game. 
while True:
    guess_no = guess_no + 1
    User_guess=int(input("Enter your guess number. "))
    if User_guess == random_num:
      # if user given no. and random generated no. are same that means a correct one.
      ## - then no need to run the programme anymore and break out of the loop. 
        print("Congrats! The corrct guess.")
        break
    else:
      # if user given no. and random generated no. are not same then giving them opportunity to try again.
        print("Sorry! The wrong one. Try another one.")
        
# finalising the result. 
print("You got the correct one in total attempts of " + str(guess_no) + " guesses" )
