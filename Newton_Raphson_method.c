#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>

float f(float x,int y)
{
    if(y==0)
    {
        return(x*tan(x)-1);
    }
    if(y==1)
    {
        return(x*pow(1/cos(x),2)+tan(x));
    }
    if(y==2)
    {
        return(3*x+exp(x));
    }
    if(y==3)
    {
        return(3+exp(x));
    }
}

float calc(int y)
{
    float R1,R0,f1,f0,E=0.0001,p;
    int step;
    step=0;
    printf("Enter the initial roots:\n");
    scanf("%f",&R0);
    printf("|step    |    xn    |    xn+1    |\n");
    do
    {
        f0=f(R0,y);
        f1=f(R0,y+1);
        R1=R0-(f0/f1);
       step=step+1;
       printf("|  %d   |  %f   |  %f  |\n",step,R0,R1);
       p=(R1-R0)/R1;
       R0=R1;

    } while (fabs(p)>E);
    printf("The roots is %f.\n",R1); 
}

int main()
{
    printf("For x*tanx-1:\n");
    calc(0);
    printf("\n\nFor 3x+e^x:\n");
    calc(2);
    getch();
    return 0;
}