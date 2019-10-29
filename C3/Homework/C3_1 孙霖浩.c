#include <stdio.h>
#include <string.h>
struct student
{
    int id;
    char name[12];
    struct student *next;
};
int main()
{
    struct student a;
    a.id = 10;
    strcpy(a.name, "FangRuiXin");
    a.next = &a;
    int *p = (int *)&a;
    char *pa = (char *)&a;
    int *pStudent = (int *)&a + 4;
    printf("%d\n", *p);
    printf("%s\n", pa + sizeof(int));
    printf("%x\n", *pStudent);
    printf("%p", &a);
}
