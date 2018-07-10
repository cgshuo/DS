#include <stdio.h>
#include "double_link.h"

//C���� ˫������ʵ��ջ

int create_dlink_stack()
{
    return create_dlink();
}

int destroy_dlink_stack()
{
    return destroy_dlink();
}

int push(void *p)
{
    return dlink_insert_first(p);
}

//����ջ��Ԫ��ֵ
void* peek()
{
    return dlink_get_first();
}

void* pop()
{
    void *p = peek();
    dlink_delete_first();
    return p;
}

int size()
{
    return dlink_size();
}

int is_empty()
{
    return dlink_is_empty();
}


//test
typedef struct stag_stu
{
    int id;
    char name[20];
}stu;

static stu arr_stu[] =
{
    {10, "sky"},
    {20, "jody"},
    {30, "vic"},
    {40, "dan"},
};

#define ARR_STU_SIZE ( (sizeof(arr_stu)) / (sizeof(arr_stu[0])) )


static void print_stu(stu *p)
{
    if(!p)
        return;
    printf("id = %d, name = %s\n", p->id, p->name);
}

void main()
{
    stu *pval=NULL;

    // ������ջ��
    create_dlink_stack();

    // ��10, 20, 30 ��������ջ��
    int i=0;
    for (i=0; i<ARR_STU_SIZE-1; i++)
    {
        push(&arr_stu[i]);
    }

    // ����ջ��Ԫ�ء���ֵ��pval����ɾ����ջ��Ԫ�ء�
    pval = (stu*)pop();
    //print_stu(pval) ;

    // ֻ����ջ������ֵ��pval����ɾ����Ԫ��.
    pval = peek();
    //print_stu(pval) ;

    push(&arr_stu[ARR_STU_SIZE-1]);


    // ��ӡջ�е�����Ԫ��
    while (!is_empty())
    {
        pval = pop();
        print_stu(pval) ;
    }

    // ����ջ
    destroy_dlink_stack();
}


















