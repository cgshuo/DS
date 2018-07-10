#include <stdio.h>
#include <malloc.h>

//节点
typedef struct tag_node
{
    struct tag_node *prev;
    struct tag_node *next;
    void *p;
}node;

//表头（不放数据
static node *phead=NULL;
//节点个数
static int count=0;

static node* create_node(void *pval)
{
    node *pnode = NULL;
    pnode = (node *)malloc(sizeof(node));
    if(!pnode)//如果pnode 为假
    {
        printf("create node error!\n");
        return NULL;
    }
    pnode->prev = pnode->next = pnode;
    pnode->p = pval;
    return pnode;
}
int create_dlink()
{
    phead = create_node(NULL);
    if(!phead)
        return -1;
    count = 0;
    return 0;
}

int dlink_is_empty()
{
    return count == 0;
}

int dlink_size()
{
    return count;
}

static node* get_node(int index)
{
    if(index < 0 || index >= count)
    {
        printf("%s failed! index out of bound!\n", __func__);
        return NULL;
    }

    //正向查找
    if(index <= (count/2))
    {
        int i = 0;
        node *pnode=phead->next;
        while((i++) < index)
            pnode = pnode->next;
        return pnode;
    }

    //反向查找
    int j = 0;
    int rindex = count - index -1;
    node *rnode = phead->prev;
    while((j++) < rindex)
        rnode = rnode->prev;
    return rnode;
}

static node* get_first_node()
{
    return get_node(0);
}

static node* get_last_node()
{
    return get_node(count-1);
}

// 获取“双向链表中第index位置的元素”。成功，返回节点值；否则，返回-1。
void* dlink_get(int index)
{
    node *pindex = get_node(index);
    if(!pindex)
    {
        printf("%s failed!\n",__func__);
        return NULL;
    }
    return pindex->p;
}

void* dlink_get_first()
{
    return dlink_get(0);
}

void* dlink_get_last()
{
    return dlink_get(count-1);
}

int dlink_insert(int index, void* pval)
{
    if(index == 0)
    {
        return dlink_insert_first(pval);
    }

    node *pindex = get_node(index);
    if(!pindex)
        return -1;

    node *pnode = create_node(pval);
    if(!pnode)
        return-1;

    pnode->prev = pindex->prev;
    pnode->next = pindex;
    pindex->prev->next = pnode;
    pindex->prev = pnode;

    count++;

    return 0;
}

int dlink_insert_first(void *pval)
{
    node *pnode = create_node(pval);
    if(!pnode)
        return -1;

    pnode->prev = phead;
    pnode->next = phead->next;
    phead->next->prev = pnode;
    phead->next = pnode;

    count++;

    return 0;
}

int dlink_append_last(void *pval)
{
    node *pnode = create_node(pval);
    if(!pnode)
        return -1;

    pnode->next = phead;
    pnode->prev = phead->prev;
    phead->prev->next = pnode;
    phead->prev = pnode;

    count++;

    return 0;
}

int dlink_delete(int index)
{
    node *pindex = get_node(index);
    if(!pindex)
    {
        printf("%s failed! the index  out of bound\n", __func__);
        return -1;
    }

    pindex->next->prev = pindex->prev;
    pindex->prev->next = pindex->next;
    free(pindex);

    count--;

    return 0;
}

int dlink_delete_first()
{
    return dlink_delete(0);
}

int dlink_delete_last()
{
    return dlink_delete(count-1);
}

int destroy_dlink()
{
    if(!phead)
    {
        printf("%s failed! dlink is null!\n", __func__);
        return -1;
    }

    node *pnode = phead->next;
    node *ptmp = NULL;
    while(pnode != phead)
    {
        ptmp = pnode;
        pnode = pnode->next;
        free(ptmp);
    }
    free(phead);
    phead = NULL;
    count = 0;
    return 0;
}
















