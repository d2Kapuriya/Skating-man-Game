#include<iostream>
#include<graphics.h>
#include<conio.h>  //kbhit
#include <stdio.h>
#include<windows.h>
#include<dos.h>   //sleep
using namespace std;
int t,s,d,score=0;

char ch,arr[50];
void temple()  // temple function defination
{
    line(350,375,550,375);//base line
    line(350,250,550,250);//second base
    line(350,375,350,250);//first wall
    line(550,375,550,250);//second wall
    line(350,250,450,200);//first triangle line
    line(550,250,450,200);//second triangle line
    line(450,200,450,150);//dhaja straight line
    line(450,150,470,170);//dhaja triangle uper line
    line(470,170,450,170);// dhaja triangle lower line
}
void man(int jump)   // man function defination
{

    if(jump==0)
        t=0;
    if(jump==2)
        t=t-3;
    if(jump==1)
        t=t+3;
    setcolor(4);
   line(225,225-t,225,230-t);//noise
   circle(235,225-t,5);//second eye
   circle(215,225-t,5);//first eye
   circle(225,225-t,20);// face
   line(225,300-t,225,245-t); // belly
   line(225,255-t,250,285-t);//right hand
   line(225,255-t,200,285-t);// left hand
   line(200,285-t,180,395-t);// reference
   line(200,375-t,225,300-t); //first lag
   line(250,375-t,225,300-t);  //second lag
   setcolor(0);
   line(175,375-t,275,375-t);// plate
   line(175,375-t,170,370-t);//first plate corner
   line(275,375-t,280,370-t);//second plate corner
   setcolor(0);
   circle(200,385-t,10);//plate first wheel
   circle(250,385-t,10);//plate second wheel
   line(0,395,1000,395);
   line(0,396,1000,396);
   line(0,398,500,396);
}
void cap()  // cap function definaton
{
    int points[]={510-d,395,525-d,355,540-d,395,510-d,395};
    setcolor(4);
    setfillstyle(4,4);
    fillpoly(4,points);
    drawpoly(4,points);
    d++;
   if(d==524)
    {d=0;}
   if((d==524)||(d==300)||(d==100)||(d==200)||(d==400))
    {score++;}

}
int main()
{
    system("COLOR 3F");
    cout << "\n\n\t                      \t\t\t *==> SKATTING MAN <==*\n\n";
    cout << " \n\n\t\t\t                        \" \* WELCOME TO OUR GAME \* \"\n\n";
    cout<<"\n\n\n\t\t\t PRESS SPACE FOR JUMP ";
    cout<<"\n\n\t\t\t PRESS X FOR EXIT ";
     cout<<"\n\n\t\t\t PRESS P FOR PAUSE ";
      cout<<"\n\n\t\t\t PRESS ANY KEY  FOR CONTINUE ";
    cout<<"\n\n\t\t\t\t\t\t\tBest Of Luck ";
    cout<<"\n\n \t\t\t\t  \t\t\tGAME IS LOADING..";
    Sleep(500);
    for(int i=1; i<10; i++)
    {
        system("COLOR 4F");
        cout << ".";
        system("COLOR 3F");
    }


    int gd=DETECT,gm;
    char ch,choice;
    int x=10;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    settextstyle(4,0,5);
    setbkcolor(14);


while(true)
 {
        while(!kbhit())
        {
          sprintf(arr,"score : %d",score);
          outtextxy(50,10,arr);
          man(0);
          cap();
          if((d>=240)&&(d<270)&&(t<6))
            {
                settextstyle(4,0,5);
               setcolor(4);
               Beep(500,1000);
               outtextxy(75,75,"Game Over...!!!");
               Sleep(1000);
               exit(0);
            }
            cleardevice();
        }
      ch=getch();
      if(ch==' ')
      {
          for(int i=0;i<50;i++)
          {

              sprintf(arr,"score : %d",score);
              outtextxy(50,10,arr);
              man(1);
              cap();
             // temple();
             cleardevice();
          }
          for(int i=0;i<50;i++)
          {
              sprintf(arr,"score : %d",score);
              outtextxy(50,10,arr);
              man(2);
              cap();
              //temple();
              cleardevice();
          }
      }
     else if(ch=='x')
      {
          exit(0);
      }
    else if((ch=='p')||(ch=='P'))
      {
          while(!kbhit())
          {
               outtextxy(75,75,"PRESS ANY KEY FOR CONTINUE...");
          }
          ch=getch();
      }
    else
     {
          settextstyle(4,0,5);
          setcolor(4);
           Beep(500,500);
           outtextxy(75,75,"DO NOT PRESS ANY OTHER KEY...!!!");

    }
 }

  getch();
 closegraph();
}


