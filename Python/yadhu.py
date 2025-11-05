import turtle
import time

# ========================
# Setup Screen
# ========================
screen = turtle.Screen()
screen.bgcolor("navyblue")
screen.title("Anu Shoots Yadhu - Slow Motion")
screen.tracer(0)  # For manual control of updates

# ========================
# Helper: Draw Emoji Face
# ========================
def draw_face(x, y, face_color, eye_color, mouth_func, name=""):
    t = turtle.Turtle()
    t.speed(0)
    t.hideturtle()
    t.penup()
    t.goto(x, y)
    t.pendown()

    # Face
    t.fillcolor(face_color)
    t.begin_fill()
    t.circle(40)
    t.end_fill()

    # Eyes
    t.penup()
    t.goto(x - 15, y + 15)
    t.pendown()
    t.fillcolor(eye_color)
    t.begin_fill()
    t.circle(6)
    t.end_fill()

    t.penup()
    t.goto(x + 15, y + 15)
    t.pendown()
    t.begin_fill()
    t.circle(6)
    t.end_fill()

    # Mouth
    t.penup()
    mouth_func(t, x, y)

    # Name label
    t.penup()
    t.goto(x, y - 60)
    t.color("white")
    t.write(name, align="center", font=("Arial", 12, "bold"))

    return t  # return for later modification

# Mouth functions
def sad_mouth(t, cx, cy):
    t.goto(cx - 20, cy - 10)
    t.setheading(-60)
    t.pendown()
    t.pencolor("black")
    t.circle(20, 120)

def happy_mouth(t, cx, cy):
    t.goto(cx - 20, cy - 15)
    t.setheading(60)
    t.pendown()
    t.pencolor("black")
    t.circle(20, -120)

# ========================
# 1. Draw Text Circle (Top to Bottom)
# ========================
text_turtle = turtle.Turtle()
text_turtle.speed(0)
text_turtle.color("yellow")
text_turtle.hideturtle()
text_turtle.penup()

radius = 130
center_x, center_y = 0, -30
steps = 36
angle_step = 360 / steps

# Start at TOP
text_turtle.goto(center_x, center_y + radius)
text_turtle.setheading(90)

for i in range(steps):
    text_turtle.write("Yadhu is sad", align="center", font=("Arial", 14, "bold"))
    text_turtle.penup()
    text_turtle.forward(radius)
    text_turtle.pendown()
    text_turtle.left(angle_step)
    text_turtle.penup()
    text_turtle.backward(radius)
    text_turtle.pendown()

# ========================
# 2. Draw Faces
# ========================
anu_face = draw_face(-180, -30, "lightpink", "black", happy_mouth, "Anu")
yadhu_face = draw_face(180, -30, "lightyellow", "black", sad_mouth, "Yadhu")
center_sad = draw_face(0, -30, "lightyellow", "black", sad_mouth, "")

screen.update()
time.sleep(1)

# ========================
# 3. Anu Laughs (Blink + Shake)
# ========================
laugh_turtle = turtle.Turtle()
laugh_turtle.hideturtle()
laugh_turtle.penup()
laugh_turtle.goto(-180, 20)
laugh_turtle.color("white")

for _ in range(4):
    laugh_turtle.clear()
    laugh_turtle.write("HAHAHA!", align="center", font=("Arial", 16, "bold"))
    screen.update()
    time.sleep(0.4)
    laugh_turtle.clear()
    screen.update()
    time.sleep(0.2)

# ========================
# 4. SLOW MOTION SHOOTING
# ========================
arrow = turtle.Turtle()
arrow.hideturtle()
arrow.color("red")
arrow.pensize(5)
arrow.penup()
arrow.goto(-140, -30)  # Start near Anu
arrow.pendown()

# Draw arrowhead at the tip
def draw_arrowhead(x, y, heading):
    ah = turtle.Turtle()
    ah.hideturtle()
    ah.speed(0)
    ah.penup()
    ah.goto(x, y)
    ah.setheading(heading)
    ah.pendown()
    ah.color("red")
    ah.begin_fill()
    for _ in range(3):
        ah.forward(20)
        ah.right(120)
    ah.end_fill()
    return ah

# Move arrow slowly from Anu to Yadhu
steps_shoot = 60
start_x, end_x = -140, 140
for i in range(steps_shoot):
    progress = i / steps_shoot
    current_x = -140 + progress * (end_x - (-140))
    arrow.clear()
    arrow.penup()
    arrow.goto(-140, -30)
    arrow.pendown()
    arrow.goto(current_x, -30)
    
    # Draw arrowhead at tip
    arrow_head = draw_arrowhead(current_x, -30, 0)
    
    screen.update()
    time.sleep(0.05)  # SLOW MOTION

    arrow_head.clear()

# ========================
# 5. Yadhu Gets Hit! (Flash Red)
# ========================
yadhu_face.clear()
draw_face(180, -30, "red", "black", sad_mouth, "Yadhu")
screen.update()
time.sleep(0.5)

# Back to sad
yadhu_face.clear()
draw_face(180, -30, "lightyellow", "black", sad_mouth, "Yadhu")
screen.update()

# Final message
final = turtle.Turtle()
final.hideturtle()
final.color("yellow")
final.penup()
final.goto(0, -180)
final.write("Anu shot Yadhu in slow motion!", align="center", font=("Arial", 16, "bold italic"))
screen.update()

# Keep window open
turtle.done()