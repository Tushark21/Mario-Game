import pygame,sys,time
from pygame.locals import *
import random

pygame.init()

class FireBall:
    fireballimage = pygame.image.load("images\\fireball.png")

Canvas = pygame.display.set_mode((1200,680))
col = (0,0,0)
Canvas.fill(col)
pygame.display.set_caption('Major Project')

endimage = pygame.image.load("images\\end.png")
endrect = endimage.get_rect()

endrect.left = 330
endrect.top = 180

startimage = pygame.image.load("images\\start.png")
startrect = startimage.get_rect()

startrect.left = 330
startrect.top = 180

Canvas.blit(startimage, startrect)
pygame.display.update()

wait=True
while wait:
    
    for event in pygame.event.get():
        if event.type==QUIT:
            pygame.quit()
            sys.exit()
            
        if event.type == KEYDOWN:
            pygame.mixer.music.load('Music\\mario_theme.wav')
            pygame.mixer.music.play(-1)
            wait=False

maryoimage = pygame.image.load("images\\maryo.png")
maryorect = maryoimage.get_rect()
maryorect.left = 50

dragonimage = pygame.image.load("images\\dragon.png")
dragonrect = dragonimage.get_rect()
dragonrect.left = 1080

bricksimage = pygame.image.load("images\\cactus_bricks.png")
bricksrect = bricksimage.get_rect()
bricksrect.left = 0
bricksrect.top = -125

fireimage = pygame.image.load("images\\fire_bricks.png")
firerect = startimage.get_rect()
firerect.left = 0
firerect.top = 607

y=75
a=1.2
v=1.5
s=300
counter=0

fb = [FireBall() for count in range(5)]
fbcount=0
fbcontroller=-3
for j in range(0,5):
    fb[j].fireballrect=fb[j].fireballimage.get_rect()

pygame.display.update()

#Game Loop Starts
while True:

    Canvas.blit(bricksimage, bricksrect)
    Canvas.blit(fireimage, firerect)

    r=random.randint(1,25)
    if r==1 and fb[fbcount-1].fireballrect.left<780:
        fb[fbcount].fireballrect.top=y+30
        fb[fbcount].fireballrect.left=dragonrect.left-20
        fbcount+=1
        if fbcount>4:
            fbcount=0
            
    for j in range(0,5):
        fb[j].fireballrect.left+=fbcontroller
        Canvas.blit(fb[j].fireballimage,fb[j].fireballrect)
        
    y=y+a
    s=s+v
    counter=counter+1
    if v<0 and counter==60:
        v=1.5

    maryorect.top=s;        
    dragonrect.top=y;
    Canvas.blit(dragonimage, dragonrect)
    Canvas.blit(maryoimage, maryorect)
    time.sleep(0.001)

    for event in pygame.event.get():
        if event.type == KEYDOWN:
            if event.key == K_UP:
                v=-1.5
                counter=0

    for j in range(0,5):
        l=fb[j].fireballrect.left
        c=fb[j].fireballrect.top
        r=fb[j].fireballrect.right
        if maryorect.right>l and maryorect.left<r and maryorect.top<c and maryorect.bottom>c:
            pygame.mixer.music.load('Music\\mario_dies.wav')
            pygame.mixer.music.play(1)
            wait=True
            Canvas.blit(endimage, endrect)
            pygame.display.update()
            while wait:
               for event in pygame.event.get():
                if event.type==QUIT:
                    pygame.quit()
                    sys.exit()
            
                if event.type == KEYDOWN:
                    if event.key == K_KP_ENTER:
                        y=75
                        a=1.2
                        v=1.5
                        s=300
                        counter=0
                        fbcount=0
                        for j in range(0,5):
                            fb[j].fireballrect.top=-100
                        pygame.mixer.music.load('Music\\mario_theme.wav')
                        pygame.mixer.music.play(-1)
                        wait=False
    

    if s>560 or s<75:
        pygame.mixer.music.load('Music\\mario_dies.wav')
        pygame.mixer.music.play(1)
        wait=True
        Canvas.blit(endimage, endrect)
        pygame.display.update()
        while wait:
           for event in pygame.event.get():
            if event.type==QUIT:
                pygame.quit()
                sys.exit()
            if event.type == KEYDOWN:
                if event.key == K_KP_ENTER:
                    y=75
                    a=1.2
                    v=1.5
                    s=300
                    counter=0
                    fbcount=0
                    for j in range(0,5):
                        fb[j].fireballrect.top=-100
                    pygame.mixer.music.load('Music\\mario_theme.wav')
                    pygame.mixer.music.play(-1)
                    wait=False
    
    if y>530:
        a=-1.2
    else:
        if y<75:
            a=1.2

    if event.type==QUIT:
            pygame.quit()
            sys.exit()
            
    pygame.display.update()
    Canvas.fill(col)
