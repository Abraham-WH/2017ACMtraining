#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n,k;
int a[10000000];
int ans;

void find(int kk,int l,int r);//kk��Ҫ��ĵ�k����
int read();

int read()//��д�Ż�����
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
    int mid = (l + r) / 2;//������ֵ
    int key ;
    swap(a[mid],a[r]);//��ֵ�Ŷ�β
    int i = l;
    int j = r - 1;
    while(i <= j)//��ʼ���ߴ�������ֵ�Ƚ�
    {
        while(a[i] < a[r])  i++;
        while(a[j] > a[r])  j--;
        if(i <= j)
            swap(a[i++],a[j--]);
    }
    key = i;
    swap(a[i],a[r]);//������ֵ
    if(key == n-kk)
    {
        ans = a[key];
        return ;//�ҵ�
    }
    if(l < j)find(kk,l,j);//�ݹ飬����
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
        a[i] = read();//������Ż�
    find(k,left,right);
    cout <<ans<< endl;
    return 0;
}
