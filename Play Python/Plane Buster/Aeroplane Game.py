import pygame,time,sys
from pygame.locals import *
import random

pygame.init()

pygame.display.set_caption('Plane Buster')

screenInfo = pygame.display.Info()

canvasW=screenInfo.current_w
canvasH=screenInfo.current_h
#Canvas = pygame.display.set_mode((canvasW,canvasH),pygame.RESIZABLE)
Canvas = pygame.display.set_mode((canvasW,canvasH),pygame.FULLSCREEN)

col = (0,0,0)
Canvas.fill(col)

###Menu Objects
menuWindow=pygame.image.load("images\\menu_window.png")
menuWindowRect=menuWindow.get_rect()

headerImage=pygame.image.load("images\\menu.png")
headerImageRect=headerImage.get_rect()

arrowImage=pygame.image.load("images\\arrow.png")
arrowImageRect=arrowImage.get_rect()

#transparentImage = pygame.Surface((int(arrowImageRect.width),int(arrowImageRect.height)))
#transparentImage.set_alpha(0)

startImage=pygame.image.load("images\\hover\\start_hover.png")
startImageRect=startImage.get_rect()

optionsImage=pygame.image.load("images\\normal\\options_normal.png")
optionsImageRect=optionsImage.get_rect()

quitImage=pygame.image.load("images\\normal\\quit_normal.png")
quitImageRect=quitImage.get_rect()

padding=10
menuWindowRect.centerx=canvasW//2
menuWindowRect.centery=canvasH//2

headerImageRect.centerx=canvasW//2-padding
headerImageRect.top=menuWindowRect.top+40

startImageRect.centerx=canvasW/2-padding
startImageRect.centery=(canvasH/2)-(menuWindowRect.height)/4+headerImageRect.height-40

optionsImageRect.centerx=canvasW/2-padding
optionsImageRect.centery=canvasH/2+headerImageRect.height-50

quitImageRect.centerx=canvasW/2-padding
quitImageRect.centery=canvasH/2+(menuWindowRect.height)/4+headerImageRect.height-60

arrowImageRect.left=startImageRect.right
arrowImageRect.centery=startImageRect.centery

###Game Objects
#Bullets Class
class Bullets:
    #Bullet
    bulletImage = pygame.image.load("images\\bullet1.png")
    #bulletRect = bulletImage.get_rect()
    smokeImage=pygame.image.load("images\\smoke.png")
    bulletShoot=False

#BackGround
backGroundImage = pygame.image.load("images\\BG.png")
backGroundRect = backGroundImage.get_rect()
backGroundRect.left = -50
backGroundRect.bottom = canvasH+100

#Aeroplane
aeroplaneImage = pygame.image.load("images\\fly1.png")
aeroplaneRect = aeroplaneImage.get_rect()

bullets=[Bullets() for i in range(20)]

for j in range(0,20):
    bullets[j].bulletRect=bullets[j].bulletImage.get_rect()

for j in range(0,20):
    bullets[j].smokeRect=bullets[j].smokeImage.get_rect()

#Enemy Ship
enemyShipImage = pygame.image.load("images\\enemy_ship.png")
enemyShipRect = aeroplaneImage.get_rect()

#Enemy Bullets Class
class EnemyBullets:
    #Bullet
    enemyBulletImage1 = pygame.image.load("images\\enemy_bullet.png")
    enemyBulletImage2 = pygame.image.load("images\\enemy_bullet.png")
    enemySmokeImage=pygame.image.load("images\\smoke.png")
    enemyBulletShoot=False

enemyBullets=[EnemyBullets() for i in range(20)]
for j in range(0,20):
    enemyBullets[j].enemyBulletRect1=enemyBullets[j].enemyBulletImage1.get_rect()

for j in range(0,20):
    enemyBullets[j].enemyBulletRect2=enemyBullets[j].enemyBulletImage2.get_rect()

