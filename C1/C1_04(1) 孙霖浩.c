#include <stdio.h>

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
int main(void)
{
    int length = 0, h = 0, y = 0, x = 0;
    while (~scanf(" %d", &length))
    {
        h = ((length / 2) + 1);

        for (y = 0; y < h; y++)
        {
            for (x = 0; x < length; x++)
            {
                if (x >= (((length - 1) / 2) - y) && x <= (((length - 1) / 2) + y))
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
