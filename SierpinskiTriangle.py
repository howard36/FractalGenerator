import turtle
import math
import random

random.seed()

t = turtle.Turtle()
screen = turtle.Screen()

current = [0.0, 0.0, 0.0, 0.0, 0.0]

t.penup()
# t.hideturtle()
# screen.bgcolor("black")

s = 500.0
yshift = -100

points = [[0.0, 1.0*s+yshift, 0.0, 1.0, 0.0],
          [-math.sqrt(3)/2*s, -0.5*s+yshift, 1.0, 0.0, 0.0],
          [math.sqrt(3)/2*s, -0.5*s+yshift, 0.0, 0.0, 1.0]]

moves = 0
while (True):
    moves += 1
    i = random.randint(0, 2)
    for j in range(5):
        current[j] = (current[j] + points[i][j])/2
    t.setpos(current[0], current[1])
    t.pencolor((current[2], current[3], current[4]))
    # if moves > 1000:
    t.dot(5)
    if moves % 100 == 0:
        print(moves)

turtle.done()
