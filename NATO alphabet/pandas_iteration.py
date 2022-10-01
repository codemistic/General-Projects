import pandas

student_details = {
    "student": ['A', 'B', 'C'],
    "score": [50, 20, 80]
}

student_dataframe = pandas.DataFrame(student_details)
# print(student_dataframe)

for (key, value) in student_dataframe.iterrows():
    print(value)
    print(value.student)
    print(value.score)
