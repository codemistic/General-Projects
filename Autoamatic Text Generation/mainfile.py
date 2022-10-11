def build_dict():
  
  import string
  import requests
  
  # Corpus -> The Project Gutenberg EBook of The Art Of Writing & Speaking The English Language, by Sherwin Cody
  import_dataset=requests.get('http://www.gutenberg.org/files/19719/19719-0.txt')

  data = import_dataset.text.split('\n')
  data=" ".join(data)

  #Cleaning the text and separating each word into a list
  tokens = data.split()
  table = str.maketrans('', '', string.punctuation)
  tokens = [w.translate(table) for w in tokens]
  tokens = [word.lower() for word in tokens if word.isalpha()]

  #Length of training sequence one greater than input sequence
  length = seq_length + 1
  lines= []

  for i in range(length, len(tokens)+1):
    seq = tokens[i-length:i]
    line = ' '.join(seq)
    lines.append(line)

  import numpy as np
  from tensorflow.keras.preprocessing.text import Tokenizer

  tokenizer= Tokenizer()
  tokenizer.fit_on_texts(lines)
  sequences = tokenizer.texts_to_sequences(lines)

  token_dict=pd.DataFrame(tokenizer.word_index.values(),tokenizer.word_index.keys(),['value'])
  token_dict.to_csv('TD.csv')
  return token_dict
Building, Training and Saving the model

def built_model():
  from tensorflow.keras.utils import to_categorical
  from tensorflow.keras.models import Sequential
  from tensorflow.keras.layers import Dense, LSTM, Embedding
  
  #Preparaton of dataset for training
  sequences = np.array(sequences)
  X, y = sequences[:, :-1], sequences[:,-1]
  vocab_size = len(tokenizer.word_index)+1
  y = to_categorical(y, num_classes=vocab_size)

  #Building the model
  model = Sequential()
  model.add(Embedding(vocab_size, 50, input_length=seq_length))
  model.add(LSTM(100, return_sequences = True))
  model.add(LSTM(100))
  model.add(Dense(100, activation='relu'))
  model.add(Dense(vocab_size, activation='softmax')) 
  model.compile(loss = 'categorical_crossentropy', optimizer = 'adam', metrics = 'accuracy')

  #Training and Saving the model
  model.fit(X, y, batch_size=256, epochs=200)
  model.save('ATG.h5')
  return model
Getting Token Dictionary and Model Ready

import pandas as pd
from tensorflow.keras.models import load_model
from tensorflow.keras.preprocessing.sequence import pad_sequences

#Length of input sequence
seq_length = 3

try:
  model = load_model('ATG.h5')
except OSError:
  token_dict = build_dict()
  model = built_model()

try:
  token_dict = pd.read_csv('TD.csv')
except FileNotFoundError:
  token_dict = build_dict()
Prediction Function

def prediction(input_text):
  predicted_word = []
  encoded = [token_dict.value[w.lower()] for w in seed_text.split() if w.isalpha()]
  encoded = pad_sequences([encoded], maxlen = input_length)
  y_predict=model.predict(encoded)[0]
  for _ in range(5):
    if y_predict.max()<0.08:
      break
    y_maxp=y_predict.argmax()
    predicted_word.append(token_dict.index[y_maxp-1])
    y_predict[y_maxp]=0
  return predicted_word
Running the program with GUI

def start():

  root=Tk()
  root.geometry('830x500')
  root.config(bg='grey')
  def close(e):
      root.destroy()
  Label(root,text=' '*10,font='Candara 45 bold',bg='grey').grid(row=0)
  Label(root,text=' '*10+'Project :',font='Candara 20 bold',bg='grey').grid(row=3,column=0,stick='w')
  Label(root,text=' '*10+'Automatic Text Generation',font='Candara 20 bold',bg='grey').grid(row=4,column=0,stick='e')
  Label(root,text=' '*10+'Developed By :',font='Candara 18 bold',fg='blue',bg='grey').grid(row=5,column=1,stick='sw')
  Label(root,text='Vaibhav Jain (181B232)',font='Candara 17 italic',fg='blue',bg='grey').grid(row=6,column=1,stick='e')
  Label(root,text='Vibhum Tripathi (181B237)',font='Candara 17 italic',fg='blue',bg='grey').grid(row=7,column=1,stick='e')
  Label(root,text='Mohit Sharma (181B129)',font='Candara 17 italic',fg='blue',bg='grey').grid(row=8,column=1,stick='e')
  Label(root,text=' '*10+'----'*16,font='Candara 17',fg='blue',bg='grey').grid(row=9,column=1)
  Label(root,text=' '*10+'Project Guide :',font='Candara 18 bold',fg='blue',bg='grey').grid(row=10,column=1,stick='w')
  Label(root,text='Dr. Ajay Kumar',font='Candara 17 italic',fg='blue',bg='grey').grid(row=11,column=1,stick='e')

  root.bind('<Motion>',close)
  root.mainloop()
def run_GUI():
  
  root=Tk()                                     
  root.geometry('900x300')                       
  root.config(bg='royal blue')
  root.title('Automatic Text Generation: Test-box')
  l1=Label(root,text='Automatic Text Generation: Test-box',font='Candara 18 bold',bg='royal blue')
  l1.pack()

  present = False                             # Check variable for listbox
  lb=Listbox()                                   

  def put(event):                             # Function to put selected word from...
      global input_box                        # predicted words list into entry bar
      cs = lb.curselection()
      input_box.insert(END,lb.get(cs))
      input_box.insert(END,' ')
      lb.destroy()
      output()

  def listing(predicted):                    # Function to print list of predicted words
      global present
      global lb
      present = True
      lb = Listbox(root,font='Candara 15',width=15,height=len(predicted))
      lb.bind('<Double-1>', put)
      lb.pack()
      for word in predicted:
          lb.insert(END,word)
      
  def output():                                  
      global input_box
      input_text=str(input_box.get())             
      predicted=prediction(input_text)     
      if len(predicted) > 0 :
          listing(predicted)                     

  def keypress(e):
      global present
      global lb
      input_box.insert(END,str(e.char))
      if e.char == ' ' and present == False :          # Prediction function called after <space>
          output()
      elif e.char == ' ' and present == True :
          None
      elif present == True :
          present = False
          lb.destroy()
          
  input_box=Entry(root,width=75,font='Candara 15')
  input_box.pack()
  root.bind("<KeyPress>", keypress)

  root.mainloop()
from tkinter import *
start()
run_GUI()
