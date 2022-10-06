from tkinter import *
import math

# ---------------------------- CONSTANTS ------------------------------- #
PINK = "#e2979c"
RED = "#e7305b"
GREEN = "#9bdeac"
YELLOW = "#f7f5dd"
FONT_NAME = "Courier"
WORK_MIN = 25
SHORT_BREAK_MIN = 5
LONG_BREAK_MIN = 20
reps = 0
timer = None
marks = ""
# ---------------------------- TIMER RESET ------------------------------- #

# ---------------------------- TIMER MECHANISM ------------------------------- # 

def start_timer():
    global reps
    reps += 1

    work_sec = WORK_MIN * 60
    short_break_sec = SHORT_BREAK_MIN * 60
    long_break_sec = LONG_BREAK_MIN * 60

    if reps % 8 == 0:
        countdown_fun(long_break_sec)
        timer_label.config(text="LONG BREAK", fg=GREEN)
    elif reps % 2 == 0:
        countdown_fun(short_break_sec)
        timer_label.config(text="SHORT BREAK", fg=YELLOW)
    else:
        countdown_fun(work_sec)
        timer_label.config(text="WORK TIME", fg=RED)

def reset_button():
    window.after_cancel(timer)
    canvas.itemconfig(timer_txt,text="00:00")
    timer_label.config(text="TIMER",fg=GREEN )
    marks=""

# ---------------------------- COUNTDOWN MECHANISM ------------------------------- #

def countdown_fun(count):
    countdown_min = math.floor(count / 60)
    countdown_sec = count % 60
    if countdown_sec < 10:
        countdown_sec = f"0{countdown_sec}"
    canvas.itemconfig(timer_txt, text=f"{countdown_min}:{countdown_sec}")
    if count > 0:
        global timer
        timer = window.after(1000, countdown_fun, count - 1)
    else:
        start_timer()
        global marks
        work_sessions = math.floor(reps/2)
        for _ in range(work_sessions):
            marks += "✔"
        tick.config(text= marks )

# ---------------------------- UI SETUP ------------------------------- #
window = Tk()
window.title("Pomodoro")
window.config(padx=100, pady=58, bg=YELLOW)

canvas = Canvas(width=282, height=282, bg=YELLOW, highlightthickness=0)
clock = PhotoImage(file="tomato.png")
canvas.create_image(103, 112, image=clock)
timer_txt = canvas.create_text(103, 130, text="00:00", fill="white", font=(FONT_NAME, 35, "bold"))
canvas.grid(column=2, row=2)

timer_label = Label(text="Timer", font=(FONT_NAME, 40, "bold"), fg=GREEN, highlightthickness=0, bg=YELLOW)
timer_label.grid(column=2, row=1)

tick = Label( fg=GREEN, font=(FONT_NAME, 15, "bold"))
tick.grid(column=2, row=4)

start = Button(text="Start", command=start_timer)
start.grid(column=1, row=3)
Reset = Button(text="Reset", command=reset_button)
Reset.grid(column=3, row=3)

window.mainloop()
