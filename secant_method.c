#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>

float f(float x,int y)
{
    if(y==0)
    {
        return(pow(x,2)-4*x-10);
    }
    if(y==1)
    {
        return(4*sin(x)-exp(x));
    }
}

float calc(int y)
{
    float R1,R2,R0,f1,f2,f0,E=0.0001,p;
    int step;
    step=1;
    printf("Enter the first and second initial roots:\n");
    scanf("%f %f",&R0,&R1);
    printf("|step  |  x0  |  x1  |  x2  |\n");
    do
    {
        f0=f(R0,y);
        f1=f(R1,y);
        R2=R1-((R1-R0)/(f1-f0))*f1;
        printf("| %d   |%f  |%f  |%f  |\n",step,R0,R1,R2);
        R0=R1;
        R1=R2;
        p=((R2-R1)/R2);
        step=step+1;

    } while (fabs(p)>E);
    printf("| %d   |%f  |%f  |%f  |\n",step,R0,R1,R2);
    printf("The roots is %f.\n",R2); 
}

int main()
{
    printf("For the x^2-4x-10:\n");
    calc(0);
    printf("\n\nFor the 4sin(x)-e^x:\n");
    calc(1);
    return 0;
}