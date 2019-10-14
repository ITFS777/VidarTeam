#include <stdio.h>

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
int main(void)
{
    int lim = 0, digit = 0, i = 0, tmp = 0, sub = 0;

    while (~scanf(" %d", &lim))
    {
        for (i = 100; i < lim; i++)
        {
            tmp = i;
            sub = 0;
            digit = 0;

            do
            {
                digit = (tmp % 10);
                sub += (digit * digit * digit);
                tmp /= 10;
            } while (tmp != 0);

            if (i == sub)
                printf("%d ", i);
        }
    }

    return 0;
}