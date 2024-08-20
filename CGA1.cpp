/*
CG Assignment-1

Name: Purva Gorakh Phadol
SE Computer
Div: B
Roll No: 49
Date: 1/10/22

Que. Write C++ program to draw a concave polygon and fill it with desired color using scan fill algorithm. Apply the concept of inheritance.
*/

#include <iostream>
#include <graphics.h>
using namespace std;

class lines
{
    public:
        void drawline(int x1,int y1,int x2,int y2)
        {
            line(x1,y1,x2,y2);
        }
};

class polygon : public lines
{
    int n,i,j,k,dy,dx;
    int y,temp;
    int x1[10],y1[10],xi[10];
    float m[10];
    public:
        void scanfill()
        {
            cout<<"Enter the Number of Sides of Polygon: ";
            cin>>n;

            for(i=0;i<n;i++)
            {
                cout<<"Enter the x & y Coordinates: ";
                cin>>x1[i]>>y1[i];       
            }

            x1[n]=x1[0]; //to join start and end
            y1[n]=y1[0];
            
            for(i=0;i<n;i++)
            {
                drawline(x1[i],y1[i],x1[i+1],y1[i+1]);
            }
            
            for(i=0;i<n;i++)
            {
                dx=x1[i+1]-x1[i];
                dy=y1[i+1]-y1[i];
                if(dy==0)
                {
                    m[i]=1;
                }
                if(dx==0)
                {
                    m[i]=0;
                }
                if((dx!=0) && (dy!=0))
                {
                    m[i]=dx/dy;
                }
            }
            
            for(y=0;y<480;y++)
            {
                k=0;
                for(i=0;i<n;i++)
                {
                    if(((y1[i]<=y)&&(y1[i+1]>y)) || ((y1[i]>y)&&(y1[i+1]<=y)))
                    {
                        xi[k]=(int)(x1[i]+m[i]*(y-y1[i]));
                        k++;
                    }
                }

                for(i=0;i<k-1;i++)
                {
                    for(j=0;j<k-1;j++)
                    {
                        if(xi[j]>xi[i+1])
                        {
                            temp=xi[j];
                            xi[j]=xi[j+1];
                            xi[j+1]=temp;
                        }
                    }
                }

                setcolor(14);
                for(i=0;i<k;i+=2)
                {
                    drawline(xi[i],y,xi[i+1]+1,y);
                }
                delay(20);
            }
        }
};

int main()
{
    int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
    polygon p;
    p.scanfill();
    getch();
    closegraph();
    return 0;
}

/*
Input:
Number of sides of the polygon.
Coordinates for each vertex of the polygon.


Console Output Example:
Enter the Number of Sides of Polygon: 4
Enter the x & y Coordinates: 50
50
Enter the x & y Coordinates: 150
50
Enter the x & y Coordinates: 150
150
Enter the x & y Coordinates: 50
150


Output Image: CGA1_scanfill.png
*/



