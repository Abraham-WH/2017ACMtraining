#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int t,n;
int a[20];
int visit[20];
int ans[20];//存放答案
int p;//答案数组索引
int flag;//有无解
int pre;//防止重复

bool cmp(int a,int b)
{
    return a > b;
}

void dfs(int k,int sum)//处理a[k]，当前和为sum
{
    if(sum == t)//有解
    {
        flag = 1;
        for(int i = 0; i < p - 1; i++)
            cout <<ans[i]<<'+';
        cout<<ans[p - 1]<<endl;
        return;
    }
    else if(sum > t) return;//无解
    else
    {
        for(int i = k; i < n; i++)
        {
            if(visit[i] == 0 && a[i] != pre)
            {
                sum += a[i];
                visit[i] = 1;
                ans[p++] = a[i];
                dfs(i + 1,sum);//如果a[k]放入答案，处理下一个
                sum -= a[i];//如果不放入
                visit[i] = 0;
                p--;
                pre = a[i];//如果该数不放入，标记防止重复！！！
            }
        }
    }
    return;
}

int main()
{
    while(scanf("%d%d",&t,&n) == 2&& n != 0)//t=0,n!=0的特殊情况
    {
        if(t == 0)
            cout<<"Sums of "<<t<<':'<<endl<<"NONE"<<endl;
        else
        {
            flag = 0;
            p = 0;
            pre = -1;
            for(int i = 0; i < n; i++)
            {
                scanf("%d",&a[i]);
                visit[i] = 0;
                ans[i] = 0;
            }
            sort(a,a + n,cmp);
            cout<<"Sums of "<<t<<':'<<endl;
            dfs(0,0);
            if(!flag)
                cout<<"NONE"<<endl;
        }
    }
    return 0;
}
