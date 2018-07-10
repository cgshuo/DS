#include <iostream>
using namespace std;

void merge(int* a, int start, int mid, int end)
{
    int *tmp = new int[end-start+1];
    int i = start;
    int j = mid + 1;
    int k = 0;
    while(i <= mid && j <= end)
    {
        if(a[i] <= a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }

    while(i <= mid)
        tmp[k++] = a[i++];
    while(j <= end)
        tmp[k++] = a[j++];
    
    for(i = 0; i < k; i++)
        a[start+i] = tmp[i];
    delete[]tmp;
}

void mergeSortUp2Down(int* a, int start, int end)
{
    if(a == NULL || start >= end)
        return;
    int mid = (end + start)/2;
    mergeSortUp2Down(a, start, mid);
    mergeSortUp2Down(a, mid+1, end);

    merge(a, start, mid, end);
}

void mergeGroups(int*a ,int len, int gap)
{
    int i;
    int twolen = 2 * gap;//两个相邻的子数组的长度
    // 将"每2个相邻的子数组" 进行合并排序。
    for(i = 0; i+twolen-1 < len; i+=twolen)
    {
        merge(a, i, i+gap-1, i+twolen-1);
    }
    // 若 i+gap-1 < len-1，则剩余一个子数组没有配对。
    // 若 i+gap-1 < len-1，则剩余一个子数组没有配对。
    if(i+gap-1 < len-1)
        merge(a, i, i+gap-1, len-1);
}
void mergeSortDown2Up(int* a, int len)
{
    int n;
    if(a == NULL || len <= 0)
        return;
    for(n = 1; n < len; n*=2)
        mergeGroups(a, len, n);
}

int main()
{
    int i;
    int a[] = {80,30,60,40,20,10,50,70};
    int ilen = (sizeof(a)) / (sizeof(a[0]));

    cout << "before sort:";
    for (i=0; i<ilen; i++)
        cout << a[i] << " ";
    cout << endl;

    mergeSortUp2Down(a, 0, ilen-1);        // 归并排序(从上往下)
    //mergeSortDown2Up(a, ilen);            // 归并排序(从下往上)

    cout << "after  sort:";
    for (i=0; i<ilen; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}