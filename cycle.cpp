#include<iostream>
#include<graphics.h>
#include<cstdlib>
#include<conio.h>
#include <stdio.h>
#include<math.h>
#include <time.h>
#include <windows.h>
using namespace std;
int x=100,y=300, t=0,speed;
void gotoxy(int x, int y)
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void getup()
{
    system("cls");
    outtextxy(5,2,"===>Press X to Exit, Press Space to Jump");
    outtextxy(50,100,"SCORE : ");
    /*for(int x=0;x<79;x++)
    outtextxy(x,400,"ß");*/

        //road
     line(0,y+50,x+1000,y+50);
}

void ds(int jump=0)
{
   double p=0;
    static int a=1;

    if(jump==0)
        t=0;
    else if(jump==2)
        t--,x-2;
    else t++,x+2;
    setcolor(4);
    line(x+100,y-100-t,x+200,y-100-t);   // horizontale handle
    line(x+150,y-100-t,x+150,y-50-t);// verticle handle
    line(x,y-t,x+150,y-t);  //  between two wheel line

    line(x+150,y-t,x+150-50*cos(p),y-t-50*sin(p));  // first wheel line
    line(x+150,y-t,x+150-50*cos(p+2*3.14/3),y-t-50*sin(p+2*3.14/3));   //first wheel line
    line(x+150,y-t,x+150-50*cos(p-2*3.14/3),y-t-50*sin(p-2*3.14/3));    // first wheel line
    line(x,y-t,x-50*cos(p),y-t-50*sin(p));    //second wheel line
    line(x,y-t,x-50*cos(p+2*3.14/3),y-t-50*sin(p+2*3.14/3));  //second wheel line
    line(x,y-t,x-50*cos(p-2*3.14/3),y-t-50*sin(p-2*3.14/3));  // second wheel line

    //while
    setcolor(2);

    circle(x,y-t,50);   // second wheel(pachal)
    circle(x+150,y-t,50);  // first wheel (agal)
    p=p+0.09;

    delay(speed);
}
void obj()
{
    int j=700,k=300;
    static int t=0,scr=0;
    if(x==56 && t<4)
    {
    scr=0;
    speed=40;
    outtextxy(400,400,"Game Over");
    getch();
    printf("         ");
    }

    // register
    line(j+25-t,k+25,j+25-t,k); // second line of register
    line(j+75-t,k+25,j+75-t,k);  // first line of register
    line(j+25-t,k+25,j+75-t,k+25); // third line of register
    line(j+50-t,k+50,j+50-t,k+25); //four line of register
    t++;
    if(t==749)
    {
        t=0;
        scr++;
        outtextxy(100,10,"score :scr");
        outtextxy(120,10,"scr");
        if(speed>20)
        speed--;
    }

    cleardevice();
}
int main()
{

    int gd=DETECT,gm,i;
    char ch;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    setbkcolor(14);
    system("mode con: lines=29 cols=82");
    getup();
    while(true)
    {
        while(!kbhit())
        {
            ds();
            obj();
        }
        ch=getch();
        if(ch==' ')
        {
            for(i=0;i<75;i++)
           {
            cleardevice();
            ds(1);
            obj();
            }
            for(i=0;i<75;i++)
            {cleardevice();
            ds(2);
            obj();
            }
        }

        else if (ch=='x')
            return(0);

    }

 getch();
    closegraph();

}



