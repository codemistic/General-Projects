import pygame 
import numpy as np
pygame.init()
clock = pygame.time.Clock()
screen = pygame.display.set_mode((377, 377))
grid = np.zeros((15, 15), dtype="int8")
grid[7][2:6] = 2
apple_pos = [7, 11]
grid[apple_pos[0]][apple_pos[1]] = 5
snake = [[7, 2], [7, 5]]
d = [2, 2]
direction_list = []
keys = [pygame.K_UP, pygame.K_RIGHT, pygame.K_DOWN, pygame.K_LEFT]
colors = [(0, 150, 150), (0, 255, 0), (255, 0, 0)]
frames = 0
moving = False
while True:
    frames += 1
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            quit()
        if event.type == pygame.KEYDOWN:
            for i in range(len(keys)):
                if event.key == keys[i]:
                    moving = True
                    direction_list.append(i+1)
    if moving and frames >= 10:
        frames = 0
        if direction_list:
            d[1] = direction_list[0]
            direction_list.pop(0)
        d[0] = grid[snake[0][0]][snake[0][1]]
        last_pos = [snake[0][:], snake[1][:]]
        for i in range(2):
            snake[i][round((d[i] % 2-1)*-1)] += round(5/24*d[i]**4 - 25/12*d[i]**3 + 151/24*d[i]**2 - 65/12*d[i])
            grid[last_pos[i][0]][last_pos[i][1]] = d[i] * i
            if i:
                for n in range(2):
                    if snake[i][n] < 0 or snake[i][n] > 14:
                        quit()
                if 5 > grid[snake[i][0]][snake[i][1]] > 0:
                    quit()
                if snake[i] == apple_pos:
                    grid[last_pos[0][0]][last_pos[0][1]] = d[0]
                    snake[0] = last_pos[0]
                    while grid[apple_pos[0]][apple_pos[1]] != 0:
                        apple_pos = [np.random.randint(0, 14), np.random.randint(0, 14)]
                    grid[apple_pos[0]][apple_pos[1]] = 5
                grid[snake[i][0]][snake[i][1]] = d[1]
    for row in range(len(grid)):
        for pos in range(len(grid[row])):
            pygame.draw.rect(screen, colors[round((np.log(grid[row][pos]+1))-0.15)], (25*pos+2, 25*row+2, 23, 23))
    clock.tick(60)
    pygame.display.update()
