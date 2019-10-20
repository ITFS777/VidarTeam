#include <stdio.h>
#include <string.h>
#pragma pack(push)   //默认分块大小入栈
#pragma pack(8)      //将结构体以8字节为单位对齐
typedef struct
{
char a;              //(char)大小为1字节，为了对齐8字节，其实际占用内存为8字节，即占用了额外7个字节的空间但并未使用
unsigned long long b;//(unsigned long long)大小为8字节，与分块大小一致，其实际占用内存也为8字节
} aaa;               //结构体的两个成员均为8字节对齐，因此整个结构体大小为16字节
#pragma pack(pop)    //默认分块大小出栈，内存对齐改为默认大小
int main()
{
aaa ddd;
printf("%ld %ld %ld\n", sizeof(ddd.a), sizeof(ddd.b), sizeof(ddd));
return 0;            //ddd.a为char类型，其大小为1字节；ddd.b为ULL类型，其大小为8字节；ddd为结构体类型，其大小为16字节
}
//struct
//{
//|char|0|0|0|0|0|0|0|
//|unsigned long long|
//}