#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>

void card(int x,int y,int a[8][8]);

void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");
int x,y,q,h,l,r,m,n,a[8][8],b[8][8],c[8][8],dx,dy,s;

exit:
x=y=dx=dy=h=m=n=0;
cout<<"Enter Board Size(>2 & <9)\n";
cin>>s;

settextstyle(0,0,2);

gotoxy(1,1);
cleardevice();
l=25+((s-4)*15);

if(s<3 || s>8){
cout<<"Invalid Board Size :(\n";
goto exit;
}

//Card Colour
srand(time(0));
for(int i=0;i<s;i++)
{
for(int j=0;j<s;j++)
{
r=rand()%4;
if(r%3!=0)
{
b[i][j]=c[i][j]=a[i][j]=2;
m++;
}

else
{
b[i][j]=c[i][j]=a[i][j]=4;
}

}
}

//Layout
setcolor(15);
rectangle(100,100,100+(s*50),100+(s*50));
for(i=0;i<s-1;i++)
{
line(150+(i*50),100,150+(i*50),100+((s)*50));	         //Vertical line

line(100,150+(i*50),100+((s)*50),150+(i*50));	         //Horizontal line
}

setfillstyle(1,14);
settextstyle(0,0,3);
setcolor(0);
for(int j=0;j<=(s-1)*50;)
{
for(int i=0;i<=(s-1)*50;)
{
bar(110+i,106+j,140+i,144+j);
outtextxy(117+i,115+j,"?");

i=i+50;
}
j=j+50;
}
cout<<"Moves Left "<<l;

//
while(l>0)
{
x=x>s-1?0:x;
x=x<0?s-1:x;
y=y>s-1?0:y;
y=y<0?s-1:y;

setcolor(1);
rectangle(107+(x*50),105+(y*50),143+(x*50),145+(y*50));
rectangle(108+(x*50),104+(y*50),142+(x*50),146+(y*50));
rectangle(109+(x*50),103+(y*50),141+(x*50),147+(y*50));

q=getch();

setcolor(0);
rectangle(107+(x*50),105+(y*50),143+(x*50),145+(y*50));
rectangle(108+(x*50),104+(y*50),142+(x*50),146+(y*50));
rectangle(109+(x*50),103+(y*50),141+(x*50),147+(y*50));

if(q==75)
{
x--;
}

else if(q==77)
{
x++;
}

else if(q==72)
{
y--;
}

else if(q==80)
{
y++;
}

else if(q==13 && a[x][y]!=-1)
{
l--;
if(a[x][y]==b[dx][dy] || h==0)
{
if(a[x][y]==2)
{
n++;
}

card(x,y,a);
a[x][y]=-1;
dx=x;
dy=y;
h=1;
}

else
{
h=0;
setfillstyle(1,14);
bar(110+(dx*50),106+(dy*50),140+(dx*50),144+(dy*50));
outtextxy(117+(dx*50),115+(dy*50),"?");

a[dx][dy]=b[dx][dy];

if(a[dx][dy]==2)
{
n--;
}

}

gotoxy(12,1);
cout<<l<<" ";
}

else if(q==27)
{
cleardevice();
closegraph();
exit(0);
}

//Check
if(m==n)
{
setcolor(11);
outtextxy(60+(s*15),40,"You Win");
outtextxy(80+(s*10),70,"SCORE:");
gotoxy(30+s,6);
cout<<(s*50)+(l*30)+500;
getch();
cleardevice();
gotoxy(1,1);

goto exit;
}

}

setcolor(11);
outtextxy(50+(s*10),40,"Game Over");
getch();
cleardevice();
closegraph();
}

void card(int x,int y,int a[8][8])
{
setfillstyle(1,a[x][y]);
bar(110+(x*50),106+(y*50),140+(x*50),144+(y*50));

if(a[x][y]==2){
//Tick
line(113+(x*50),122+(y*50),120+(x*50),135+(y*50));
line(113+(x*50),122+(y*50),119+(x*50),135+(y*50));
line(113+(x*50),122+(y*50),118+(x*50),135+(y*50));
line(113+(x*50),122+(y*50),117+(x*50),135+(y*50));

line(120+(x*50),135+(y*50),137+(x*50),120+(y*50));
line(119+(x*50),135+(y*50),137+(x*50),120+(y*50));
line(118+(x*50),135+(y*50),137+(x*50),120+(y*50));
line(117+(x*50),135+(y*50),137+(x*50),120+(y*50));
}

else{
//Cross
line(115+(x*50),111+(y*50),135+(x*50),139+(y*50));
line(116+(x*50),111+(y*50),135+(x*50),139+(y*50));
line(117+(x*50),111+(y*50),135+(x*50),139+(y*50));
line(118+(x*50),111+(y*50),135+(x*50),139+(y*50));

line(135+(x*50),111+(y*50),115+(x*50),139+(y*50));
line(134+(x*50),111+(y*50),115+(x*50),139+(y*50));
line(133+(x*50),111+(y*50),115+(x*50),139+(y*50));
line(132+(x*50),111+(y*50),115+(x*50),139+(y*50));
}

}