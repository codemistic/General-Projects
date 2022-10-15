#For sample input, I have selected sample.txt

text = open("sample.txt", "r")
  
d = dict()
l=[]
print("Enter the word you want to search: ",end='')
searchWord=input()
for line in text:
    line = line.strip()
    count=0
  
    words = line.split(" ")
                         
    count=0  

    for word in words:
        if word==searchWord:
            l.append(word)


print(len(l))
