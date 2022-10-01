from turtle import Turtle


class ball(Turtle):
    def __init__(self):
        super().__init__()
        self.move_speed = 0.1
        self.penup()
        self.color("white")
        self.shape("circle")
        self.goto(0, 0)
        self.x_move = 10
        self.y_move = 10

    def move(self):
        new_x = self.xcor() + self.x_move
        new_y = self.ycor() + self.y_move
        self.goto(new_x, new_y)

    # if the ball is increasing then it will decrease after bounce and vice-versa that's why we multiplied it with -1 ->
    def bounce_y(self):
        """this function of ball class is responsible for bouncing back of the ball once it collide with the upper or
        lower wall """
        self.y_move *= -1

    def bounce_x(self):
        """this function of ball class is responsible for bouncing back of the ball once it collide with the right or
        left paddle """
        self.x_move *= -1
        self.move_speed*=0.8

    def reset_ball(self):
        """this method is reponsible for reseting the ball once any of the paddle misses the ball"""
        self.goto(0,0)
        self.bounce_x()
        self.move_speed=0.1