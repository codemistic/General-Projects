# importing random module which will generate the random number.

import random

# storing the random number in the randNumber variable
randNumber = random.randint(1, 100)
userGuess = None
guesses = 0

# creating the lives for the game
lives = 5

while(userGuess != randNumber and lives>0):
    userGuess = int(input(f"Enter your guess Number Between 1 - 100 (You have {lives} lives left ) : "))
    lives -= 1
    guesses+=1
    if(userGuess==randNumber):
        print("You guessed it right!")
    else:
        if(userGuess>randNumber):
            print("You guessed it wrong! Enter a smaller number")
        else:
            print("You guessed it wrong! Enter a larger number")

if lives == 0 and userGuess!=randNumber :
	print("You loose !!! ")
	print(f"The correct number is {randNumber} ")
else:
	print(f"You guessed the number in {guesses} guesses")

# checking the highest score till now and storing it in the hiscore variable

'''

with open("hiscore.txt", "r") as f:
    hiscore = int(f.read())

# if the record has been broken then update it 
if(guesses<hiscore):
    print("You have just broken the high score!")
    with open("hiscore.txt", "w") as f:
        f.write(str(guesses))
        
'''
