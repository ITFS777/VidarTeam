#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>
//////////////////////////////////////////////////////////////////////////
typedef struct list
{
    char *var_name;
    double value;
    struct list *last;
    struct list *next;
} var;
typedef union item_t {
    double *num;
    char *var;
} item_t;
//////////////////////////////////////////////////////////////////////////
bool get_item(item_t *item, char *symbol, unsigned int *item_c, unsigned int *symbol_c);
int get_type(char ch);
item_t *add_item(item_t *item, unsigned int length);
char *get_var_name(char *var_name);
void skip_space(void);
bool is_var(char ch);
bool is_num(char ch);
bool is_symbol(char ch);
//////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{
    unsigned int item_c = 0, symbol_c = 0;
    int i = 0, j = 0;
    char *symbol = (char *)calloc(1, sizeof(char));     //符号表
    item_t *item = (item_t *)calloc(1, sizeof(item_t)); //项表

    if (get_item(item, symbol, &item_c, &symbol_c)) //赋值表达式
    {
    }
    else //计算表达式
    {
        for (i = 0; i < item_c; i++)
            printf("%s ", item[i]);
        for (i = 0; i < symbol_c; i++)
            printf("%c ", symbol[i]);
    }
    free(symbol);
    free(item);
    return 0;
_command:

_error:
    printf("unknown error!\n");
    system("pause");
    return 0;
}
//////////////////////////////////////////////////////////////////////////
bool get_item(item_t *item, char *symbol, unsigned int *item_c, unsigned int *symbol_c)
{ //item为项表，下标i;symbol为符号表，下标j;
    double tmp = 0;

    *item_c = 0;    //初始化项计数
    *symbol_c = 0;  //初始化符号计数

    bool assign = false; //是否为赋值表达式

    while (1)   //循环读取项
    {
        skip_space();        //跳过可能存在的空格
        char ch = getchar(); //读取当前项首字符

        switch (get_type(ch))
        {
        case 1: //变量
            ungetc(ch, stdin);
            if ((*item_c) > 0)
                add_item(item, *item_c);
            item[*item_c].var = (char *)calloc(1, sizeof(char));
            get_var_name(item[*item_c].var);
            (*item_c)++;
            break;
        case 2: //数值
            ungetc(ch, stdin);
            if ((*item_c) > 0)
                add_item(item, *item_c);
            item[*item_c].num=(double*)calloc(1, sizeof(double));
            scanf(" %lf", item[*item_c].num);
            (*item_c)++;
            break;
        case 3: //符号
            ungetc(ch, stdin);
            if ((*symbol_c) > 0)
                symbol = realloc(symbol, ((*symbol_c)+1) * sizeof(char));
            symbol[*symbol_c] = getchar();
            (*symbol_c)++;
            break;
        case 4: //赋值
            assign = true;
            return assign;
        case 6: //结束
            return assign;
        default:
            return assign;
        }
    }
}
//////////////////////////////////////////////////////////////////////////
int get_type(char ch)
{
    if (is_var(ch))
        return 1; //变量
    else if (is_num(ch))
        return 2; //数值
    else if (is_symbol(ch))
        return 3; //运算
    else if (ch == '=')
        return 4; //赋值
    else if (ch == '#')
        return 5; //命令
    else if (ch == '\n')
        return 6; //换行
    else
        return 0; //非法输入
}
//////////////////////////////////////////////////////////////////////////
item_t *add_item(item_t *item, unsigned int length)
{
    item = realloc(item, (length + 1) * sizeof(item_t));
    if (item == NULL)
        return NULL;
    else
        return item;
}
//////////////////////////////////////////////////////////////////////////
char *get_var_name(char *var_name)
{
    int i = 0;
    char ch = 0;
    while (is_var(ch = getchar()))
    {
        var_name[i++] = ch;
        var_name = realloc(var_name, (i + 1) * sizeof(char));
        if (var_name == NULL)
            return NULL;
        var_name[i] = '\0';
    }
    ungetc(ch, stdin);
    return var_name;
}
//////////////////////////////////////////////////////////////////////////
void skip_space(void)
{
    char ch = 0;
    while ((ch = getchar()) == ' ')
        ;
    ungetc(ch, stdin);
}
//////////////////////////////////////////////////////////////////////////
bool is_var(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch == '_') || (ch == '$'))
        return true;
    else
        return false;
}
//////////////////////////////////////////////////////////////////////////
bool is_num(char ch)
{
    if (ch >= '0' && ch <= '9' || ch == '.')
        return true;
    else
        return false;
}
//////////////////////////////////////////////////////////////////////////
bool is_symbol(char ch)
{
    if ((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/'))
        return true;
    else
        return false;
}