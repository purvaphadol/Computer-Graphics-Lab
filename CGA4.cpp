/*
CG Assignment-4

Name: Purva Gorakh Phadol
SE Computer
Div: B
Roll No: 49
Date: 9/11/22

Que. Write C++ program to draw 2-D object and perform following basic transformations,
a) Scaling
b) Translation 
c) Rotation. 
Apply the concept of operator overloading.
*/

#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class transform
{
	public:
		int m,a[20][3],c[20][3];
		int i,j,k;
		public:
			
		void object();
		void accept();
		void operator *(float b[20][3])
		{
			for(int i=0;i<m;i++)
			{
				for(int j=0;j<3;j++)
				{
					c[i][j]=0;
					for(int k=0;k<3;k++)
					{
						c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
					}
				}
			}
		}
};

void transform::object()
{
	float xmax,ymax;
    xmax=getmaxx();
    ymax=getmaxy();
    xmax=xmax/2;
    ymax=ymax/2;

    setcolor(WHITE);
    i=0;
    while(i<m-1)
    {
        line(xmax+a[i][0],ymax-a[i][1],xmax+a[i+1][0],ymax-a[i+1][1]);
        i++;
    }
    i=m-1;
    line(xmax+a[i][0],ymax-a[i][1],xmax+a[0][0],ymax-a[0][1]);
    
    setcolor(BLUE);
    i=0;
    while(i<m-1)
    {
        line(xmax+c[i][0],ymax-c[i][1],xmax+c[i+1][0],ymax-c[i+1][1]);
        i++;
    }
    i=m-1;
    line(xmax+c[i][0],ymax-c[i][1],xmax+c[0][0],ymax-c[0][1]);

    setcolor(YELLOW);
    line(0,ymax,xmax*2,ymax);
    line(xmax,0,xmax,ymax*2);
}

void transform::accept()
{
	cout<<"Enter number of vertices: ";
    cin>>m;
    for(i=0;i<m;i++)
	{
        cout<<"Enter co-ordinates of vertices "<<i+1<<" : ";
        cin>>a[i][0]>>a[i][1];
        a[i][2]=1;
    }
}

int main()
{
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	int ch,tx,ty,sx,sy;
	float deg,theta,b[20][3];
	transform t;
	t.accept();
	do
	{
	    cout<<"\n\n\t----- MENU -----\n\t1.Translation \n\t2.Scaling \n\t3.Rotation \n\t4.Exit \n\t----------------";
	    cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
            case 1: cout<<"\nTRANSLATION OPERATION\n";
                    cout<<"Enter value for tx and ty: ";
                    cin>>tx>>ty;
				    cleardevice();
                    b[0][0]=b[2][2]=b[1][1]=1;
                    b[0][1]=b[0][2]=b[1][0]=b[1][2]=0;
                    b[2][0]=tx;
                    b[2][1]=ty;
                    t * b;
                    t.object();
                    delay(100);
                    break;

            case 2: cout<<"\nSCALING OPERATION\n";
                    cout<<"Enter value for sx and sy: ";
                    cin>>sx>>sy;
                    cleardevice();
                    b[0][0]=sx;
                    b[1][1]=sy;
                    b[0][1]=b[0][2]=b[1][0]=b[1][2]=0;
                    b[2][0]=b[2][1]=0;
                    b[2][2] = 1;
                    t * b;
                    t.object();
                    delay(100);
                    break;

            case 3: cout<<"\nROTATION OPERATION\n";
                    cout<<"Enter value for angle: ";
                    cin>>deg;
                    cleardevice();
                    theta=deg*(3.14/180);
                    b[0][0]=b[1][1]=cos(theta);
                    b[0][1]=sin(theta);
                    b[1][0]=sin(-theta);
                    b[0][2]=b[1][2]=b[2][0]=b[2][1]=0;
                    b[2][2]=1;
                    t * b;
                    t.object();
                    delay(100);
                    break;
            
            case 4: cout<<"\nExit\n";
                    exit(0);
                    break;

            default:
                cout<<"\nInvalid choice"<<endl;
		}
	}
	while(ch!=4);
    getch();
    closegraph();
    return 0;    
}

/*
Input:
Number of vertices and their coordinates.
Transformation parameters (e.g., scaling factors, translation distances, rotation angle).


Console Output Example:
Enter number of vertices: 3
Enter co-ordinates of vertices 1 : 30
30
Enter co-ordinates of vertices 2 : 70
50
Enter co-ordinates of vertices 3 : 50
80


        ----- MENU -----
        1.Translation
        2.Scaling
        3.Rotation
        4.Exit
        ----------------
Enter your choice: 1

TRANSLATION OPERATION
Enter value for tx and ty: 20
22


        ----- MENU -----
        1.Translation
        2.Scaling
        3.Rotation
        4.Exit
        ----------------
Enter your choice: 2

SCALING OPERATION
Enter value for sx and sy: 1
2


        ----- MENU -----
        1.Translation
        2.Scaling
        3.Rotation
        4.Exit
        ----------------
Enter your choice: 3

ROTATION OPERATION
Enter value for angle: 150


        ----- MENU -----
        1.Translation
        2.Scaling
        3.Rotation
        4.Exit
        ----------------
Enter your choice: 5

Invalid choice


        ----- MENU -----
        1.Translation
        2.Scaling
        3.Rotation
        4.Exit
        ----------------
Enter your choice: 4

Exit

Output Images:
1.CGA4_Translation.png
2.CGA4_Scaling.png
3.CGA4_Rotation.png
*/

