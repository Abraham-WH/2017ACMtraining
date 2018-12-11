#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n,k;
int a[10000000];
int ans;

void find(int kk,int l,int r);//kk，要求的第k大数
int read();

int read()//读写优化函数
{
    int tmp = 0;
    char x;
    while(1)
    {
        x = getchar();
        if(x >= '0' && x<= '9') tmp = tmp * 10 + x - '0';
        else break;
    }
    return tmp;
}

void find(int kk,int l,int r)
{
    int mid = (l + r) / 2;//快排轴值
    int key ;
    swap(a[mid],a[r]);//轴值放队尾
    int i = l;
    int j = r - 1;
    while(i <= j)//开始两边处理，与轴值比较
    {
        while(a[i] < a[r])  i++;
        while(a[j] > a[r])  j--;
        if(i <= j)
            swap(a[i++],a[j--]);
    }
    key = i;
    swap(a[i],a[r]);//换回轴值
    if(key == n-kk)
    {
        ans = a[key];
        return ;//找到
    }
    if(l < j)find(kk,l,j);//递归，分治
    if(r > i)find(kk,i+1,r);
}

int main()
{
    int left,right;
    ans = 0;
    cin>>n>>k;
    left = 0;
    right = n - 1;
    for(int i = 0; i < n; i++)
        a[i] = read();//读入的优化
    find(k,left,right);
    cout <<ans<< endl;
    return 0;
}
