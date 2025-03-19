#include<bits/stdc++.h>
using namespace std;


void swap(int arr[],int a,int b)
{
    int temp = arr[b];
    arr[b] = arr[a];
    arr[a] = temp;
}

int partition(int arr[], int l, int r) {
    int k = l + rand() % (r - l + 1); // 随机选择 pivot 索引
    int pivot = arr[k]; // pivot 的值
    int a = l; // 用于记录小于等于 pivot 的元素的位置
    int mid = 0; // 用于记录 pivot 的最终位置

    for (int i = l; i <= r; i++) {
        if (arr[i] <= pivot) {
            if (arr[i] == pivot) {
                mid = a; // 记录 pivot 的位置
            }
            swap(arr,a, i); // 交换 arr[a] 和 arr[i]
            a++;
        }
    }
    swap(arr,mid, a-1); // 将 pivot 移动到正确的位置
    return a-1; // 返回 pivot 的最终位置
}

void quicksort(int arr[],int l,int r)
{
    if(l<r) {
        int mid = partition(arr,l, r);
        quicksort(arr, l, mid - 1);
        quicksort(arr, mid + 1, r);
    }
}

int main()
{
    int arr[10] = {22,32,999,-9,4,2,4,5,0,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    srand(time(0));
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}