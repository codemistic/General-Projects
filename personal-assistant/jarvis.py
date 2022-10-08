from email.mime import audio
import pyttsx3
import speech_recognition as sr
import datetime
import wikipedia
import webbrowser

 #microsoft ki  speech api key acces krny k leye
engine=pyttsx3.init('sapi5')
#window ki apni pass sy aawaz lene k leye
voices=engine.getProperty('voices')
#konsi voice chaie male /female to
engine.setProperty('voices',voices[0].id)

#what you want them to say
def speak(audio):
    engine.say(audio)
    engine.runAndWait()

def wishme():
    #datetime module k datetime dictiorny k now k hour do
    hour=int(datetime.datetime.now().hour)    
    #hour 0-24 tk honge
    if hour>=0 and hour<12:
        speak('Good morning')
    elif hour>=12 and hour<18:
        speak('Good afternoon')
    else:
        speak("Good night")   

    speak("Aslamo alikum! G Abdul samad, How may i help you?")
def takeCommand():
    
    #this will take user voice from microphone and return string output
    
    r=sr.Recognizer() #r instaneous vraibe hai or sr.Rec class
    with sr.Microphone() as source: 
        print("Listening....")  
        r.pause_threshold=1 #class varible ko change kiya ha ,#module mai hai class
        audio=r.listen(source) #source hamri awaz ha
    try:
        print("Recognizing...") 
        query=r.recognize_google(audio,language='en-in')
        print(f'User said: {query}\n') 
    except Exception as e:
        print("Say this again pls..")
        return "None"
    return query

if __name__=="__main__":
    wishme()            
    if 1:
        query=takeCommand().lower()
        #lower is leye kiya take hamri voice input ko lower kre or match krna asan ho
        #logic for executing tasks based on query
        if 'wikipedia' in query:
            speak("searching Wikipedia...")
            query=query.replace('wikipedia','')
            results=wikipedia.summary(query,sentences=2)
            speak("Acoording to wikipedia..")
            print(results)
            speak(results)
        elif 'open youtube' in query:
            webbrowser.open('youtube.com')
        elif 'open google' in query:
            webbrowser.open('google.com')
        elif 'open stackoverflow' in query:
            webbrowser.open('stackoverflow.com')    
        elif 'play music' in query:
            webbrowser.open('https://youtu.be/G0dQCVuzjSc')
        elif 'the time' in query:
            strTime=datetime.datetime.now().strftime('%H:%M:%S')
            speak(f'bhai time horha ha {strTime}')  
