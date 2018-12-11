#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int a[1000010],n,k,q[1000010],ans[1000010];//队列中放置数组下标而不是数值

void Minqueue()
{
    int front =1;
    int rear = 1;//队列最后一个数
    int index = 1;
    for(int i = 1; i <= n; i++)
    {
        while(front <= rear && (a[i] < a[q[rear]]))
            rear --;//删除所有小于a[i]的数，并放置a[i]
        q[++rear] = i;
        while(i >= k && q[front] <= i - k)
            front++;//超出区间
        if(i >= k && front <= rear&& q[front] > i - k)
        {
            ans[index] = a[q[front]];//队头合适，打印
            cout<<ans[index]<<' ';
            index++;
        }
    }
    return;
}

void Maxqueue()
{
    int front =1;
    int rear = 1;//队列最后一个数
    int index = 1;
    for(int i = 1; i <= n; i++)
    {
        while(front <= rear && (a[i] > a[q[rear]]))
            rear --;//删除所有小于a[i]的数，并放置a[i]
        q[++rear] = i;
        while(i >= k && q[front] <= i - k)
            front++;//超出区间
        if(i >= k && front <= rear&& q[front] > i - k)
        {
            ans[index] = a[q[front]];//队头合适，打印
            cout<<ans[index]<<' ';
            index++;
        }
    }
    return;
}
int main()
{
    while(scanf("%d%d",&n,&k) == 2)
    {
        memset(q,0,sizeof(q));
        memset(ans,0,sizeof(ans));
        for(int i = 1; i <= n; i++)
            cin>>a[i];
        Minqueue();
        cout<<endl;
        Maxqueue();
        cout<<endl;
    }
    return 0;
}
