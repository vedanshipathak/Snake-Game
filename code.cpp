#include<bits/stdc++.h>
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
        cout<<"#";
       }
       cout<<endl;

       for(int i=0;i<height;i++)
       {
        for(int j=0;j<width;j++)
        {
          if(j==0)//if first make wall we dont need for inside
          cout<<"#";
          
          cout<<" ";
          if(j==width-1)
          cout<<"#";
          

        }
        cout<<endl;
       }
       //for bottom wall
       for(int i=0;i<width;i++)
       {
        cout<<"#";
       
       }
        cout<<endl;
}
void Input()
{

}
void logic()
{

}
int main()
{
   setup();
   while(!gameOver)
   {
    draw();
    Input();
    logic();
    //Sleep(10);//slow the game if you want
   }
}