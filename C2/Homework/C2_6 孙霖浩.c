#include <stdio.h>
struct myClass
{
    int num;
    void (*func)(struct myClass);
};
void printNum(struct myClass this)
{
    printf("%d\n", this.num);
}
int main()
{
    struct myClass test;
    test.num = 23333;
    test.func = printNum;
    test.func(test);
}