#include <stdio.h>
#include "double_link.h"

//C语言 双向链表实现栈

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

//返回栈顶元素值
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

    // 创建“栈”
    create_dlink_stack();

    // 将10, 20, 30 依次推入栈中
    int i=0;
    for (i=0; i<ARR_STU_SIZE-1; i++)
    {
        push(&arr_stu[i]);
    }

    // 将“栈顶元素”赋值给pval，并删除“栈顶元素”
    pval = (stu*)pop();
    //print_stu(pval) ;

    // 只将“栈顶”赋值给pval，不删除该元素.
    pval = peek();
    //print_stu(pval) ;

    push(&arr_stu[ARR_STU_SIZE-1]);


    // 打印栈中的所有元素
    while (!is_empty())
    {
        pval = pop();
        print_stu(pval) ;
    }

    // 销毁栈
    destroy_dlink_stack();
}


















