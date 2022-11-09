#include<stdio.h>
#include<math.h>

float f(float x)
{
    return 3*x-cos(x)-1;
}
float g(float x)
{
    return 3+sin(x);
}

int main()
{
    float x0,x1,xn,e;
    float y0,y1;
    int steps=1;                                          // Changed in This
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
        float x2=(x0+x1)/2.0;
        float root;
        do
        {
            xn=x2-(f(x2)/g(x2));
            printf("%d %f %f\n",steps,x2,xn);
            root=x2;
            x2=xn;
            steps++;
        }while(xn-root>=e);
        printf("\nRoot is: %f\n",xn);
    }
}
