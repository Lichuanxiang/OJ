#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

void QuickSort(int a[], int l, int r){
    if(l>=r) return;
    int i=l+1, j=r;
    int pivot = a[l];
    while(1)
    {
        while(a[i]<pivot) i++;
        while(a[j]>pivot) j--;
        if(i>=j) break;
        cout<<a[i]<<" "<<a[j]<<endl;
        swap(a[i], a[j]);
    }
    a[l] = a[j];
    a[j] = pivot;
    QuickSort(a, l, j-1);
    QuickSort(a, j+1, r);
}

//使用qsort函数需要导入stdlib.h库，并需设置比较方法
int cmp(const void *a, const void *b)
{
    return (*(int *)a-*(int *)b);
}

int main()
{
    int n, i, a[100];
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    //QuickSort(a, 0, n-1);

    qsort(a, n, sizeof(a[0]), cmp);

    for(i=0; i<n; i++)
        printf("%d ",a[i]);
    printf("\n");

    return 0;
}
