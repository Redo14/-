#include<bits/stdc++.h>
using namespace std;
#define initsize 100
#define elemtype int

typedef struct{
    elemtype *data;
    int maxsize,length;
}sqlist;

void Initlist(sqlist &l)
{
    l.data = new int[initsize]; // l.data = (elemtype *)malloc(每次增加 乘以 sizeof(elemtype))
    l.length=0;
    l.maxsize = initsize;
}
bool listinsert(sqlist &l,int p,elemtype data)
{
    if(p<1||p > l.length+1)
    {return false;}
    if(l.length >= l.maxsize)
    {return false;}
    for(int i=l.length;i>=p;i--)  //位序:l->l+1开始,最后p->p+1 ,下标则全部-1
    {l.data[i] = l.data[i-1];}
    l.data[p-1] = data;
    l.length++;
    return true;
}

bool listdisplay(sqlist &l){
    if(l.length == 0)
    {cout<<"空的顺序表";
    return false;}
    cout<<endl;
    for(int i=0;i<l.length;i++)
    {cout<<"["<<i+1<<"]"<<l.data[i]<<endl;}
    return true;
}
bool listdelete(sqlist &l,int p)
{
    if(p<1||p>l.length)
    {return false;}
    for(int i=p;i<l.length;i++)
    {l.data[i-1]=l.data[i];}
    l.length--;
    return true;
}
bool deletek(sqlist &l,int k)
{
    int j=0;
    for(int i=0;i<l.length;i++)
    {
        l.data[i-j] = l.data[i]; //chaoguo!
        if(l.data[i] == k)
        {
            j++;
        }
    }
    l.length = l.length -j;
    return true;
}
int main() {
    sqlist l1;
    Initlist(l1);
    listinsert(l1,1,2);
    listinsert(l1,2,2);
    listinsert(l1,3,2);
    listinsert(l1,2,2);
    listinsert(l1,2,2);
    listinsert(l1,4,2);
    deletek(l1,2);
    listdisplay(l1);
}