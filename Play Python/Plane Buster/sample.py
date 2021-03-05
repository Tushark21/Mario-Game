import pygame,time,sys
from pygame.locals import *
import random

pygame.init()

pygame.display.set_caption('Plane Buster')

screenInfo = pygame.display.Info()

canvasW=screenInfo.current_w
canvasH=screenInfo.current_h
#Canvas = pygame.display.set_mode((canvasW-200,canvasH),pygame.RESIZABLE)
Canvas = pygame.display.set_mode((canvasW,canvasH),pygame.FULLSCREEN)

col = (0,0,0)
Canvas.fill(col)

menuWindow=pygame.image.load("images\\menu_window.png")
menuWindowRect=menuWindow.get_rect()
menuWindowRect.centerx=canvasW//2
menuWindowRect.centery=canvasH//2

headerImage=pygame.image.load("images\\menu.png")
headerImageRect=headerImage.get_rect()
headerImageRect.centerx=canvasW//2
headerImageRect.top=menuWindowRect.top+40

startImage=pygame.image.load("images\\hover\\start_hover.png")
startImageRect=startImage.get_rect()
startImageRect.centerx=canvasW/2
startImageRect.centery=(canvasH/2)-(menuWindowRect.height)/4+headerImageRect.height-40

optionsImage=pygame.image.load("images\\normal\\options_normal.png")
optionsImageRect=optionsImage.get_rect()
optionsImageRect.centerx=canvasW/2
optionsImageRect.centery=canvasH/2+headerImageRect.height-50

quitImage=pygame.image.load("images\\normal\\quit_normal.png")
quitImageRect=quitImage.get_rect()
quitImageRect.centerx=canvasW/2
quitImageRect.centery=canvasH/2+(menuWindowRect.height)/4+headerImageRect.height-60


Canvas.blit(menuWindow,menuWindowRect)
Canvas.blit(headerImage,headerImageRect)
Canvas.blit(startImage,startImageRect)
Canvas.blit(optionsImage,optionsImageRect)
Canvas.blit(quitImage,quitImageRect)
pygame.display.update()

indexHovered=0
while True:

    for event in pygame.event.get():
        if event.type==QUIT:
            pygame.quit()
            sys.exit()
        
        if event.type == KEYUP:
            print("UP")

        if event.type == KEYDOWN:
            
            if event.key==K_ESCAPE:
                pygame.quit()
                sys.exit()

            if event.key==K_KP_ENTER or event.key==K_RETURN:
                if indexHovered==0:
                    startImage=pygame.image.load("images\\pressed\\start_pressed.png")
                    Canvas.blit(startImage,startImageRect)
                if indexHovered==1:
                    optionsImage=pygame.image.load("images\\pressed\\options_pressed.png")
                    Canvas.blit(optionsImage,optionsImageRect)
        
                if indexHovered==2:
                    quitImage=pygame.image.load("images\\pressed\\quit_pressed.png")
                    Canvas.blit(quitImage,quitImageRect)

                pygame.display.update()
                time.sleep(1)


            if event.key == K_UP:
                indexHovered-=1

            if event.key == K_DOWN:
                indexHovered+=1
            
            indexHovered=0 if indexHovered<0 else indexHovered
            indexHovered=2 if indexHovered>2 else indexHovered

        if indexHovered==0:
            optionsImage=pygame.image.load("images\\normal\\options_normal.png")
            startImage=pygame.image.load("images\\hover\\start_hover.png")
        
        if indexHovered==1:
            startImage=pygame.image.load("images\\normal\\start_normal.png")
            optionsImage=pygame.image.load("images\\hover\\options_hover.png")
            quitImage=pygame.image.load("images\\normal\\quit_normal.png")
        
        if indexHovered==2:
            optionsImage=pygame.image.load("images\\normal\\options_normal.png")
            quitImage=pygame.image.load("images\\hover\\quit_hover.png")
        
        Canvas.blit(startImage,startImageRect)
        Canvas.blit(optionsImage,optionsImageRect)
        Canvas.blit(quitImage,quitImageRect)
        pygame.display.update()