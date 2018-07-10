#ifdef _DOUBLE_LINK_H
#define _DOUBLE_LINK_H

extern int create_dlink();
extern int destroy_dlink();
extern int dlink_is_empty();
extern int dlink_size();
extern void* dlink_get(int index);
extern void* dlink_get_first();
extern void* dlink_get_last();

//将value插入index位置，成功返回0，否则返回-1
extern int dlink_insert(int index, void *pval);

extern int dlink_insert_first(void *pval);
extern int dlink_append_last(void *pval);
extern int dlink_delete(int index);

extern int dlink_delete_first();
extern int dlink_delete_last();

#endif // _DOUBLE_LINK_H
