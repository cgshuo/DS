#include <iostream>
using namespace std;

void bubbleSort1(int* a, int n)
{
    int i, j, tmp;
    for(i = n-1; i > 0; i--)
    {
        for(j = 0; j < i; j++)
        {
            if(a[j] > a[i])
            {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}

void bubbleSort2(int *a, int n)
{
    int i,j,tmp,flag;
    for(i = n - 1; i > 0; i--)
    {
        for(j = 0; j < i; j++)
         {
            if(a[j] > a[j+1])
            {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;

                flag = 1;
            }
            if(flag == 0)
                break;

        }
    
    }
    
}
int main()
{
    int i;
    int a[] = {20,40,30,10,60,50};
    int ilen = (sizeof(a)) / (sizeof(a[0]));

    cout << "before sort:";
    for (i=0; i<ilen; i++)
        cout << a[i] << " ";
    cout << endl;

    bubbleSort1(a, ilen);
    //bubbleSort2(a, ilen);

    cout << "after  sort:";
    for (i=0; i<ilen; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}