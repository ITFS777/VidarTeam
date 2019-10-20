//在第三道题中，形参的声明为
(const char *s1, const char *s2)
//这表明s1和s2指向的地址的值是const char类型，因此指向的地址的值无法被改变
//但s1和s2都是char类型的指针，其值都是可以改变的
//可以总结出以下结构
(指针指向的数据类型) * <指针类型> (指针名)
//若要实现s1、s2以及其指向的地址均无法被改变，则应该用如下声明
(const char * const s1,const char * const s2)