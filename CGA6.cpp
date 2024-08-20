/*
CG Assignment-6

Name: Purva Gorakh Phadol
SE Computer
Div: B
Roll No: 49
Date: 19/11/22

Que: Write a C++ program to implement bouncing ball using sine wave form. Apply the concept of polymorphism. 
*/

#include<iostream>
#include<graphics.h>
#include<cmath>
using namespace std;

class ball
{
	public:
	void sine()
	{
		setcolor(6);
		line(getmaxx()/2,0,getmaxx()/2,getmaxy());
		line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
	}

	void sine(int angle)
	{
		double x,y;
		//Generate sine wave
		for(x=0;x<getmaxx();x+=1)
		{
			//Calculate y for corresponding x
			y=200*sin(angle*3.14/180);		//200=height
											//at 0=y=0
			y=getmaxy()/2-y;
		
			setcolor(8);
			fillellipse(x,y,25,25);
			delay(40);
			cleardevice();
			angle+=1;
			sine();		
		}
	}		
};

int main()
{
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	int angle;
	
	cout<<"ENTER THE ANGLE: ";
	cin>>angle;
	ball obj;
	
	obj.sine(angle);
	delay(5000);
	getch();
	closegraph();
	return 0;
}

/*
Input: The user inputs an initial angle value, which determines the starting position of the sine wave. The input is provided via the console.


Console Example:
ENTER THE ANGLE: 90


Output: The output is a graphical animation of a ball bouncing along a sine wave path. The ball appears to move smoothly across the screen, following the sine wave's curve. The image is displayed in the graphical window.

Output Image: CGA6_bouncingBall.png
*/
