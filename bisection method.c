#include<stdio.h>
#include<math.h>

float f(float x)
{
    return x*x*x-x*x+2;
}

int main()
{
    float x0,x1,x2,e;
    float y0,y1,y2;
    int steps=0;
    printf("Enter Initial Intervals: \n");
    scanf("%f %f",&x0,&x1);
    printf("Enter tolerable error: \n");
    scanf("%f",&e);
    y0=f(x0);
    y1=f(x1);
    if(y0*y1>=0)
        printf("Incorrect Guess\n");
    else
    {
        printf("Steps x0 x1 x2\n");
        do
        {
            x2=(x0+x1)/2.0;
            y2=f(x2);
            printf("%d %f %f %f\n",steps,x0,x1,x2);
            if(y2>0)
            {
                x1=x2;
            }
            else
            {
                x0=x2;
            }
            steps++;
        }while(x1-x0>=e);
        printf("\nRoot is: %f\n",x2);
    }
}
