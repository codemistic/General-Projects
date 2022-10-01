from turtle import Turtle


class score(Turtle):
    def __init__(self):
        super().__init__()
        self.penup()
        self.color("white")
        self.hideturtle()
        self.l_score = 0
        self.r_score = 0
        self.update_score()

    def update_score(self):
        self.clear()
        self.goto(-100, 200)
        self.write(self.l_score,align="center",font=("Courier",50,"normal"))
        self.goto(100, 200)
        self.write(self.r_score,align="center",font=("Courier",50,"normal"))

    def l_score_increase(self):
        self.l_score += 1
        self.update_score()

    def r_score_increase(self):
        self.r_score += 1
        self.update_score()
