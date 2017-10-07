#include<iostream.h>
#include<dos.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>


//Prototype of Distraction Function
void distraction(int cn,int col);


//Prototype of Track Function
void car(int b,int a,int cn,int col);


//Function to Try Again
void again(int cn,int col)
{

while(1)
{
cleardevice();

//Background Color
setfillstyle(SOLID_FILL,7);

setcolor(15);
rectangle(150,0,500,480);
floodfill(1,1,15);
floodfill(600,1,15);

//car
car(120,0,cn,col);

//Boundary
setfillstyle(SOLID_FILL,15);
bar(150,0,495,5);
bar(150,0,155,479);
bar(495,0,500,479);
bar(150,473,500,480);
//

//Road Marks
setfillstyle(SOLID_FILL,14);
bar(256,44,274,122);
bar(376,44,394,122);

bar(256,200,274,278);
bar(376,200,394,278);

bar(256,356,274,434);
bar(376,356,394,434);
//

//Traffic Lights
setfillstyle(SOLID_FILL,9);
bar(300,200,350,330);

setcolor(15);
setfillstyle(SOLID_FILL,0);

circle(325,225,15);
floodfill(326,226,15);

circle(325,265,15);
floodfill(326,266,15);

circle(325,305,15);
floodfill(326,306,15);

delay(500);

for(int p=0;p<3;p++)
{
setfillstyle(SOLID_FILL,(p%2)*11+4-p);
floodfill(325,225+p*40,15);

delay(1000);
}

setfillstyle(SOLID_FILL,0);
bar(300,200,350,330);
//

distraction(cn,col);
goto exit;
}

exit:
}

//Function for distraction
void distraction(int cn,int col)
{
int q,k,l,c,d1,d2,s,n,m,t,y;
d1=d2=s=n=y=0;
c=1;
k=7;
m=6;
t=5;
int i=0,j=0,e=0,i1=0,j1=0,e1=0;
int bi=0,bj=0,be=0;

srand(time(0));

while(!kbhit())
{
play:
setfillstyle(SOLID_FILL,7);
bar(525,400,620,420);

//distraction
if(n==0)
{
l=0;
y=240;
}

else if(n==1)
{
l=120;
y=0;
}

else if(n==2)
{
l=240;
y=120;
}

setcolor(12);
line(165+l,k,245+l,k);

if(m>103)
{
setcolor(0);
line(165+l,m-97,245+l,m-97);
}

if(s>30)
{
setcolor(11);
line(165+y,k,245+y,k);

if(m>103)
{
setcolor(0);
line(165+y,m-97,245+y,m-97);
}
}

k=k+2;
m=m+2;
//

//Road Marks
setfillstyle(SOLID_FILL,14);

bar(256,44+bi,274,122+bi);
bar(376,44+bi,394,122+bi);

bar(256,200+bj,274,278+bj);
bar(376,200+bj,394,278+bj);

bar(256,356+be,274,434+be);
bar(376,356+be,394,434+be);

setcolor(14);
if(bi>39)
{
line(256,6+i,274,6+i);
line(376,6+i,394,6+i);
i++;
}

if(i>156 || j>0)
{
line(256,6+j,274,6+j);
line(376,6+j,394,6+j);
j++;
}

if(j>156 || e>0)
{
line(256,6+e,274,6+e);
line(376,6+e,394,6+e);
e++;
}

setfillstyle(1,15);
bar(150,473,500,480);
setcolor(0);

//bar
line(256,43+bi,274,43+bi);
line(376,43+bi,394,43+bi);

line(256,199+bj,274,199+bj);
line(376,199+bj,394,199+bj);

line(256,355+be,274,355+be);
line(376,355+be,394,355+be);
//

if(i>78 || i1>0)
{
line(256,6+i1,274,6+i1);
line(376,6+i1,394,6+i1);
i1++;
}

if(j>78 || j1>0)
{
line(256,6+j1,274,6+j1);
line(376,6+j1,394,6+j1);
j1++;
}

if(e>78 || e1>0)
{
line(256,6+e1,274,6+e1);
line(376,6+e1,394,6+e1);
e1++;
}

i=i>466?0:i;
j=j>466?0:j;
e=e>466?0:e;

i1=i1>466?0:i1;
j1=j1>466?0:j1;
e1=e1>466?0:e1;

if(bi<500)
{
bi++;
bj++;
be++;
}
//

delay(t);

//
if(k>345 && n==0)
{
d1=1;
}

else if(k>345 && n==1)
{
d1=2;
}

else if(k>345 && n==2)
{
d1=3;
}

if(s>30)
{
if(k>345 && y==0)
{
d2=1;
}

else if(k>345 && y==120)
{
d2=2;
}

else if(k>345 && y==240)
{
d2=3;
}

}

//
if(m>569)
{
m=6;
d1=d2=0;
k=7;
s++;
n=rand()%3;
}

if(m>471)
{
k=-1;
}

//Check
if((c==1 && (d1==1 || d2==1)) || (c==2 && (d1==2 || d2==2))  || (c==3 && (d1==3 || d2==3)))
{
settextstyle(0,0,7);
setcolor(4);
outtextxy(75,195,"GAME OVER");

settextstyle(0,0,2);
setcolor(1);
outtextxy(260,273,"SCORE:");
gotoxy(46,18);
cout<<(s*100)+(s/30)*200+(s/50)*300+(s/100)*500;

goto exit;
}

}

//Change Track & Change Speed
while(1)
{
q=getch();

//Change Track
if(q==75 && c==2)
{
car(120,0,cn,col);
c=1;
goto play;
}

else if((q==77 && c==1) || (q==75 && c==3))
{
car(240-(240*(c%3)),120,cn,col);
c=2;
goto play;
}

else if(q==77 && c==2)
{
car(120,240,cn,col);
c=3;
goto play;
}

else if(q==32)   //pause
{
setcolor(6);
settextstyle(0,0,2);
outtextxy(525,400,"PAUSED");

q=getch();
if(q==32)
{
goto play;
}
}

//Change Speed
else if(q==72)
{
t--;
t=t<0?0:t;
goto play;
}

else if(q==80)
{
t++;
t=t>5?5:t;
goto play;
}
//

else
{
goto play;
}
//

}

exit:
q=getch();

if(q==13)
{
cleardevice();
}

else
{
goto exit;
}

}


