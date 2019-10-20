#include <stdio.h>
int getElement(int *a, int b, int c)
{
    return *(a+b*16+c);
}
int main()
{
    int a[16][16] = {0};
    int b, c;
    scanf_s("%d %d", &b, &c);
    printf("%d\n", getElement((int *)a, b, c));
    return 0;
} 