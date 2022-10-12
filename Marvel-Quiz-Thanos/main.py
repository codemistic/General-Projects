print("WELCOME TO QUIZ!")

playing = input("Do you want to play? ")

if playing.lower() != "yes":
    quit()

print("Okay,LEts get Started :)")
score = 0

answer = input("What does MCU stand for? ")
if answer.lower() == "marvel cinematic universe":
    print("Correct!")
    score += 1
else:
    print("Wrong!")

answer = input("Who is called the mad titan? ")
if answer.lower() == "thanos":
    print("Correct!")
    score += 1
else:
    print("Wrong!")

answer = input("Name Six infinity stones according to order of acquisition by Thanos. ")
if answer.lower() == "power space reality soul time mind":
    print("Correct!")
    score += 1
else:
    print("Wrong!")

answer = input(" What was Thanos' Team Called? ")
if answer.lower() == "black order":
    print("Correct!")
    score += 1
else:
    print("Wrong!")

print("You Got " + str(score) + " questions correct!")
print("You Got " + str(score/4 * 100) + " %")
