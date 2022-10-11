from tkinter import *
from PIL import Image, ImageTk
from random import randint
import pygame

# main window
window = Tk()
width= window.winfo_screenwidth()
height= window.winfo_screenheight()
#setting tkinter window size
window.geometry("%dx%d" % (width, height))

window.title("ROCK PAPER SCISSOR GAME")
bg=ImageTk.PhotoImage(Image.open('C:/Users/ahraz/Desktop/rp/bb0.jpg'))
label1 = Label( window,width=1366,height=768, image = bg).place(x = 0,y = 0)
#window.resizable(True,True)
#window.configure(background="#B6C3CC")
heading = Label(window,text="ROCK PAPER SCISSOR SHOOT!", font=("arial", 40, 'bold'), bg='#ffdb58',fg="black",relief='solid').place(x=300, y=50)
pygame.mixer.init()
pygame.mixer.music.load("C:/Users/ahraz/Downloads/gamemusic.mp3")
pygame.mixer.music.set_volume(0.5)
pygame.mixer.music.play(-1)


# images
rock1 = Image.open("C:/Users/ahraz/Desktop/rp/rock2.png")
rock1 = rock1.resize((180, 180))

paper1 = Image.open("C:/Users/ahraz/Desktop/rp/paper2.jpg")
paper1 = paper1.resize((180, 180))

scissor1 = Image.open("C:/Users/ahraz/Desktop/rp/scissor2.png")
scissor1 = scissor1.resize((180, 180))

rock2 = Image.open("C:/Users/ahraz/Desktop/rp/rock.png")
rock2 = rock2.resize((180, 180))

paper2 = Image.open("C:/Users/ahraz/Desktop/rp/paper1.jpg")
paper2 = paper2.resize((180, 180))

scissor2 = Image.open("C:/Users/ahraz/Desktop/rp/scissor1.png")
scissor2 = scissor2.resize((180, 180))

rock_img = ImageTk.PhotoImage(rock1)
paper_img = ImageTk.PhotoImage(paper1)
scissor_img = ImageTk.PhotoImage(scissor1)
rock_img_comp = ImageTk.PhotoImage(rock2)
paper_img_comp = ImageTk.PhotoImage(paper2)
scissor_img_comp = ImageTk.PhotoImage(scissor2)

# default picture

user_label = Label(window, image=scissor_img, bg="#3e5b64")
comp_label = Label(window, image=scissor_img_comp, bg="#3e5b64")
comp_label.place(x=140,y=300)
user_label.place(x=1050,y=300)

# scores

userScore = Label(window, text=0, font=("arial",40,'bold'),relief='solid', bg="white", fg="#3e5b64")
computerScore = Label(window, text=0, font=("arial",40,'bold'),relief='solid', bg="white", fg="#3e5b64")
computerScore.place(x=360,y=350)
userScore.place(x=950,y=350)
h_list=["GAME HISTORY"]

# indicators
class indicators:
    def __init__(self):
        self.user_indicator = Label(window,width=8,height=0, font=("arial",30,'bold'), text="USER",relief='solid', bg="white", fg="#3e5b64")

        self.comp_indicator = Label(window,width=10,height=0, font=("arial",30,'bold'), text="COMPUTER",relief='solid', bg="white", fg="#3e5b64")

        self.user_indicator.place(x=1040,y=200)
        self.comp_indicator.place(x=140,y=200)


# messages

msg = Label(window,width=14,text="LET'S BEGIN!", font=("arial", 40, 'bold'),relief='solid', bg="white", fg="#CD2990")
msg.place(x=460, y=350)
# update message
def updateMessage(x):
    if x=="ITS A TIE!!!":
        msg = Label(window, width=14, text=x, font=("arial", 40, 'bold'), relief='solid', bg="white",
                fg="black")
        msg.place(x=460, y=350)
    elif x=="YOU LOST!":
        msg = Label(window, width=14, text=x, font=("arial", 40, 'bold'), relief='solid', bg="white",
                    fg="red")
        msg.place(x=460, y=350)
    elif x=="YOU WIN!":
        msg = Label(window, width=14, text=x, font=("arial", 40, 'bold'), relief='solid', bg="white",
                    fg="green")
        msg.place(x=460, y=350)





    #msg['text'] = x



# update user score
class UpdateScore():
    def updateUserScore(self):
        self.score = int(userScore["text"])
        self.score += 1
        userScore["text"] = str(self.score)

    # update computer score

    def updateCompScore(self):
        self.score = int(computerScore["text"])
        self.score += 1
        computerScore["text"] = str(self.score)


# check winner
class CheckWinner(UpdateScore):
    def checkWin(self, user, computer):
        if user == computer:
            updateMessage("ITS A TIE!!!")
            h_list.append("It was a Tie")
        elif user == "rock":
            if computer == "paper":
                updateMessage("YOU LOST!")
                self.updateCompScore()
                h_list.append("You Lost")
            else:
                updateMessage("YOU WIN!")
                self.updateUserScore()
                h_list.append("You Won")
        elif user == "paper":
            if computer == "scissor":
                updateMessage("YOU LOST!")
                self.updateCompScore()
                h_list.append("You Lost")
            else:
                updateMessage("YOU WIN!")
                self.updateUserScore()
                h_list.append("You Won")
        elif user == "scissor":
            if computer == "rock":
                updateMessage("YOU LOST!")
                self.updateCompScore()
                h_list.append("You Lost")
            else:
                updateMessage("YOU WIN!")
                self.updateUserScore()
                h_list.append("You Won")

        else:
            pass


choices = ["rock", "paper", "scissor"]
# update choices
class UpdateChoices(CheckWinner):

    def updateChoice(self, x):

        # for computer
        compChoice = choices[randint(0, 2)]
        if compChoice == "rock":
            comp_label.configure(image=rock_img_comp)
        elif compChoice == "paper":
            comp_label.configure(image=paper_img_comp)
        else:
            comp_label.configure(image=scissor_img_comp)

        # for user
        if x == "rock":
            user_label.configure(image=rock_img)
        elif x == "paper":
            user_label.configure(image=paper_img)
        else:
            user_label.configure(image=scissor_img)

        self.checkWin(x, compChoice)


def scores():
    for i in range(len(h_list)):
        for j in range(1):
            e = Entry(window, width=20,bg='black', fg='white',font=('Arial', 16, 'bold'))
            e.grid(row=i, column=j)
            e.insert(END, h_list[i])




# buttons
class buttons(UpdateChoices):
    def __init__(self):
        rock = Button(window, width=16, height=1, text="ROCK", bg="sky blue", fg="blue",font=("arial",20,"bold"),
                      relief='solid',command=lambda: self.updateChoice("rock")).place(x=140,y=550)
        paper = Button(window, width=16, height=1, text="PAPER", bg="sky blue", fg="blue",font=("arial",20,"bold"),
                       relief='solid', command=lambda: self.updateChoice("paper")).place(x=550,y=550)
        scissor = Button(window, width=16, height=1, text="SCISSOR", bg="sky blue", fg="blue",
                         font=("arial",20,"bold"),relief='solid', command=lambda: self.updateChoice("scissor")).place(x=950,y=550)
        quitbtn=Button(window, width=16, height=1, text="QUIT", bg="#ffdb58", fg="black",
                         font=("arial",16,"bold"),relief='solid',command=scores).place(x=990,y=620)




ob= indicators()
ob1= buttons()
ob2= UpdateChoices()
window.mainloop()
