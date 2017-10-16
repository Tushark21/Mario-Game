#include<iostream.h>
#include<graphics.h>
#include<process.h>
#include<conio.h>
#include<dos.h>

void main()
{clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");

play:
int q,x=240,y=140,t=1,i=0,j=0,l=0;
int c[3][3]={0,0,0,0,0,0,0,0,0};
int n,m,x1,y1;

setcolor(11);
line(280,140,280,260);
line(240,180,360,180);
line(320,140,320,260);
line(240,220,360,220);

gotoxy(1,1);
cout<<"Player X turn";

while(!kbhit())
{ again:

if(x<240 || x>320)
{
x=x>240?240:320;
i=i>0?0:2;
}

if(y<140 || y>220)
{
y=y>140?140:220;
j=j>0?0:2;
}


setcolor(4);
rectangle(x+1,y+1,39+x,39+y);
rectangle(x+2,y+2,38+x,38+y);

}
setcolor(0);
rectangle(x+1,y+1,39+x,39+y);
rectangle(x+2,y+2,38+x,38+y);

q=getch();

if(q==77)
{
x=x+40;
i++;
}

else if(q==80)
{
y=y+40;
j++;
}

else if(q==75)
{
x=x-40;
i--;
}

else if(q==72)
{
y=y-40;
j--;
}


//Cross
else if(q==13 && t==1 && c[i][j]==0)
{
gotoxy(1,1);
cout<<"Player O turn";
c[i][j]=t;
setcolor(6);
line(x+10,y+10,30+x,30+y);
line(x+30,y+10,x+10,y+30);
t=2;
l++;

//Check
for(n=0;n<3;n++)
{
if((c[n][0]==1 && c[n][1]==1 && c[n][2]==1) || (c[0][n]==1 && c[1][n]==1 && c[2][n]==1) || (c[0][0]==1 && c[1][1]==1 && c[2][2]==1) || (c[0][2]==1 && c[1][1]==1 && c[2][0]==1))
{
gotoxy(1,1);
cout<<"YOU WINS     ";
goto input;
}
}
//

}

//
if(l==9)
{
gotoxy(1,1);
cout<<"Game Draw           ";
goto input;
}
//

//Zero
if(t==2)
{
gotoxy(1,2);
cout<<"Computer Thinking";

//
for(n=1;n<10;n++)
{
delay(150);

if(n%4!=0)
{
cout<<".";
}

else
{gotoxy(18,2);
cout<<"   ";
gotoxy(18,2);
}
}
//

gotoxy(1,2);
cout<<"                   ";

gotoxy(1,1);
cout<<"Player X turn";

x1=240;
y1=140;

if(c[1][1]==0)
{
x1=280;
y1=180;
c[1][1]=t;
}

//Horizontal Check
if(x1==240 && y1==140)
{
for(m=0;m<3;m++)
{
//
 if((c[0][m]==2 && c[1][m]==2) || (c[1][m]==2 && c[2][m]==2) || (c[0][m]==2 && c[2][m]==2))
 {
  for(n=0;n<3;n++)
   {
    if(c[n][m]==0)
    {
    x1=x1+(40*n);
    y1=y1+(40*m);
    c[n][m]=t;
    n=5;
    m=5;
    }  // 2nd if ends

   }  //for loop with n ends

 }  //1st if ends
//

//
 else if((c[0][m]==1 && c[1][m]==1) || (c[1][m]==1 && c[2][m]==1) || (c[0][m]==1 && c[2][m]==1))
 {
  for(n=0;n<3;n++)
   {
    if(c[n][m]==0)
    {
    x1=x1+(40*n);
    y1=y1+(40*m);
    c[n][m]=t;
    n=5;
    m=5;
    }  // 2nd if ends

   }  //for loop with n ends

 }  //1st if ends
//

}  //for loop with m ends

}  //complete else if ends
//


//Vertical Check
if(x1==240 && y1==140)
{
for(m=0;m<3;m++)
{
//
 if((c[m][0]==2 && c[m][1]==2) || (c[m][1]==2 && c[m][2]==2) || (c[m][0]==2 && c[m][2]==2))
 {
  for(n=0;n<3;n++)
   {
    if(c[m][n]==0)
    {
    x1=x1+(40*m);
    y1=y1+(40*n);
    c[m][n]=t;
    n=5;
    m=5;
    }  // 2nd if ends

   }  //for loop with n ends

 }  //1st if ends
//

//
 else if((c[m][0]==1 && c[m][1]==1) || (c[m][1]==1 && c[m][2]==1) || (c[m][0]==1 && c[m][2]==1))
 {
  for(n=0;n<3;n++)
   {
    if(c[m][n]==0)
    {
    x1=x1+(40*m);
    y1=y1+(40*n);
    c[m][n]=t;
    n=5;
    m=5;
    }  // 2nd if ends

   }  //for loop with n ends

  }  //1st if ends
//

 }  //for loop with m ends

}  //complete else if ends
//


//Random
if(x1==240 && y1==140)
{
for(m=0;m<3;m++)
{
for(n=0;n<3;n++)
{
if(c[n][m]==0)
{
x1=x1+(40*n);
y1=y1+(40*m);
c[n][m]=t;
n=5;
m=5;
}
}
}
//

}

setcolor(14);
circle(20+x1,20+y1,10);
t=1;
l++;

//Check
for(n=0;n<3;n++)
{
if((c[n][0]==2 && c[n][1]==2 && c[n][2]==2) || (c[0][n]==2 && c[1][n]==2 && c[2][n]==2) || (c[0][0]==2 && c[1][1]==2 && c[2][2]==2) || (c[0][2]==2 && c[1][1]==2 && c[2][0]==2))
{
gotoxy(1,1);
cout<<"YOU LOSE     ";
goto input;
}
}
//
}

goto again;

input:

gotoxy(1,2);
cout<<"Press Enter to play again ESC to exit";

q=getch();

if(q==13)
{
cleardevice();
goto play;
}

else if(q==27)
{
cleardevice();
exit(0);
}

else
{
goto input;
}

getch();
closegraph();
}
//K21