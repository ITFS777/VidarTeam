#include <stdio.h>
#include <stdlib.h>
//////////////////////////////////////////////////////////////////////////
typedef struct people
{
    struct people *last;
    struct people *next;
    int name;
} people;
//////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{
    int count = 0, N = 0, M = 0, i = 0;
    scanf(" %d %d %d", &count, &N, &M);
    people *peo = (people *)calloc(count, sizeof(people));
    people *p = NULL;

    for (i = 0; i < count; i++)
    {
        peo[i].name = i;
        if (i == (count - 1))
            peo[i].next = &peo[0];
        else
            peo[i].next = &peo[i + 1];
        if (i == 0)
            peo[i].last = &peo[count - 1];
        else
            peo[i].last = &peo[i - 1];
    }

    p = peo;

    while (count >= N)
    {
        for (i = 0; i < (N - 1); i++)
            p = p->next;

        p->last->next = p->next;
        p->next->last = p->last;
        p = p->next;

        count--;
    }

    for (i = 0; i < count; i++)
    {
        if (p->name != (M - 1))
            p = p->next;
        else
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");

    return 0;
}