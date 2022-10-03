# Python Calculator
# Created by Amey Karan


import math

print("Welcome to Python Calculator!")
print("What do you want to do today?")
print("1. Addition")
print("2. Subtraction")
print("3. Multiplication")
print("4. Division")
print("5. Highest Common Factor (HCF)")
print("6. Least Common Multiple (LCM)")

while True:
    choice = input("Enter your choice: ")
    if choice in ["1", "2", "3", "4", "5", "6"]:
        break
    else:
        print("Please select a valid choice")

print()
while True:
    num1 = input("Enter the first number: ")
    try:
        num1 = int(num1)
        break
    except:
        print("Enter a valid number!")

while True:
    num2 = input("Enter the second number: ")
    try:
        num2 = int(num2)
        break
    except:
        print("Enter a valid number!")


print()

choice = int(choice)
if choice == 1:
    print(f"{num1} + {num2} = {num1 + num2}")

elif choice == 2:
    print(f"{num1} - {num2} = {num1 + num2}")

elif choice == 3:
    print(f"{num1} * {num2} = {num1 + num2}")

elif choice == 4:
    print(f"{num1} ÷ {num2} = {num1 + num2}")
    print(f"Quotient: {num1 // num2}")
    print(f"Remainder: {num1 % num2}")

elif choice == 5:
    print(f"HCF({num1}, {num2}) = {math.gcd(num1, num2)}")

elif choice == 6:
    print(f"LCM({num1}, {num2}) = {math.lcm(num1, num2)}")

print("Thank you for choosing me. Hope to see you soon!")
