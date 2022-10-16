from tkinter import *
import tkinter.font as font

expression=""

#Function to add numbers/operands to the expression
def append(x):
    global expression
    expression+=x
    equation.set(expression)

#Function to totally clear the expression
def clear():
    global expression
    expression=""
    equation.set("")

#Function to calculate the expression when equal is clicked
def equal_clicked():
    try:
        global expression
        total=str(eval(expression))
        equation.set(total)
        expression=""
    except:
        equation.set("There was an error!")
        expression=""

#Function to delete one character from the expression
def delete():
    global expression
    x=len(expression)
    expression=expression[:(x-1)]
    equation.set(expression)
    

root=Tk()
root.title("Calculator")
root.configure(background="#5E2612")

equation=StringVar()

#Heading Label
l1=Label(root,text="CALCULATOR", font=("Helvetica 18 bold",27),anchor=CENTER,bg="#5E2612",fg="white").grid(row=0,column=2,columnspan=2)
frame=Frame(root).grid(row=1,column=1,columnspan=5)

#Entry field to type/display entered expression
display=Entry(frame,textvariable=equation,font=("times 15",16),bd=4).grid(row=2,column=1,columnspan=3,sticky="w")

#Buttons for numbers

b1=Button(root,text="1",width=16,height=4,bd=4,bg="#FFEBCD",command=lambda: append("1"))
b1.grid(row=3,column=1)

b2=Button(root,text="2",width=16,height=4,bd=4,bg="#FFEBCD",command=lambda: append("2"))
b2.grid(row=3,column=2)

b3=Button(root,text="3",width=16,height=4,bd=4,bg="#FFEBCD",command=lambda: append("3"))
b3.grid(row=3,column=3)

b4=Button(root,text="4",width=16,height=4,bd=4,bg="#FFEBCD",command=lambda: append("4"))
b4.grid(row=4,column=1)

b5=Button(root,text="5",width=16,height=4,bd=4,bg="#FFEBCD",command=lambda: append("5"))
b5.grid(row=4,column=2)

b6=Button(root,text="6",width=16,height=4,bd=4,bg="#FFEBCD",command=lambda: append("6"))
b6.grid(row=4,column=3)

b7=Button(root,text="7",width=16,height=4,bd=4,bg="#FFEBCD",command=lambda: append("7"))
b7.grid(row=5,column=1)

b8=Button(root,text="8",width=16,height=4,bd=4,bg="#FFEBCD",command=lambda: append("8"))
b8.grid(row=5,column=2)

b9=Button(root,text="9",width=16,height=4,bd=4,bg="#FFEBCD",command=lambda: append("9"))
b9.grid(row=5,column=3)

b0=Button(root,text="0",width=16,height=4,bd=4,bg="#FFEBCD",command=lambda: append("0"))
b0.grid(row=6,column=2)

#Buttons for operations

bAdd=Button(root,text="+",width=16,height=4,bd=4,bg="#FFA07A",command=lambda: append("+"))
bAdd.grid(row=3,column=4)

bSubtract=Button(root,text="-",width=16,height=4,bd=4,bg="#FFA07A",command=lambda: append("-"))
bSubtract.grid(row=4,column=4)

bMultiply=Button(root,text="x",width=16,height=4,bd=4,bg="#FFA07A",command=lambda: append("*"))
bMultiply.grid(row=5,column=4)

bDiv=Button(root,text="/",width=16,height=4,bd=4,bg="#FFA07A",command=lambda: append("/"))
bDiv.grid(row=6,column=4)

bDecimal=Button(root,text=".",width=16,height=4,bd=4,bg="#FFEBCD",command=lambda: append("."))
bDecimal.grid(row=6,column=1)

bEq=Button(root,text="=",width=16,height=4,bd=4,bg="#FFEC8B",command=lambda: equal_clicked())
bEq.grid(row=6,column=3)

bClear=Button(root,text="Clear",width=16,height=2,bd=2,bg="#FFEC8B",command=lambda: clear())
bClear.grid(row=2,column=4)

bDelete=Button(root,text="Delete",width=16,height=2,bd=2,bg="#FFEC8B",command=lambda: delete())
bDelete.grid(row=2,column=3)

root.mainloop()



