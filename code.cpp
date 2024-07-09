#include<bits/stdc++.h>
#include<conio.h>
#include <unistd.h>
using namespace std;
bool gameOver;
const int width=20;
const int height=20;
int x,y,fruitX,fruitY,score;
//direction
enum eDirection{STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;

void setup()
{
   gameOver=false;
   //direc stop so that snake wont move until we make it
   dir=STOP;
   x=width/2;//middle
   y=height/2;//for snake head to be at center
   //po of fruit at any random pos
   fruitX=rand()%width;//within the width of the game
   fruitY=rand()%height;
   score=0;
}
void draw()
{
       //draw a map 
       //first clear the screen
       system("cls");
       //for top wall
       for(int i=0;i<width;i++)
       {
        cout<<"*";
       }
       cout<<endl;

       for(int i=0;i<height;i++)
       {
        for(int j=0;j<width;j++)
        {
          if(j==0)//if first make wall we dont need for inside    
          cout<<"*";
          if(i==y&&j==x)
          {
            cout<<"O";
          }
          else if(i==fruitY && j==fruitX)
          cout<<"F";
          else
          cout<<" ";
          if(j==width-1)
          cout<<"*";
          

        }
        cout<<endl;
       }
       //for bottom wall
       for(int i=0;i<width+2;i++)
       {
        cout<<"*";
       
       }
        cout<<endl;
        cout<<"Score:"<<score<<endl;
}
//keyboard input:
//w->up
//a d->left and right respectively
// s ->down
void Input()
{
   //conio for getting character from console window
   //kbhit willl handle the user input from the keyboard 
   //use switch case for different keyboard actions
   if(_kbhit())
   {
      switch (_getch())
      {
        case 'a':
        dir=LEFT;
        break;
        case 'd':
        dir=RIGHT;
        break;
        case 'w':
        dir=UP;
        break;
        case 's':
        dir=DOWN;
        break;
        case 'x':
        gameOver=true;
        break;
      }
   }
}
void logic()
{ sleep(0.5);//slow the game if you want
   switch(dir)
   {
      case LEFT:
      x--;//dec the x cordinate by 1 of snake
      break;
      case RIGHT:
      x++;//increase the x coordinate of snake
      break;
      case UP:
      y--;
      break;
      case DOWN:
      y++;
      break;
      default:
      break;
   }
   //condition if it hits the boundary then game over
   if(x>width || x<0||y>height ||y<0)
   {
      gameOver=true;
   }
   //increase the score when eat the fruit
   if(x==fruitX && y==fruitY)
   {
      score+=10;//incr score
      //after score inc again place fruit random anywhere
      fruitX=rand()%width;//within the width of the game
      fruitY=rand()%height;
   }
}
int main()
{
   setup();
   while(!gameOver)
   {
    draw();
    Input();
    logic();
    
   }
}