from tkinter import *

root = Tk()
root.title("calculator")
root.geometry("500x300")
root.resizable(False, False)

info = Label(root, text="Enter your weight in kg and height in meter",font=('arial', 15), fg="grey")
info.place(relwidth=1, x=0, y=0)

def fun():
    h=height_store.get()
    w=weight_store.get()
    try:
        BMI= w/(h*h)
        if BMI < 18.5:
            show.config(text="Underweight")
        elif BMI >= 30:
            show.config(text="Obesity")
        elif BMI >= 18 and BMI < 25:
            show.config(text="Normal")
        elif BMI <= 25 and BMI < 30:
            show.config(text="Overweight")
    except:
        show.config(text="Inavlid Input")



height = Label(root, text='Height', font=("Century", 18)).place(x=60, y=40, height=40,width=130)
height_store = DoubleVar()
height_entry = Entry(root, font=("arial", 18), textvariable=height_store)
height_entry.place(x=195, y=40, height=40,width=200)
height_store.set("")
height_entry.insert(0,0)

weight_store = DoubleVar()
weight = Label(root, text='Weight', font=("Century", 18)).place(x=60, y=100, height=40,width=130)
weight_entry = Entry(root, font=("arial", 18), textvariable=weight_store)
weight_entry.place(x=195, y=100, height=40, width=200)
weight_store.set("")
weight_entry.insert(0,0)

btn = Button(root, text="Submit",font=("ALGERIA", 20), cursor='hand2',command=fun).place(x=160, y=160,width=180)

show = Label(root, font=('times new roman', 30), fg="blue")
show.place(relwidth=1, x=0, y=230)

root.mainloop()
