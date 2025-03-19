#include<bits/stdc++.h>
using namespace std;

void binarysearch(int arr[],int size)
{
    int mid,k;
    int left =0;int right;
    right = size -1;
    cin>>k;
    while(left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == k)
        {
            cout<<"下标是："<<mid;
            return;
        }
        if(arr[mid] < k)
        {left = mid+1;}
        else
        {right = mid-1;}
    }
    cout<<"!!";
    return;
}
int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,11};
    binarysearch(arr,10);
}