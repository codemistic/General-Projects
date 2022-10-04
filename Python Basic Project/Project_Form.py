#Project Student Admission Form
print("\t\t\t**** Student Admission Form ****")
print("\t\t\tPlease Enter the Following Details..")
roll_no = int(input("\t\t\tEnter Roll No: "))
name = input("\t\t\tEnter Your Name:")
add =  input("\t\t\tEnter Address:")
dept = input("\t\t\tEnter Department:")
mob = int(input("\t\t\tEnter Mobile No:"))
email = input("\t\t\tEnter Email-ID:")
city = input("\t\t\tEnter City: ")
state = input("\t\t\tEnter State:")
age  = int(input("\t\t\tEnter Age:"))



#if(mob > 10):
 #   raise Exception("Please Enter A Valid Mobile No")
#elif(age > 20):
 #   raise Exception("Age Should Be greater than 20")
    
print("\n\n\t\t\tStudent Details Are As Folllows....")
print("\t\t\tStudent Roll No: " + str(roll_no) )
print("\t\t\tStudent Name: " + name)
print("\t\t\tStudent Address: "+ add)
print("\t\t\tStudent Department:"+ dept)
print("\t\t\tStudent Mobile no: " + str(mob) )
print("\t\t\tStudent Email-ID: "+ email)
print("\t\t\tCity: " + city)
print("\t\t\tState: " + state)
print("\t\t\tAge: "+ str(age) )
