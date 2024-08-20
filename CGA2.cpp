/*
CG Assignment-2

Name: Purva Gorakh Phadol
SE Computer
Div: B
Roll No: 49
Date: 8/10/22

Que. Write C++ program to implement Cohen Southerland line clipping algorithm.
*/

#include<iostream>
#include<graphics.h>
#include<cmath>
using namespace std;

static int CENTER=0,TOP=8,BOTTOM=4,RIGHT=2,LEFT=1,INSIDE=0;		// Defining region codes
static int x_min,y_min,x_max,y_max;

// Function to compute region code for a point(x, y)
int computeCode(double x, double y)
{	
	int code = INSIDE;		// initialized as being inside

	if (x < x_min)		// to the left of rectangle
	{ 
		code |= LEFT;
	}
	else if (x > x_max)		// to the right of rectangle
	{ 
		code |= RIGHT;
	}
	else if (y < y_min)		// below the rectangle
	{ 
		code |= BOTTOM;
	}
	else if (y > y_max)		// above the rectangle
	{
	    code |= TOP;
	} 

	return code;
}

void cohenSutherlandClip(double x1, double y1,double x2, double y2)
{
	// Compute region codes for P1, P2
	int code1 = computeCode(x1, y1);
	int code2 = computeCode(x2, y2);
	
	bool accept = false;

	while (true) 
	{
		if ((code1 == 0) && (code2 == 0)) 	// If both endpoints lie within rectangle
		{
			accept = true;
			break;
		}
		else if (code1 & code2) 	// If both endpoints are outside rectangle, in same region
		{
			break;
		}
		else 
		{	// Some segment of line lies within the rectangle
			int code_out;
			double x, y;
			
			if (code1 != 0)		// At least one endpoint is outside the rectangle, pick it.
			{
				code_out = code1;
			}
			else
			{
				code_out = code2;
			}
			// Find intersection point using formulas
			if (code_out & TOP) 	// point is above the clip rectangle
			{
				x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
				y = y_max;
			}
			else if (code_out & BOTTOM) 	// point is below the rectangle
			{
				x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
				y = y_min;
			}
			else if (code_out & RIGHT) 	// point is to the right of rectangle
			{
				y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
				x = x_max;
			}
			else if (code_out & LEFT) 	 // point is to the left of rectangle
			{
				y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
				x = x_min;
			}

			// Now intersection point x, y is found
            // We replace point outside rectangle by intersection point
			if (code_out == code1) 
			{
				x1 = x;
				y1 = y;
				code1 = computeCode(x1, y1);
			}
			else
			{
				x2 = x;
				y2 = y;
				code2 = computeCode(x2, y2);
			}
		}	
	}
	
	if (accept) 
	{
	    cleardevice();
		cout<<"Line accepted from "<<x1<<", "<<y1<<" to "<<x2<<", "<<y2<<endl;
		rectangle(x_min,y_min,x_max,y_max);
		line(x1,y1,x2,y2);
	}
	else
	{
		cout<<"Line rejected"<<endl;
	}         
}

int main()
{
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	int x2,x3,y2,y3;
	
    cout<<"Enter the Co-ordinate of Rectangle: ";
	cin>>x_min>>y_min>>x_max>>y_max;
	rectangle(x_min,y_min,x_max,y_max);
	cout<<"Enter the Co-ordinate of Line: ";
	cin>>x2>>y2>>x3>>y3;
	line(x2,y2,x3,y3);
	cohenSutherlandClip(x2,y2,x3,y3);

	delay(10000);
	closegraph();
	return 0 ;
}

/*
Input:
Coordinates of the rectangular clipping window.
Coordinates of the line to be clipped.


Console Output Example:
Enter the Co-ordinate of Rectangle: 50
50
200
200
Enter the Co-ordinate of Line: 30
30
250
250
Line accepted from 50, 50 to 200, 200


Output Image: CGA2_lineCipping.png
*/