//Main Function
void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");

int i,q,cn=1,col=3,scol=1;

//Menu
i=0;
again:

i=i>80?80:i;
i=i<0?0:i;

setfillstyle(1,3);
bar(0,10+i,700,30+i);

setcolor(15);
settextstyle(0,0,2);
outtextxy(100,15,"NEW GAME");
outtextxy(100,35,"HELP");
outtextxy(100,55,"OPTION");
outtextxy(100,75,"HIGH SCORE");
outtextxy(100,95,"EXIT");

q=getch();

//Menu Slector
setfillstyle(1,0);
bar(0,10+i,700,30+i);

if(q==80)
{
i=i+20;
}

else if(q==72)
{
i=i-20;
}
//

else if(q==13 && i==0)
{
again(cn,col);
}

else if(q==13 && i==20)
{
cleardevice();

settextstyle(0,0,2);
setcolor(14);
outtextxy(10,20,"You have to cross each obstacles that");
outtextxy(10,40,"comes on the way.Use LEFT/RIGHT Arrow");
outtextxy(10,60,"keys to move the car & UP/DOWN Arrow");
outtextxy(10,80,"keys to increase the speed of the car.");
outtextxy(10,100,"As the car crosses the obstacles the");
outtextxy(10,120,"Difficulty Level Increases and so the");
outtextxy(10,140,"Score.");

getch();
cleardevice();
}

else if(q==13 && i==40)
{
cleardevice();
settextstyle(0,0,3);
selcar:
col=col<3?3:col;
col=col>14?14:col;
car(100,100,cn,col);

while(!kbhit())
{
setcolor(scol);
outtextxy(200,100,"SELECT CAR");
scol=scol>14?1:scol;
scol++;
delay(100);
}
q=getch();

col=q==72 && cn==2?3:col;
col=q==80 && cn==1?3:col;

cn=q==72?1:cn;
cn=q==80?2:cn;

if(q==75)
{
if(col==8 || col==14)
{
col=col-(col%10)/2;
}
else
col--;

}

else if(q==77)
{
if(col==4 || col==12)
{
col=col+col%10;
}
else
col++;
}

else if(q==13)
{
cleardevice();
goto again;
}

goto selcar;
}

else if(q==13 && i==60)
{
cleardevice();
gotoxy(0,0);
outtextxy(200,100,"HIGH SCORE");
getch();
cleardevice();
goto again;
}

else if(q==13 && i==80)
{
cleardevice();
closegraph();
exit(0);
}
goto again;

}


//Function for Change in Track
void car(int b,int a,int cn,int col)
{
//Hide Car
setfillstyle(SOLID_FILL,0);
bar(159+b,345,251+b,470);

//3D Car
if(cn==1)
{
setfillstyle(1,col);
bar(180+a,355,230+a,460);

setcolor(col);
pieslice(180+a,355,90,180,10);    //1
pieslice(230+a,355,0,90,10);      //2
pieslice(180+a,460,180,270,10);   //3
pieslice(230+a,460,270,360,10);   //4
bar(180+a,345,230+a,355);     //UP
bar(180+a,460,230+a,470);    //DOWN
bar(170+a,355,180+a,460);     //LEFT
bar(230+a,355,240+a,460);     //RIGHT

pieslice(169+a,380,90,180,10);    //LEFT MIRROR
pieslice(241+a,380,0,90,10);      //RIGHT MIRROR

setfillstyle(1,0);
bar(180+a,380,230+a,405);
bar(180+a,435,230+a,455);
bar(180+a,380,190+a,455);
bar(220+a,380,230+a,455);

setcolor(15);
line(180+a,380,190+a,405);
line(230+a,380,220+a,405);

line(190+a,435,180+a,455);
line(220+a,435,230+a,455);

rectangle(180+a,380,230+a,455);
rectangle(190+a,405,220+a,435);
}

else if(cn==2)
{
//car
setfillstyle(SOLID_FILL,col);

bar(165+a,345,245+a,360);
bar(185+a,360,225+a,460);
bar(175+a,385,235+a,435);
bar(165+a,460,245+a,470);

setfillstyle(SOLID_FILL,1);
bar(170+a,364,180+a,382);
bar(230+a,364,240+a,382);
bar(170+a,439,180+a,457);
bar(230+a,439,240+a,457);

bar(180+a,370,184+a,376);
bar(226+a,370,230+a,376);
bar(180+a,445,184+a,451);
bar(226+a,445,230+a,451);

}

}
//K21