for j in range(0,20):
    enemyBullets[j].enemySmokeRect=enemyBullets[j].enemySmokeImage.get_rect()

#Fire
fireImage=pygame.image.load("images\\fire.png")
fireImageRect=fireImage.get_rect()

#Health Bar
aeroplaneHealthBarImage=pygame.image.load("images\\health_bar.png")
aeroplaneHealthBarRect=aeroplaneHealthBarImage.get_rect()

aeroplanePlusImage=pygame.image.load("images\\plus.png")
aeroplanePlusImageRect=aeroplanePlusImage.get_rect()

enemyShipHealthBarImage=pygame.image.load("images\\health_bar.png")
enemyShipHealthBarRect=enemyShipHealthBarImage.get_rect()

enemyShipPlusImage=pygame.image.load("images\\plus.png")
enemyShipPlusImageRect=enemyShipPlusImage.get_rect()

healthColor1=(255,91,167)
healthColor2=(255,60,154)

#pygame.mixer.music.load('sounds\\flying_sound.mp3')
#pygame.mixer.music.play(-1)

#gameOverImage=pygame.image.load('images\\game_over.png')
#gameOverImageRect=gameOverImage.get_rect()

#gameOverWindowImage=pygame.image.load('images\\game_over_window.png')
#gameOverWindowRect=gameOverWindowImage.get_rect()

#gameOverImageRect.centerx=canvasW//2
#gameOverImageRect.centery=canvasH//2

#gameOverWindowRect.centerx=canvasW//2
#gameOverWindowRect.centery=canvasH//2

running=False

def init():
    #print("init")
    global running
    global enemyShipHealth
    global aeroplaneHealth
    global aeroplaneRect
    global enemyShipRect
    global bullets

    running=True

    aeroplaneRect.left = 20
    aeroplaneRect.centery = canvasH//2

    enemyShipRect.left = canvasW-300
    enemyShipRect.centery = canvasH//2

    i=0
    for bullet in bullets:
        bullet.bulletShoot=False
        enemyBullets[i].enemyBulletShoot=False
        i+=1

def setMenu():

    global menuWindow
    global menuWindowRect
    global headerImage
    global headerImageRect
    global startImage
    global startImageRect
    global optionsImage
    global optionsImageRect
    global quitImage
    global quitImageRect

    indexHovered=0

    Canvas.blit(backGroundImage,backGroundRect)
    Canvas.blit(menuWindow,menuWindowRect)
    Canvas.blit(headerImage,headerImageRect)
    Canvas.blit(startImage,startImageRect)
    Canvas.blit(optionsImage,optionsImageRect)
    Canvas.blit(quitImage,quitImageRect)
    Canvas.blit(arrowImage,arrowImageRect)

    while True:

        for event in pygame.event.get():
            if event.type==QUIT:
                pygame.quit()
                sys.exit()

            if event.type == KEYDOWN:
                
                if event.key==K_ESCAPE:
                    pygame.quit()
                    sys.exit()

                if event.key==K_KP_ENTER or event.key==K_RETURN:
                    if indexHovered==0:
                        startImage=pygame.image.load("images\\pressed\\start_pressed.png")
                        Canvas.blit(startImage,startImageRect)
                        pygame.display.update()
                        time.sleep(0.1)
                        init()
                        gameLoop()
                        #headerImageRect.centerx=canvasW//2-115
                        #headerImage=pygame.image.load("images\\game_over.png")

                        Canvas.blit(menuWindow,menuWindowRect)
                        Canvas.blit(headerImage,headerImageRect)

                    if indexHovered==1:
                        optionsImage=pygame.image.load("images\\pressed\\options_pressed.png")
                        Canvas.blit(optionsImage,optionsImageRect)
                        pygame.display.update()
                        time.sleep(0.1)
                    if indexHovered==2:
                        quitImage=pygame.image.load("images\\pressed\\quit_pressed.png")
                        Canvas.blit(quitImage,quitImageRect)
                        pygame.display.update()
                        pygame.quit()
                        sys.exit()

                if event.key == K_UP:
                    indexHovered-=1

                if event.key == K_DOWN:
                    indexHovered+=1
                
                indexHovered=2 if indexHovered<0 else indexHovered
                indexHovered=0 if indexHovered>2 else indexHovered

            if indexHovered==0:
                startImage=pygame.image.load("images\\hover\\start_hover.png")
                optionsImage=pygame.image.load("images\\normal\\options_normal.png")
                quitImage=pygame.image.load("images\\normal\\quit_normal.png")
                arrowImageRect.left=startImageRect.right+10
                arrowImageRect.centery=startImageRect.centery

            if indexHovered==1:
                startImage=pygame.image.load("images\\normal\\start_normal.png")
                optionsImage=pygame.image.load("images\\hover\\options_hover.png")
                quitImage=pygame.image.load("images\\normal\\quit_normal.png")
                arrowImageRect.left=optionsImageRect.right+10
                arrowImageRect.centery=optionsImageRect.centery

            if indexHovered==2:
                startImage=pygame.image.load("images\\normal\\start_normal.png")
                optionsImage=pygame.image.load("images\\normal\\options_normal.png")
                quitImage=pygame.image.load("images\\hover\\quit_hover.png")
                arrowImageRect.left=quitImageRect.right+10
                arrowImageRect.centery=quitImageRect.centery

            Canvas.blit(menuWindow,menuWindowRect)
            Canvas.blit(headerImage,headerImageRect)
            Canvas.blit(startImage,startImageRect)
            Canvas.blit(optionsImage,optionsImageRect)
            Canvas.blit(quitImage,quitImageRect)
            Canvas.blit(arrowImage,arrowImageRect)
            pygame.display.update()

