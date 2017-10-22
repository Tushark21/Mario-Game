#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>

void number(int ,int ,int);

void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");

play:
cleardevice();
int a[3][3],q,x=0,y=0,x1=2,y1=2,num,k,t;

setfillstyle(1,15);
bar(100,100,252,252);

//Setting Board & Its Numbers
srand(time(0));

for(int j=0;j<3;j++)
{numagain:
for(int i=0;i<3;i++)
{
t=rand()%9+1;

for(int k=0;k<3;k++)
{
for(int l=0;l<3;l++)
{

if(a[l][k]==t)
{
goto numagain;
}

}
}//Inner Loop Ends

num=a[i][j]=t;
}
}//Outer Loop Ends

for(j=0;j<3;j++)
{
for(int i=0;i<3;i++)
{
if(a[i][j]==9)
{
a[i][j]=a[2][2];
a[2][2]=-1;
}
setfillstyle(1,4);
bar(100+(i*50)+2,100+(j*50)+2,150+(i*50),150+(j*50));

num=a[i][j];
number(120+(i*50),120+(j*50),num);
}
}//Next Loop Ends
x=2;
y=2;
//

//
again:

k=1;
x=x>2?2:x;
x=x<0?0:x;
y=y>2?2:y;
y=y<0?0:y;

setfillstyle(1,0);
bar(100+(x*50)+2,100+(y*50)+2,150+(x*50),150+(y*50));
x1=x;
y1=y;

//Check
for(j=0;j<3;j++)
{
for(int i=0;i<3;i++)
{
if(a[i][j]==k)
{
k++;
}

else
{
k--;
}

}
}

if(k==8)
{
settextstyle(0,0,2);
setcolor(11);
outtextxy(120,80,"YOU WIN");

stat:
q=getch();

if(q==13)
{
goto play;
}

else if(q==27)
{
closegraph();
exit(0);
}

else
{
goto stat;
}

}
//

q=getch();

if(q==75)
{
x++;
}

else if(q==77)
{
x--;
}

else if(q==72)
{
y++;
}

else if(q==80)
{
y--;
}

else if(q==27)
{
closegraph();
exit(0);
}

num=a[x][y];
a[x1][y1]=a[x][y];
a[x][y]=-1;
setfillstyle(1,4);
bar(100+(x1*50)+2,100+(y1*50)+2,150+(x1*50),150+(y1*50));
number(120+(x1*50),120+(y1*50),num);

goto again;
}

void number(int x,int y,int num)
{
setcolor(0);
settextstyle(0,0,2);

switch(num)
{
case 1:
outtextxy(x,y,"1");
break;

case 2:
outtextxy(x,y,"2");
break;

case 3:
outtextxy(x,y,"3");
break;

case 4:
outtextxy(x,y,"4");
break;

case 5:
outtextxy(x,y,"5");
break;

case 6:
outtextxy(x,y,"6");
break;

case 7:
outtextxy(x,y,"7");
break;

case 8:
outtextxy(x,y,"8");
break;
}

}