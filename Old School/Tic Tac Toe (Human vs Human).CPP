#include<iostream.h>
#include<graphics.h>
#include<process.h>
#include<conio.h>

void main()
{clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");

play:
int q,x=240,y=140,t=1,i=0,j=0,l=0;
int c[3][3]={0,0,0,0,0,0,0,0,0};

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
for(int n=0;n<3;n++)
{
if((c[n][0]==1 && c[n][1]==1 && c[n][2]==1) || (c[0][n]==1 && c[1][n]==1 && c[2][n]==1) || (c[0][0]==1 && c[1][1]==1 && c[2][2]==1) || (c[0][2]==1 && c[1][1]==1 && c[2][0]==1))
{
gotoxy(1,1);
cout<<"Player X Wins";
goto exit;
}
}
//

}

//Zero
else if(q==13 && t==2 && c[i][j]==0)
{
gotoxy(1,1);
cout<<"Player X turn";
c[i][j]=t;
setcolor(14);
circle(20+x,20+y,10);
t=1;
l++;

//Check
for(int n=0;n<3;n++)
{
if((c[n][0]==2 && c[n][1]==2 && c[n][2]==2) || (c[0][n]==2 && c[1][n]==2 && c[2][n]==2) || (c[0][0]==2 && c[1][1]==2 && c[2][2]==2) || (c[0][2]==2 && c[1][1]==2 && c[2][0]==2))
{
gotoxy(1,1);
cout<<"Player O Wins";
goto exit;
}
}
//

}


//
if(l!=9)
{
goto again;
}

else
{
gotoxy(1,1);
cout<<"Game Draw           ";
}

exit:

cout<<"\nPress Enter to play again ESC to exit";

input:
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