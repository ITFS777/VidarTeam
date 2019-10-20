#include <stdio.h>
#define ARGUMENT 0.1
//////////////////////////////////////////////////////////////////////////
int circle(int x, int y, int r);
//////////////////////////////////////////////////////////////////////////
int main(void)
{
    int r = 0, y = 0, x = 0, min = 0;
    while (~scanf(" %d", &r))
    {
        /*for (y = -(r+(r/2)); y <= (r+(r/2)); y+=2)*/
        for (y = -r; y <= r; y += 2)
        {
            for (x = 0, min = 0; x <= r; x++)
            {
                if (circle(min, y, r) > circle(x, y, r))
                    min = x;
            }
            for (x = -r; x <= r; x++)
            /*for (x = -(r + (r / 2)); x <= (r + (r / 2)); x++)*/
            {
                if (x == min || x == -min)
                    /*if (circle(x, y, r) <= ((r*r)*ARGUMENT))*/
                    putchar('*');
                else
                    putchar(' ');
            }
            printf("\n");
        }
    }
    return 0;
}
//////////////////////////////////////////////////////////////////////////
int circle(int x, int y, int r)
{
    if (y < 0)
        y = -y;
    if (((x * x) + (y * y) - (r * r)) >= 0)
        return ((x * x) + (y * y) - (r * r));
    else
        return -((x * x) + (y * y) - (r * r));
}