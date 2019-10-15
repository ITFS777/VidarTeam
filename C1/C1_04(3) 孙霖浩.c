#include <stdio.h>
#include <math.h>
#include <windows.h>
#define SIZE 1.5
#define ARGUMENT_1 0.1
#define ARGUMENT_2 0.04
//////////////////////////////////////////////////////////////////////////
double heart(double x, double y);
//////////////////////////////////////////////////////////////////////////
int main(void)
{
    double y = 0, x = 0, min = 0;

    for (y = SIZE; y >= -SIZE; y-=ARGUMENT_1)
    {
        for (x = -SIZE; x <= SIZE; x+=ARGUMENT_2)
        {
            if (heart(x, y) <= 1)
                putchar('*');
            else
                putchar(' ');
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
//////////////////////////////////////////////////////////////////////////
double heart(double x, double y)
{
    return (pow( (double)x, 2.0) + pow( (double)( (double)y - pow( (double)(x * x) , (double)(1.0 / 3.0) ) ), 2.0));
}
