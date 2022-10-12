import random
user_wins = 0
pc_wins = 0

options = ["rock","paper","scissor"]

while True:
    user_input = input("Type Rock/Paper/Scissor or Q to quit: ").lower()
    if user_input == "q":
        break

    if user_input not in options:
        continue

    random_number = random.randint(0,2)
    #rock : 0,paper: 1,scissors: 2
    computer_pick = options[random_number]
    print("PC Picked",computer_pick + ".")

    if user_input == "rock" and computer_pick == "scissors":
        print("You Won!")
        user_wins += 1
        
    elif user_input == "paper" and computer_pick == "rock":
        print("You won!")
        user_wins += 1

    elif user_input == "scissors" and computer_pick == "paper":
        print("You won!")
        user_wins += 1

    else:
        print("You lost!")
        pc_wins += 1

print("You won", user_wins, "times.")
print("The computer won", pc_wins, "times.")


print("BYE!")
