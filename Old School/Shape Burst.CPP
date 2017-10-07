#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>
#include<stdlib.h>

void fig(int a[7][7],int i,int j);

void main()
{clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");

int a[7][7],x=0,y=0,q,temp=-1,x1,y1,x2,x3[6],n=0,h=0,t,v=1 ;
int s=0;

//Layout
rectangle(100,100,340,340);
for(int j=0;j<5;j++)
{
for(int i=0;i<5;i++)
{
line(140+(i*40),100,140+(i*40),340);
line(100,140+(i*40),340,140+(i*40));
}
}

settextstyle(0,0,2);
setcolor(4);
outtextxy(150,80,"SCORE:");
gotoxy(32,6);
cout<<s;

//Initial Figures
srand(time(0));
for(j=0;j<6;j++)
{
for(int i=0;i<6;i++)
{
a[i][j]=rand()%5;
fig(a,i,j);
}
}

delay(300);

for(int i=0;i<7;i++)
{
a[i][6]=-10;
a[6][i]=-10;
}

again:

//
//Checking
while(v>0)
{
v=0;
for(j=0;j<6;j++)
{
for(int i=0;i<6;i++)
{
//horizontal check
if(a[i][j]==a[i+1][j])
{
x3[n]=i;
x3[n+1]=i+1;
n++;
}

else if(n<2)
{
n=0;
}


if((n>=2 && a[i][j]!=a[i+1][j]) || (n>=2 && i==5))
{
for(int l=j;l>=0;l--)
{
for(int k=0;k<=n;k++)
{
if(l==0)
{
a[x3[k]][l]=rand()%5;
if(j==l)
{
setfillstyle(1,0);
bar(101+(x3[k]*40),101+(l*40),139+(x3[k]*40),139+(l*40));
s++;
}
}

else
{
a[x3[k]][l]=a[x3[k]][l-1];
if(j==l)
{
setfillstyle(1,0);
bar(101+(x3[k]*40),101+(l*40),139+(x3[k]*40),139+(l*40));
s++;
}
}

}//loop in if with k ends
}//loop in if with l ends

delay(500);

//
for(l=j;l>=0;l--)
{
for(int k=0;k<=n;k++)
{
if(l==0)
{
setfillstyle(1,0);
bar(101+(x3[k]*40),101+(l*40),139+(x3[k]*40),139+(l*40));
fig(a,x3[k],l);
}

else
{
setfillstyle(1,0);
bar(101+(x3[k]*40),101+(l*40),139+(x3[k]*40),139+(l*40));
fig(a,x3[k],l);
}

}//loop in if with k ends
}//loop in if with l ends

delay(300);
j=0;
n=0;
h=1;
v=1;
}//if loop ends
//

}//Loop with i ends
n=0;

setcolor(4);
outtextxy(150,80,"SCORE:");
gotoxy(32,6);
cout<<s;

//vertical check
for(i=0;i<6;i++)
{
if(a[j][i]==a[j][i+1])
{
n++;
}

else if(n<2)
{
n=0;
}


if((n>=2 && a[j][i]!=a[j][i+1]) || (n>=2 && i==5))
{
for(int k=i;k>=i-n;k--)
{
setfillstyle(1,0);
bar(101+(j*40),101+(k*40),139+(j*40),139+(k*40));
s++;
}

delay(500);

for(k=i;k>=0;k--)
{
if(k-n>0)
{
a[j][k]=a[j][k-n-1];
setfillstyle(1,0);
bar(101+(j*40),101+(k*40),139+(j*40),139+(k*40));
}

else
{
a[j][k]=rand()%5;
setfillstyle(1,0);
bar(101+(j*40),101+(k*40),139+(j*40),139+(k*40));
}

}//loop in if with k ends

//
for(k=i;k>=0;k--)
{
if(k-n>0)
{
fig(a,j,k);
}

else
{
fig(a,j,k);
}

}//loop in if with k ends

delay(300);
n=0;
j=0;
h=1;
v=1;
}//if loop ends

}//Loop with i ends
n=0;

}//Loop with j ends

setcolor(4);
outtextxy(150,80,"SCORE:");
gotoxy(32,6);
cout<<s;

}//While Loop ends
//

if(h==0 && q==13 && temp==-1)
{
setfillstyle(1,0);
t=a[x1][y1];
a[x1][y1]=a[x][y];
bar(101+(x1*40),101+(y1*40),139+(x1*40),139+(y1*40));
fig(a,x1,y1);

setfillstyle(1,0);
a[x][y]=t;
bar(101+(x*40),101+(y*40),139+(x*40),139+(y*40));
fig(a,x,y);
}

v=1;
//Selector
while(!kbhit())
{
x=x>5?5:x;
x=x<0?0:x;
y=y>5?5:y;
y=y<0?0:y;

setcolor(4);
rectangle(101+(x*40),101+(y*40),139+(x*40),139+(y*40));
rectangle(102+(x*40),102+(y*40),138+(x*40),138+(y*40));
rectangle(103+(x*40),103+(y*40),137+(x*40),137+(y*40));
}

setcolor(0);
rectangle(101+(x*40),101+(y*40),139+(x*40),139+(y*40));
rectangle(102+(x*40),102+(y*40),138+(x*40),138+(y*40));
rectangle(103+(x*40),103+(y*40),137+(x*40),137+(y*40));

q=getch();

h=0;

if(q==72)
{
y--;
}

else if(q==80)
{
y++;
}

else if(q==75)
{
x--;
}

else if(q==77)
{
x++;
}

else if(q==27)
{
exit(0);
}

else if(q==13)
{
if(temp==-1)
{
temp=a[x][y];
x1=x;
y1=y;
setcolor(4);
rectangle(105+(x*40),105+(y*40),135+(x*40),135+(y*40));
rectangle(106+(x*40),106+(y*40),134+(x*40),134+(y*40));
}

else if((x1-x==0 && y1-y==0) || (x1-x==-1 && y1-y==0) || (x1-x==1 && y1-y==0) || (x1-x==0 && y1-y==-1) || (x1-x==0 && y1-y==1))
{
setfillstyle(1,0);
a[x1][y1]=a[x][y];
bar(101+(x1*40),101+(y1*40),139+(x1*40),139+(y1*40));
fig(a,x1,y1);

setfillstyle(1,0);
a[x][y]=temp;
bar(101+(x*40),101+(y*40),139+(x*40),139+(y*40));
fig(a,x,y);
temp=-1;
delay(300);
}

}

goto again;
}

void fig(int a[7][7],int i,int j)
{
switch(a[i][j])
{
case 0:
setfillstyle(1,2);
setcolor(2);
fillellipse(120+(i*40),120+(j*40),6,9);      		   //Ellipse
break;

case 1:
setfillstyle(1,11);
setcolor(11);
pieslice(120+(i*40),120+(j*40),0,360,10);
							    //Ring
setfillstyle(1,0);
setcolor(0);
pieslice(120+(i*40),120+(j*40),0,360,7);
break;

case 2:
setfillstyle(1,12);
setcolor(12);
fillellipse(120+(i*40),120+(j*40),8,9);      		   //Circle
break;

case 3:
setfillstyle(1,14);
setcolor(14);
pieslice(120+(i*40),130+(j*40),45,135,18);    		     //Diamond
break;

case 4:
setfillstyle(1,1);
setcolor(1);
fillellipse(120+(i*40),120+(j*40),6,9);    		      //+
fillellipse(120+(i*40),120+(j*40),9,6);
break;
}

}
//K21