'''Author = Sitam Meur. 
- Dice Roller Simulator with help of Python.
- Python random module is being used.''' 

# importing the random module. 
import random

# defining the main function of the dice rolling project. 

def roll_dice():
  
  # creating one dictionary in python containing all the faces representation of a dice from (1-6). 
    dice_drawing = {
        1: (
            "-----",
            "|   |",
            "| o |",
            "|   |",
            "-----",
        ),
        2: (
            "-----",
            "|o  |",
            "|   |",
            "|  o|",
            "-----",
        ),
        3: (
            "-----",
            "|o  |",
            "| o |",
            "|  o|",
            "-----",
        ),
        4: (
            "-----",
            "|o o|",
            "|   |",
            "|o o|",
            "-----",
        ),
        5: (
            "-----",
            "|o o|",
            "| o |",
            "|o o|",
            "-----",
        ),
        6: (
            "-----",
            "|o o|",
            "|o o|",
            "|o o|",
            "-----",
        ),

    }


    # taking input from the user as Yes / No. 
    # though will handle input string character types later in the programme. 
    dice_roll = input("Do You wanna roll the dice ? (Yes / No): ")
    
    ''' .lower() is a built-in Python method primarily used for string handling. 
    The .lower() method takes no arguments and returns the lowercased strings from the given string by converting each uppercase character to lowercase. 
    If there are no uppercase characters in the given string, it returns the original string.'''
    
    # by implementing .lower() method, giving user full advantage while giving inputs. As it converts uppercase characters into lower case characters. 
    while(dice_roll.lower() ==  "Yes".lower()):
        
       ## generating random dice rolls by the help of random.randint() method. 
       ## random.randint(a, b) = Return a random integer N such that a <= N <= b. Alias for randrange(a, b+1).
        
        dice1 = random.randint(1,6)
        dice2 = random.randint(1,6)

        print("dice rolled: {} and {}".format(dice1, dice2))

       ## displaying rolled dice faces by accessing the "dice_drawing" dictionary implemented above.  
      
        print("\n".join(dice_drawing[dice1]))
        print("\n".join(dice_drawing[dice2]))

       ## input by the user that to continue more or not. 
        dice_roll = input("Do You wanna roll again ? (Yes / No): ")

# finally calling the function. 
roll_dice()

