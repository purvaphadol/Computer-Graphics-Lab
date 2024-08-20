/*
CG Assignment-3

Name: Purva Gorakh Phadol
SE Computer
Div: B
Roll No: 49
Date: 17/09/22

Que. Write C++ program to draw the following pattern. Use DDA line and Bresenham‘s circle drawing algorithm. Apply the concept of encapsulation.
*/

#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class pattern
{
	public:
	int i,x1,y1,di,d,d1;
	float dx,dy,steps,xin,yin,x,y;
	void DDA_line(int x1,int y1,int x2,int y2,int icolor);
	void bre_circle(int xc,int yc,int R);
};

void pattern::DDA_line(int x1,int y1,int x2,int y2,int icolor)
{
	dx=(x2-x1);
	dy=(y2-y1);
	
	if (fabs(dx)>fabs(dy))
	{
		steps=fabs(dx);
	}
	else
	{
		steps=fabs(dy);
	}

	xin=dx/steps;
	yin=dy/steps;
	x=x1;
	y=y1; 

	for (i=0;i<steps;i++)
	{
		putpixel(floor(x),floor(y),icolor);
		x+=xin;
		y+=yin;
	}
}

void pattern::bre_circle(int xc,int yc,int R)
{
	x1=0;
	y1=R;
	di=2*(1-R);
	int limit=0;
	while(y1>=limit)
	{
		putpixel(xc+x1, yc+y1, 7);
		putpixel(xc-x1, yc+y1, 7);
		putpixel(xc-x1, yc-y1, 7);
		putpixel(xc+x1, yc-y1, 7);
		if(di<0)
		{
			d=((2*di)+(2*y1)-1);
			if(d<=0)
			{
				x1=x1+1;
				di=di+(2*x1)+1;
			}
			else
			{
				x1=x1+1;
				y1=y1-1;
				di=di+(2*x1)-(2*y1)+2;
			}
		}
		else if(di>0)
		{
			d=((2*di)-(2*x1)-1);
			if(d<=0)
			{
				x1=x1+1;
				y1=y1-1;
				di=di+(2*x1)-(2*y1)+2;
			}
			else
			{
				y1=y1-1;
				di=di-(2*y1)+1;
			}
		}
		else if (di==0)
		{
			x1=x1+1;
			y1=y1-1;
			di=di+(2*x1)-(2*y1)+2;
		}
	}
}


int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);

	pattern c;
	c.DDA_line(300,200,386.5,350,7);
	c.DDA_line(300,200,213.5,350,7);
	c.DDA_line(386.5,350,213.5,350,7);
	c.bre_circle(300,300,100);
	c.bre_circle(300,300,50);

	delay(10000);
	closegraph();
	return 0;
}

/*
Input:
Line: Coordinates for the lines are predefined in the program.
	DDA_line(x1, y1, x2, y2, icolor)
	x1, y1: The coordinates of the starting point of the line.
	x2, y2: The coordinates of the ending point of the line.
	icolor: The color of the line (represented by the integer 7, which typically corresponds to the color white in graphics libraries).

Circle: Center and radius for the circles are predefined in the program.
	bre_circle(xc, yc, R)
	xc, yc: The coordinates of the center of the circle.
	R: The radius of the circle.


Console Output: No user input is required; all coordinates and parameters are set within the program.


Output Image: CGA3_ddaLine_breCircle.png
*/

