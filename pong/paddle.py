from turtle import Turtle


class padel(Turtle):
    def __init__(self, pos):
        super().__init__()
        self.shape("square")
        self.penup()
        self.color("white")
        self.shapesize(5, 1)
        self.setpos(pos)

    def move_up(self):
        if self.ycor() < 250:
            new_y = self.ycor() + 20
            self.goto(self.xcor(), new_y)

    def move_down(self):
        if self.ycor() > -250:
            new_y = self.ycor() - 20
            self.goto(self.xcor(), new_y)

    def center_line(self):
        self.goto(0, 0)
        self.shapesize(40, 0.01)
