#include<stdio.h>
#include<math.h>

float f(float x)
{
    return x-cos(x);
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
            x2=x0-((x1-x0)/(y1-y0))*y0;
            y2=f(x2);
            printf("%d %f %f %f\n",steps,x0,x1,x2);
            if(y2>0)
            {
                x1=x2;
                y1=y2;
            }
            else
            {
                x0=x2;
                y0=y2;
            }
            steps++;
        }while(x1-x0>=e);
        printf("\nRoot is: %f\n",x2);
    }
}

/*

Enter Initial Intervals:
-1 2
Enter tolerable error:
0.0001
Steps x0 x1 x2
0 -1.000000 2.000000 0.167943
1 0.167943 2.000000 0.631313
2 0.631313 2.000000 0.724214
3 0.724214 2.000000 0.737179
4 0.737179 2.000000 0.738844
5 0.738844 2.000000 0.739055
6 0.739055 2.000000 0.739081
7 0.739081 2.000000 0.739085
8 0.739085 2.000000 0.739085
9 0.739085 2.000000 0.739085

Root is: 0.739085

*/
