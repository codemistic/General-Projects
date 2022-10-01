import random

student = ["harsh", "kanodiya", "saumya"]

new_dict = {new_key: random.randint(1, 100) for new_key in student}
# print(new_dict)

passed_students = {student: score for (student, score) in new_dict.items() if score >= 60}
print(passed_students)

# <------------------------------- creating dictionary from the list --->
sentence = "What is the Airspeed Velocity of an Unladen Swallow?"

new_dict = {data: len(data) for data in sentence.split()}
print(new_dict)

# <------------- end  ---------------->

# <----------------- creating dictionary from a existing dictionary ---------------->
weather_c = {
    "Monday": 12,
    "Tuesday": 14,
    "Wednesday": 15,
    "Thursday": 14,
    "Friday": 21,
    "Saturday": 22,
    "Sunday": 24,
}
weather_f = {day: ((temp * 1.8) + 32) for (day, temp) in weather_c.items()}

print(weather_f)

# <------------------------- end ---------------------->
