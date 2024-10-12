/***************************************************
 * Date:2024/10/12
1）结构体
***************************************************/

#include <stdio.h>

struct Stu // 定义结构体：学生 不占空间
{
    /* 成员变量 */
    char name[20];
    int age;
    char sex[10];
    char tele[12];
};

void print(struct Stu* ps)
{
    printf("%s %d %s %s\n", (*ps).name, (*ps).age, (*ps).sex, (*ps).tele);
    // ->
    // 结构体指针变量 -> 成员名
    printf("%s %d %s %s\n", ps->name, ps->age, ps->sex, ps->tele); // ps指针指向变量的成员
}

int main()
{
    struct Stu s =
    {
        "zhangsan",
        20,
        "nan",
        "17600755720"
    };
    printf("%s %d %s %s\n", s.name, s.age, s.sex, s.tele);
    print(&s);
    return 0;
}
