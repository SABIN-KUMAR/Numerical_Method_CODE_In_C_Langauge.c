#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>

float E=0.00001;
float functionRun(float x)
{
    return(x*(exp(x))-2);
}

int main()
{
    float abscheck,firstvalue,secondvalue,midvalue;
    int step=0;
    cheaker:
    printf("Enter the two initial values:\n");
    scanf("%f %f",&firstvalue,&secondvalue);
    float firstfunc,secondfunc,midfunc;
    firstfunc=functionRun(firstvalue);
    secondfunc=functionRun(secondvalue);

    if(firstfunc*secondfunc>0)
    {
        printf("Error values:");
        goto cheaker;
    }
     printf("\n|Step  |  iteration value|\n");
    do
    {
        midvalue=(firstvalue+secondvalue)/2;
        midfunc=(functionRun(midvalue));
        if(midfunc*firstfunc<0)
        {
            secondvalue=midvalue;
            secondfunc=midfunc;
        }
        else
        {
            firstfunc=midfunc;
            firstvalue=midvalue;
        }
        step=step+1;
       
        printf("| %d    |         %f|\n",step,midvalue);
    }
    while(fabs(functionRun(midvalue))>E);
   
    getch();
    return 0;
}