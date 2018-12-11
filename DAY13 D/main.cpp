#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int a[1000010],n,k,q[1000010],ans[1000010];//�����з��������±��������ֵ

void Minqueue()
{
    int front =1;
    int rear = 1;//�������һ����
    int index = 1;
    for(int i = 1; i <= n; i++)
    {
        while(front <= rear && (a[i] < a[q[rear]]))
            rear --;//ɾ������С��a[i]������������a[i]
        q[++rear] = i;
        while(i >= k && q[front] <= i - k)
            front++;//��������
        if(i >= k && front <= rear&& q[front] > i - k)
        {
            ans[index] = a[q[front]];//��ͷ���ʣ���ӡ
            cout<<ans[index]<<' ';
            index++;
        }
    }
    return;
}

void Maxqueue()
{
    int front =1;
    int rear = 1;//�������һ����
    int index = 1;
    for(int i = 1; i <= n; i++)
    {
        while(front <= rear && (a[i] > a[q[rear]]))
            rear --;//ɾ������С��a[i]������������a[i]
        q[++rear] = i;
        while(i >= k && q[front] <= i - k)
            front++;//��������
        if(i >= k && front <= rear&& q[front] > i - k)
        {
            ans[index] = a[q[front]];//��ͷ���ʣ���ӡ
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
