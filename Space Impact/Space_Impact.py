import pygame
import math
import random
from pygame import mixer

pygame.init()

# Create a Screen
screen=pygame.display.set_mode((800,600))

# Background
background=pygame.image.load('assets/back.jpg')

# Background Sound
mixer.music.load('assets/background.wav')
mixer.music.play(-1)

# Title 
pygame.display.set_caption("Space Impact")

# Player
playerImg=pygame.image.load('assets/rocket.png')
playerX,playerY=370,480
playerX_change=0

# Enemies
enemyImg=[]
enemyX=[]
enemyY=[]
enemyX_change=[]
enemyY_change=[]
no_of_enemies=6

for i in range(no_of_enemies):
	enemyImg.append(pygame.image.load('assets/enemy.png'))
	enemyX.append(random.randint(0,735))
	enemyY.append(random.randint(50,150))
	enemyX_change.append(1.5)
	enemyY_change.append(40)

# Bullet
bulletImg=pygame.image.load('assets/bullet.png')
bulletX,bulletY=0,480
bulletX_change=0
bulletY_change=5
bullet_state="ready" # Ready- Not appearing  .....  Fire- Moving 

# Score
score_val=0
font=pygame.font.Font('freesansbold.ttf',32)
textX=10
textY=10


# Game Over Text
over_font=pygame.font.Font('freesansbold.ttf',64)

def show_score(x,y):
	score=font.render("Score :"+ str(score_val),True,(255,255,255))
	screen.blit(score,(x,y))

def game_over_text():
	over_text=over_font.render("GAME OVER",True,(255,255,255))
	screen.blit(over_text,(200,250))

def player(x,y):
	screen.blit(playerImg,(x,y))

def enemy(x,y,i):
	screen.blit(enemyImg[i],(x,y))

def fire_bullet(x,y):
	global bullet_state
	bullet_state="fire"
	screen.blit(bulletImg,(x+16,y+10))

def isCollision(enemyX,enemyY,bulletX,bulletY):
	distance=math.sqrt((enemyX-bulletX)**2 + (enemyY-bulletY)**2)
	if distance<27:
		return True
	else:
		return False

# Game Loop
running=True
while running:

	screen.fill((0,0,0))
	screen.blit(background,(0,0))


	for event in pygame.event.get():
		if event.type==pygame.QUIT:
			running=False

		# Keystroke Event
		if event.type==pygame.KEYDOWN:
			if event.key==pygame.K_LEFT:
				playerX_change=-3
			if event.key==pygame.K_RIGHT:
				playerX_change=3
			if event.key==pygame.K_SPACE:
				if bullet_state is "ready":
					bullet_sound=mixer.Sound('assets/laser.wav')
					bullet_sound.play()
					bulletX=playerX
					fire_bullet(bulletX,bulletY)

		if event.type==pygame.KEYUP:
			if event.key==pygame.K_LEFT or event.key==pygame.K_RIGHT:
				playerX_change=0

	
	# Boundary Condition Checking for Player
	playerX+=playerX_change
	if playerX<=0: playerX=0
	elif playerX>=736: playerX=736

	# Enemy Movement
	for i in range(no_of_enemies):

		# Game Over
		if enemyY[i]>440:
			for j in range(no_of_enemies):
				enemyY[j]=2000
			game_over_text()
			break

		enemyX[i]+=enemyX_change[i]
		if enemyX[i]<=0:
			enemyX_change[i]=1.5
			enemyY[i]+=enemyY_change[i]

		elif enemyX[i]>=736:
			enemyX_change[i]=-1.5
			enemyY[i]+=enemyY_change[i]

	# Collision
		collision=isCollision(enemyX[i],enemyY[i],bulletX,bulletY)
		if collision:
			explosion_sound=mixer.Sound('assets/explosion.wav')
			explosion_sound.play()
			bulletY=480
			bullet_state="ready"
			score_val+=1
			enemyX[i],enemyY[i]=random.randint(0,735),random.randint(50,150)

		enemy(enemyX[i],enemyY[i],i)



	# Bullet Movement
	if bulletY<=0:
		bulletY=480
		bullet_state="ready"

	if bullet_state is "fire":
		fire_bullet(bulletX,bulletY)
		bulletY-=bulletY_change

	

	player(playerX,playerY)
	show_score(textX,textY)

	pygame.display.update()