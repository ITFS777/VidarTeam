int main()
{
    const char *str1 = "Hello, World!";
    char str2[] = "Hello, World!";
}
//在第3行的声明中，"Hello,World!"表示的是一个存储在静态存储区(static)的字符串面量(const型零尾字符数组)的首地址
//char型指针str1指向的是其首地址
//str1可以像一般的字符数组一样用下标访问字符串的各个字符，但不能像一般的字符数组一样修改(因为其指向的是const空间)
//因为字符串面量是静态存储的，出于节省空间的考虑，当有
const char *str3 = "Hello, World!";
//这样的声明时，有
(str1 == str3)

//第4行的声明的作用是将字符串面量"Hello, World!"赋值给字符数组str2，且str2的大小即为"Hello, World!"的大小
//str2的值是一个值为{'H','e','l','l','o',',','W','o','r','l','d','!','\0'}的字符数组的首地址
//字符数组str2储存在栈上，可以使用下标进行访问和修改