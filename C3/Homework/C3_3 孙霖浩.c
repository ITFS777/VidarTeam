#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>
#define NOTEST
//////////////////////////////////////////////////////////////////////////
typedef struct list
{
    char *var_name;
    double value;
    struct list *last;
    struct list *next;
} var;
//////////////////////////////////////////////////////////////////////////
struct list *add_var(struct list *p);
void del_var(struct list *p);
struct list *search_var(struct list *p, char *var_name);
void print_allvar(struct list *p);
void del_allvar(struct list *p);
char *get_string(char *str);
char *get_name(char *str);
int get_type(char ch);
void skip_space();
//////////////////////////////////////////////////////////////////////////
#ifdef NOTEST
int main(int argc, char *argv[])
{
    char flag = 0, ch = 0;

    int var_count = 0, i = 0;

    double tmp_value = 0.0;

    var *head = NULL;
    var *pvar = NULL;
_get_exp:
    char *exp = (char *)calloc(1, sizeof(char));
    if (get_string(exp) == NULL) //错误处理
        goto _error;

_judge_type:

    skip_space(exp, &i);
    switch (get_type(exp, &i)) //判断当前项类型
    {
    case 0: //非法输入

        printf("error input!\n");
        fflush(NULL);
        goto _get_exp;

    case 1: //变量

        //临时存储变量名
        char *tmp_varname = (char *)calloc(1, sizeof(char));
        if (get_name(exp, tmp_varname, &i) == NULL) //错误处理
            goto _error;

        if (search_var(head, tmp_varname) == NULL) //声明变量
        {
            if (var_count == 0)
            {
                head = add_var(head);
                pvar = head;
            }
            else
                pvar = add_var(pvar);
            //将临时变量名存储在链表中
            pvar->var_name = (char *)calloc(strlen(tmp_varname) + 1, sizeof(char));
            strncpy(pvar->var_name, tmp_varname, strlen(tmp_varname) + 1);
            var_count++;
        }
        free(tmp_varname);
        tmp_value = pvar->var_value; //暂存表达式的值
        goto _judge_type;

    case 2: //数值

        scanf(" %lf", &tmp_value);
        goto _judge_type;

    case 3: //运算

        tmp_value = opera(tmp_value, exp, &i, head);
        goto _judge_type;

    case 4: //赋值

        search_var(head, tmp_varname)->value = opera(tmp_value, exp, &i, head);
        goto _get_exp;

    case 5: //命令

    case 6: //结束
        break;
    default:
        goto _error;
    }
    printf("%lf\n", tmp_value);
_var:

    //判断变量操作类型
    switch (get_type(exp, &i))
    {
    case 0: //非法输入
        printf("error input!\n");
        goto _judge_type;
    case 4: //赋值
        skip_space();

        else pvar = search_var(head, tmp_varname); //查找变量

        pvar->value = get_value(); //变量赋值
        break;
    case 5:                                   //打印变量值
        pvar = search_var(head, tmp_varname); //查找变量
        if (pvar == NULL)                     //错误处理
        {
            printf("unknown var!\n");
            goto _judge_type;
        }
        else //打印变量
            printf("%lf\n", pvar->value);
        break;
    default:
        goto _error;
    }

    return 0;
_error:
    printf("unknown error!\n");
    system("pause");
    return 0;
}
#endif
//////////////////////////////////////////////////////////////////////////
#ifdef TEST
int main(int argc, char *argv[])
{

    return 0;
}
#endif
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
struct list *add_var(struct list *p)
{
    struct list *list = (struct list *)calloc(1, sizeof(struct list));
    list->value = 0.0;
    list->last = p;
    list->next = NULL;
    return list;
}
//////////////////////////////////////////////////////////////////////////
void del_var(struct list *p)
{
    p->last->next = p->next;
    p->next->last = p->last;
    free(p);
}
//////////////////////////////////////////////////////////////////////////
struct list *search_var(struct list *p, char *var_name)
{
    do
    {
        if (strcmp(var_name, p->var_name) == 0)
            return p;
        else
            p = p->next;
    } while (p != NULL);
    return NULL;
}
//////////////////////////////////////////////////////////////////////////
void print_allvar(struct list *p)
{
    do
    {
        printf("%s : %lf\n", p->var_name, p->value);
        p = p->next;
    } while (p != NULL);
}
//////////////////////////////////////////////////////////////////////////
void del_allvar(struct list *p)
{
    while (p->next != NULL)
    {
        p = p->next;
        free(p->last);
    }
    free(p);
}
//////////////////////////////////////////////////////////////////////////
char *get_string(char *str)
{
    int i = 0;
    char ch = 0;
    for (i = 0; (ch = getchar()) != '\n'; /*void*/)
    {
        str[i] = ch;
        i++;
        str = realloc(str, (i + 1) * sizeof(char));
        if (str == NULL)
            return NULL;
        str[i] = '\0';
    }
    return str;
}
//////////////////////////////////////////////////////////////////////////
char *get_name(char *exp, char *str, int *i)
{
    int j = 0;
    while (exp[*i] != ' ')
    {
        str[j] = exp[*i];
        (*i)++;
        j++;
        str = realloc(str, (j + 1) * sizeof(char));
        if (str == NULL)
            return NULL;
        str[j] = '\0';
    }
    return str;
}
//////////////////////////////////////////////////////////////////////////
int get_type(char *exp, int *i)
{
    if ((exp[*i] >= 'a' && exp[*i] <= 'z') || (exp[*i] >= 'A' && exp[*i] <= 'Z') || (exp[*i] == '_') || (exp[*i] == '$'))
        return 1; //变量
    else if (exp[*i] >= '0' && exp[*i] <= '9' || exp[*i] == '.')
        return 2; //数值
    else if ((exp[*i] == '+') || (exp[*i] == '-') || (exp[*i] == '*') || (exp[*i] == '/'))
        return 3; //运算
    else if (exp[*i] == '=')
    {
        (*i)++;
        return 4; //赋值
    }
    else if (exp[*i] == '#')
    {
        (*i)++;
        return 5; //命令
    }
    else if (exp[*i] == '\n')
        return 6; //换行
    else
        return 0; //非法输入
}
//////////////////////////////////////////////////////////////////////////
void skip_space(char *exp, int *i)
{
    while (exp[*i] == ' ')
        (*i)++;
}
//////////////////////////////////////////////////////////////////////////
double opera(double value, char *exp, int *i, struct list *head)
{
    skip_space(exp, i);
    switch (exp[*i])
    {
    case '+':
        (*i)++;
        skip_space(exp, i);
        switch (get_type(exp[*i]))
        {
        case 1:
            //临时存储变量名
            char *tmp_varname = (char *)calloc(1, sizeof(char));
            if (get_name(exp, tmp_varname, i) == NULL) //错误处理
                goto _error;
            value += search_var(head, tmp_varname)->value;
            free(tmp_varname);
            break;
        case 2:
            value += strtod(exp, &exp); //读取字符串中的浮点数
            *i = 0;
            break;
        case 6:
            return value; //判断表达式结尾
        case 0:
        default:
            printf("error input!\n");
            fflush(NULL);
            return value;
        }
        return opera(value, exp, i, head); //嵌套调用，往后计算表达式
    case '-':
        (*i)++;
        skip_space(exp, &i);
        switch (get_type(exp[i]))
        {
        case 1:
            //临时存储变量名
            char *tmp_varname = (char *)calloc(1, sizeof(char));
            if (get_name(exp, tmp_varname, &i) == NULL) //错误处理
                goto _error;
            value -= search_var(head, tmp_varname)->value;
            free(tmp_varname);
            break;
        case 2:
            value -= strtod(exp, &exp); //读取字符串中的浮点数
            *i = 0;
            break;
        case 6:
            return value;
        case 0:
        default:
            printf("error input!\n");
            fflush(NULL);
            return value;
        }
        return opera(value, exp, i, head);
    case '*':
        (*i)++;
        skip_space(exp, &i);
        switch (get_type(exp[i]))
        {
        case 1:
            //临时存储变量名
            char *tmp_varname = (char *)calloc(1, sizeof(char));
            if (get_name(exp, tmp_varname, &i) == NULL) //错误处理
                goto _error;
            value *= search_var(head, tmp_varname)->value;
            free(tmp_varname);
            break;
        case 2:
            value *= strtod(exp, &exp); //读取字符串中的浮点数
            *i = 0;
            break;
        case 6:
            return value;
        case 0:
        default:
            printf("error input!\n");
            fflush(NULL);
            return value;
        }
        return opera(value, exp, i, head);
    case '/':
        (*i)++;
        skip_space(exp, &i);
        switch (get_type(exp[i]))
        {
        case 1:
            //临时存储变量名
            char *tmp_varname = (char *)calloc(1, sizeof(char));
            if (get_name(exp, tmp_varname, &i) == NULL) //错误处理
                goto _error;
            value /= search_var(head, tmp_varname)->value;
            free(tmp_varname);
            break;
        case 2:
            value /= strtod(exp, &exp); //读取字符串中的浮点数
            *i = 0;
            break;
        case 6:
            return value;
        case 0:
        default:
            printf("error input!\n");
            fflush(NULL);
            return value;
        }
        return opera(value, exp, i, head);
    }
}
//////////////////////////////////////////////////////////////////////////
bool is_newvar(struct list *p, char *var_name)
{
    do
    {
        if (!strcmp(p->var_name, var_name))
            return p;
        else
            p = p->next;
    } while (p != NULL);
    return NULL;
}