def gameLoop():

    global running
    global aeroplaneImage
    global aeroplaneRect
    global enemyShipImage
    global enemyShipRect
    global bullets
    global enemyBullets

    global headerImage
    global headerImageRect

    enemyShipHealth=114
    aeroplaneHealth=114
    sprite=0

    velocityX=20
    velocityY=20

    lMove=False
    rMove=False
    uMove=False
    dMove=False
    attack=False
    shoot=False

    while running:
        sprite=int(sprite)+1
        
        if sprite>4:
            sprite=1


        for event in pygame.event.get():
            if event.type==QUIT:
                pygame.quit()
                sys.exit()
            
            if event.type == KEYUP:
                lMove=False
                rMove=False
                uMove=False
                dMove=False

            if event.type == KEYDOWN:
                
                if event.key==K_ESCAPE:
                    print("helth",aeroplaneHealth)
                    pygame.quit()
                    sys.exit()

                if event.key == K_SPACE:
                    attack=True
                    shoot=True
                    sprite=1

                if event.key == K_UP:
                    uMove=True

                if event.key == K_LEFT:
                    lMove=True

                if event.key == K_RIGHT:
                    rMove=True

                if event.key == K_DOWN:
                    dMove=True
                

        aeroplaneImage = pygame.image.load("images\\fly"+str(sprite)+".png")
        if lMove:
            aeroplaneImage = pygame.image.load("images\\fly"+str(sprite)+".png")
            if aeroplaneRect.left-velocityX<20:
                aeroplaneRect.left=20
            else:
                aeroplaneRect.centerx-=velocityX

        if rMove:
            aeroplaneImage = pygame.image.load("images\\fly"+str(sprite)+".png")
            if aeroplaneRect.right+velocityX>canvasW-20:
                aeroplaneRect.right=canvasW-20
            else:
                aeroplaneRect.centerx+=velocityX

        if uMove:
            aeroplaneImage = pygame.image.load("images\\fly"+str(sprite)+".png")
            if aeroplaneRect.top-velocityY<80:
                aeroplaneRect.top=80
            else:
                aeroplaneRect.centery-=velocityY

        if dMove:
            aeroplaneImage = pygame.image.load("images\\fly"+str(sprite)+".png")
            if aeroplaneRect.bottom+velocityY>canvasH-20:
                aeroplaneRect.bottom=canvasH-20
            else:
                aeroplaneRect.centery+=velocityY


        if attack:
            if sprite==4:
                attack=False
                shoot=False
            
            aeroplaneImage = pygame.image.load("images\\shoot"+str(sprite)+".png")

            if shoot:
                for bullet in bullets:
                    if not bullet.bulletShoot:
                        bullet.bulletRect.left=aeroplaneRect.right-40
                        bullet.bulletRect.centery=aeroplaneRect.bottom-55;
                        bullet.bulletShoot=True
                        pygame.mixer.music.load('sounds\\aeroplane_gunshot.ogg')
                        pygame.mixer.music.play(1)
                        shoot=False
                        break

        ###
        aeroplaneRect.bottom+=random.randint(-1,1)
        aeroplaneRect.left+=random.randint(-1,1)

        enemyShipRect.bottom+=random.randint(-1,1)
        enemyShipRect.left+=random.randint(-1,1)

        aeroplaneHealthBarRect.centerx=aeroplaneRect.centerx
        aeroplaneHealthBarRect.bottom=aeroplaneRect.top-10

        aeroplanePlusImageRect.right=aeroplaneHealthBarRect.left+25
        aeroplanePlusImageRect.centery=aeroplaneHealthBarRect.centery

        enemyShipHealthBarRect.centerx=enemyShipRect.centerx
        enemyShipHealthBarRect.bottom=enemyShipRect.top-10

        enemyShipPlusImageRect.right=enemyShipHealthBarRect.left+25
        enemyShipPlusImageRect.centery=enemyShipHealthBarRect.centery

        Canvas.blit(backGroundImage, backGroundRect)

        Canvas.blit(aeroplaneHealthBarImage,aeroplaneHealthBarRect)
        Canvas.blit(aeroplanePlusImage,aeroplanePlusImageRect)
        pygame.draw.rect(Canvas,healthColor1,(aeroplaneHealthBarRect.left+26,aeroplaneHealthBarRect.top+10,aeroplaneHealth,7))
        pygame.draw.rect(Canvas,healthColor2,(aeroplaneHealthBarRect.left+26,aeroplaneHealthBarRect.top+17,aeroplaneHealth,7))
        
        Canvas.blit(enemyShipHealthBarImage,enemyShipHealthBarRect)
        Canvas.blit(enemyShipPlusImage,enemyShipPlusImageRect)
        pygame.draw.rect(Canvas,healthColor1,(enemyShipHealthBarRect.left+26,enemyShipHealthBarRect.top+10,enemyShipHealth,7))
        pygame.draw.rect(Canvas,healthColor2,(enemyShipHealthBarRect.left+26,enemyShipHealthBarRect.top+17,enemyShipHealth,7))
        
        Canvas.blit(aeroplaneImage, aeroplaneRect)
        Canvas.blit(enemyShipImage,enemyShipRect)

        enemyMove=random.randint(-5,4)

        if enemyMove==0:
            for enemyBullet in enemyBullets:
                if not enemyBullet.enemyBulletShoot:
                    enemyBullet.enemyBulletRect1.left=enemyShipRect.right-155
                    enemyBullet.enemyBulletRect1.centery=enemyShipRect.bottom-123;                
                    ###
                    enemyBullet.enemyBulletRect2.left=enemyShipRect.right-150
                    enemyBullet.enemyBulletRect2.centery=enemyShipRect.bottom-111;

                    pygame.mixer.music.load('sounds\\gunshot.ogg')
                    pygame.mixer.music.play(1)
                    enemyBullet.enemyBulletShoot=True
                    break

        if enemyMove==-1:
            enemyShipRect.bottom-=50
            if enemyShipRect.top<80:
                enemyShipRect.top=80

        if enemyMove==1:
            enemyShipRect.bottom+=50
            if enemyShipRect.bottom>canvasH-20:
                enemyShipRect.bottom=canvasH-20

        i=0
        for bullet in bullets:
            if bullet.bulletShoot:
                Canvas.blit(bullet.bulletImage,bullet.bulletRect)
                bullet.bulletRect.right+=80

                if bullet.bulletRect.left>canvasW+100:
                    bullet.bulletShoot=False

                if bullet.bulletRect.right>=enemyShipRect.left+100 and bullet.bulletRect.centery<enemyShipRect.bottom-40 and bullet.bulletRect.centery>enemyShipRect.top+40 and bullet.bulletRect.left<enemyShipRect.right:
                    bullet.smokeRect.right=bullet.bulletRect.right-40
                    bullet.smokeRect.centery=bullet.bulletRect.centery
                    Canvas.blit(bullet.smokeImage,bullet.smokeRect)
                    enemyShipHealth-=4
                    if enemyShipHealth<-4:
                        enemyShipHealth=-4
                    bullet.bulletShoot=False

            if enemyBullets[i].enemyBulletShoot:
                Canvas.blit(enemyBullets[i].enemyBulletImage1,enemyBullets[i].enemyBulletRect1)
                Canvas.blit(enemyBullets[i].enemyBulletImage2,enemyBullets[i].enemyBulletRect2)
                enemyBullets[i].enemyBulletRect1.right-=80
                enemyBullets[i].enemyBulletRect2.right-=80

                if enemyBullets[i].enemyBulletRect1.right<-100:
                    enemyBullets[i].enemyBulletShoot=False

                if enemyBullets[i].enemyBulletRect2.left<=aeroplaneRect.centerx and enemyBullets[i].enemyBulletRect2.centery<aeroplaneRect.bottom-20 and enemyBullets[i].enemyBulletRect2.centery>aeroplaneRect.top and enemyBullets[i].enemyBulletRect2.left>aeroplaneRect.left:
                    enemyBullets[i].enemySmokeRect.centerx=enemyBullets[i].enemyBulletRect2.left+80
                    enemyBullets[i].enemySmokeRect.centery=enemyBullets[i].enemyBulletRect2.centery
                    Canvas.blit(enemyBullets[i].enemySmokeImage,enemyBullets[i].enemySmokeRect)
                    aeroplaneHealth-=6
                    if aeroplaneHealth<-6:
                        aeroplaneHealth=-6
                    enemyBullets[i].enemyBulletShoot=False

            i+=1

        pygame.display.update()
        time.sleep(0.01)

        if enemyShipHealth<=0:
            running=False
            fireImageRect.centerx=enemyShipRect.centerx
            fireImageRect.centery=enemyShipRect.centery
            Canvas.blit(fireImage,fireImageRect)
            headerImageRect.centerx=canvasW//2-80
            headerImage=pygame.image.load("images\\you_win.png")


        if aeroplaneHealth<=0:
            running=False
            fireImageRect.centerx=aeroplaneRect.centerx+20
            fireImageRect.centery=aeroplaneRect.centery
            Canvas.blit(fireImage,fireImageRect)
            headerImageRect.centerx=canvasW//2-95
            headerImage=pygame.image.load("images\\you_lose.png")
            #break

        if aeroplaneRect.right>=enemyShipRect.left+50 and ((aeroplaneRect.top+100<enemyShipRect.bottom and aeroplaneRect.top+100>enemyShipRect.top) or (aeroplaneRect.bottom-50<enemyShipRect.bottom and aeroplaneRect.bottom-50>enemyShipRect.top)):
            fireImageRect.centerx=(aeroplaneRect.right+enemyShipRect.left)//2
            fireImageRect.centery=(aeroplaneRect.centery+enemyShipRect.centery)//2
            Canvas.blit(fireImage,fireImageRect)
            enemyShipHealth=0
            aeroplaneHealth=0
setMenu()