# numbers = [1,2,3,4]
#
# new_list = [n+1 for n in numbers]
# print(new_list)

# comprehension can work with any sequence like list,range,string,tuple --->

# ran = range(1, 5)
# new_list = [n*2 for n in ran]
# print(new_list)

# conditional comprehension ->
names = ["Harsh","Saumya","selena"]
new_list = [name.upper() for name in names if len(name)<8]
print(new_list)