#include <stdio.h>
#include "double_link.h"

//╤сап

int create_dlink_queue()
{
    return create_dlink();
}

int destroy_dlink_queue()
{
    return destroy_dlink();
}
int add(void *p)
{
    return dlink_append_last(p);
}

void* front()
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
