#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{
    int left = 0, right = 0, i = 0, maxlength = 0, count = 0, maxloc = 0;
    char ch = 0;

    while (1)
    {
        char *str = (char *)calloc(1, sizeof(char));
        memset(str, '\0', 1 * sizeof(char));

        for (i = 0; (ch = getchar()) != '\n';)
        {
            str[i] = ch;
            i++;
            str = realloc(str, (i + 1) * sizeof(char));
            if (str == NULL)
                return 0;
            str[i] = '\0';
        }

        for (i = 0, maxlength = 0, maxloc = 0; i < strlen(str); i++)
        {
            for (left = (i - 1), right = (i + 1), count = 0; (left >= 0) && (right < strlen(str)); left--, right++)
            {
                if (str[left] == str[right])
                    count++;
                else
                    break;
            }

            if (maxlength < count)
            {
                maxlength = count;
                maxloc = i;
            }
        }

        for (i = (maxloc - maxlength); i <= (maxloc + maxlength); i++)
            putchar(str[i]);
        printf("\n");

        free(str);
    }
    return 0;
}
