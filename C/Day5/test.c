/***************************************************
 * Date:2024/10/12
1���ṹ��
***************************************************/

#include <stdio.h>

struct Stu // ����ṹ�壺ѧ�� ��ռ�ռ�
{
    /* ��Ա���� */
    char name[20];
    int age;
    char sex[10];
    char tele[12];
};

void print(struct Stu* ps)
{
    printf("%s %d %s %s\n", (*ps).name, (*ps).age, (*ps).sex, (*ps).tele);
    // ->
    // �ṹ��ָ����� -> ��Ա��
    printf("%s %d %s %s\n", ps->name, ps->age, ps->sex, ps->tele); // psָ��ָ������ĳ�Ա
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
