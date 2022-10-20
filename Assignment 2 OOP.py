#!/usr/bin/env python
# coding: utf-8

# In[8]:



                                #ASSIGNMENT 2


import abc 
class CGPA(abc.ABC):
    @abc.abstractmethod
    def get_CGPA(self):
        pass
class Student_A(CGPA):
    def __init__(self,marks1,marks2,marks3):
        self.marks1=marks1
        self.marks2=marks2
        self.marks3=marks3
    def get_CGPA(self):
        print("CGPA of Student A")
        total=((self.marks1+self.marks2+self.marks3)/3)
        print("Your Total Marks :",total)
        if total==100 and total>=85:
            print("your GPA : 4 and Grade is A")
        elif total==84 and total>=70:
            print("Your GPA : 3 and Grade is B")
        elif total==69 and total>=55:
            print("Your GPA : 2 and Grade is C")
        elif total==54 and total>=40:
            print("Your GPA : 1 and Grade is D")
        elif total==39 and total>=0:
            print("No GPA .... Grade is F")
def result(GPA):
   GPA.get_CGPA()
class Student_B(CGPA):
    def __init__(self,marks1,marks2,marks3,marks4):
        self.marks1=marks1
        self.marks2=marks2
        self.marks3=marks3
        self.marks4=marks4
    def get_CGPA(self):
        print("CGPA of Student B")
        total=((self.marks1+self.marks2+self.marks3+self.marks4)/4)
        print("Your Total Marks :",total)
        if total==100 and total>=85:
            print("your GPA : 4 and Grade is A")
        elif total>84 and total>=70:
            print("Your GPA : 3 and Grade is B")
        elif total>69 and total>=55:
            print("Your GPA : 2 and Grade is C")
        elif total>54 and total>=40:
            print("Your GPA : 1 and Grade is D")
        elif total>39 and total>=0:
            print("No GPA .... Grade is F")
def result(GPA):
    GPA.get_CGPA()
ob=Student_A(84,55,68)
obj=Student_B(48,59,62,87)
result(ob)
result(obj)
    
    


# In[ ]:




