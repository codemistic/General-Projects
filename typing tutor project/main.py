#import the pygame modules into the "pygame" namespace
import pygame
#copies all names in pygame.locals into current namespace
from pygame.locals import *
import sys
import time
import random

class Game:
   
    def __init__(self):
	#define constants for screen and the game
        self.w=850
        self.h=600
	self.reset = True
        self.active = False
        self.input_text=''
        self.word = ''
	#define constants for result 
        self.starts_time = 0
        self.total_time = 0
        self.accuracy = '0%'
        self.wpm = 0
	self.results = 'Time:0 Accuracy:0 % Wpm:0 '
        self.end = False
	#define color codes
        self.TITLE_T = (205,205,0)
        self.TEXT_T = (240,240,240)
        self.RESULT_T = (227,207,87)
        
        #initialize pygame
        pygame.init()

	#creating initial screen
        self.open_img = pygame.image.load('display1.png')
        self.open_img = pygame.transform.scale(self.open_img, (self.w,self.h))

	#creating background 
        self.bg = pygame.image.load('typing_bg.png')
        self.bg = pygame.transform.scale(self.bg, (850,850))
	
	#Creating display surface object
        self.screen = pygame.display.set_mode((self.w,self.h))
        pygame.display.set_caption('Typing Tutor')
       
        
    def display_text(self, screen, msg, y ,fsize, color):
        font = pygame.font.SysFont("ariali", fsize)
	#create text surface object
        text = font.render(msg, 1,color)
	#create rectangular object for text surface object
        text_rect = text.get_rect(center=(self.w/2, y))
	#text_rect.topleft = (20,20)
	#cursor = text(text_rect.topright, (3,text_rect.height))
        screen.blit(text, text_rect)

	#draws the surface object to the screen
        pygame.display.update()   
     
    #define function to get random word or sentence from the file   
    def get_sentence(self):
        f = open('sent.txt').read()
        sentences = f.split('\n')
        sentence = random.choice(sentences)
        return sentence

    #define function to show results of the game
    def show_results(self, screen):
        if(not self.end):
            #Calculate time
            self.total_time = time.time() - self.starts_time
               
            #Calculate accuracy
	    count = 0
            for i,c in enumerate(self.word):
                try:
                    if self.input_text[i] == c:
                        count += 1
                except:		
		    
                    pass
           
            self.accuracy = count*100/len(self.word)
           
            #Calculate words per minute
            self.wpm = len(self.input_text)*60/(5*self.total_time)
            self.end = True
            print(self.total_time)
                
            self.results = 'Time:'+str(round(self.total_time)) +" secs   Accuracy:"+ str(round(self.accuracy)) + "%" + '   Wpm: ' + str(round(self.wpm))

            #draw icon image for restart
            self.time_img = pygame.image.load('restart1.png')
            self.time_img = pygame.transform.scale(self.time_img, (200,150))
            #screen.blit(self.time_img, (80,320))
            screen.blit(self.time_img, (self.w/2-75, self.h-140))
            self.display_text(screen,"     Restart", self.h - 10, 30, (255,255,255))
            
            print(self.results)
            pygame.display.update()
    
    #define function to run the game
    def run(self):
        self.restart_game()
    
        #variable to keep the loop running
        self.running=True
	#main loop
        while(self.running):
	    #Setup the clock for a decent framerate
            clock = pygame.time.Clock()
            self.screen.fill((0,0,0), (50,250,750,150))
            pygame.draw.rect(self.screen,self.TITLE_T, (50,250,750,150), 2)

            # update the text of user input
            self.display_text(self.screen, self.input_text, 274, 29,(250,250,250))
            pygame.display.update()

	    #looking at every event in the queue
            for event in pygame.event.get():
		#check for quit event
                if event.type == QUIT:
                    self.running = False
                    sys.exit()
                elif event.type == pygame.MOUSEBUTTONUP:
                    x,y = pygame.mouse.get_pos()

                    # position of input box
                    if(x>=50 and x<=850 and y>=250 and y<=600):
                        self.active = True
                        self.input_text = ''
                        self.starts_time = time.time()
 
                     # position of restart box
                    if(x>=310 and x<=710 and y>=390 and self.end):
                        self.restart_game()
                        x,y = pygame.mouse.get_pos()
         
                        
                elif event.type == pygame.KEYDOWN:
                    if self.active and not self.end:
                        if event.key == pygame.K_RETURN:
                            print(self.input_text)
                            self.show_results(self.screen)
                            print(self.results)
                            self.display_text(self.screen, self.results,450, 32, self.RESULT_T)  
                            self.end = True
                        #Backspacing text    
                        elif event.key == pygame.K_BACKSPACE:
                            self.input_text = self.input_text[:-1]
                        else:
                            try:
                                self.input_text += event.unicode
                            except:
                                pass
         

	    #draws the surface object to the screen
	    pygame.display.update()

        #ensure a program maintains a rate of 60 fps        
        clock.tick(60)
    
    #define function to restart the game
    def restart_game(self):
        self.screen.blit(self.open_img, (0,0))

        pygame.display.update()
        time.sleep(5)
        
        self.reset=False
        self.end = False

        self.input_text=''
        self.word = ''
        self.starts_time = 0
        self.total_time = 0
        self.wpm = 0

        # Get random sentence 
        self.word = self.get_sentence()
        if (not self.word): self.restart_game()

        #drawing heading
        self.screen.fill((0,0,0))
        self.screen.blit(self.bg,(0,0))
        msg = "Welcome to Typing Tutor!"
        self.display_text(self.screen, msg,80, 80,self.TITLE_T)  

        # draw the rectangle for input box
        pygame.draw.rect(self.screen,(255,192,25), (50,250,750,150), 4)

        # draw the sentence string
        self.display_text(self.screen, self.word,200, 28,self.TEXT_T)
        
        pygame.display.update()



Game().run()
