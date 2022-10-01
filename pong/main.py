import turtle
import random
from paddle import padel
from ball import ball
from scoreboard import score
import time


screen = turtle.Screen()

screen.setup(800, 600)
screen.bgcolor("black")
screen.title("Pong")
screen.tracer(0)

rpadel = padel((350, 0))
lpadel = padel((-350, 0))
center = padel((0,0))
center.center_line()

ball = ball()
score = score()

screen.listen()
screen.onkey(key="Up", fun=rpadel.move_up)
screen.onkey(key="Down", fun=rpadel.move_down)

screen.onkey(key="w", fun=lpadel.move_up)
screen.onkey(key="s", fun=lpadel.move_down)

# we turned off the animations while the paddle is being created and with below line of code we updated the animation
# -->
game_is_on = True
while game_is_on:
    # this time.sleep
    time.sleep(ball.move_speed)
    screen.update()
    ball.move()

    #     checking for the collision of ball with wall's -->
    if ball.ycor() > 270 or ball.ycor() < -270:
        ball.bounce_y()

    #     checking for the collision of the paddle with the ball ->
    if ball.distance(rpadel)<50 and ball.xcor() > 320 or ball.distance(lpadel)<50 and ball.xcor() < -320:
        ball.bounce_x()

    # check if the paddle missed the ball ->
    if ball.xcor() > 380:
        ball.reset_ball()
        score.l_score_increase()

    if ball.xcor() < -380:
        ball.reset_ball()
        score.r_score_increase()

screen.exitonclick()
