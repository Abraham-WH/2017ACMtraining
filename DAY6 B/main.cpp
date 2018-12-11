#include <iostream>
#include <stdio.h>
using namespace std;

int n,k;
int ans = 0;
int queue[200005];
int front = 0;
int rear = 0;
int before[200005];//开数组的范围
int visit[200005] = {0};
void bfs()
{
    visit[n] = 1;
    queue[rear++] = n;
    before[n] = -1;
    while(front != rear)
    {
        int f = queue[front];
        int then[3] = {2 * f,f + 1,f - 1};
        front++;
        for(int i = 0; i < 3; i++)
        {
            if(visit[then[i]] == 0 && then[i] > 0 && then[i] < 200000)//限制越界
            {
                queue[rear++] =then[i];
                visit[then[i]] = 1;
                before[then[i]] = f;//设置前继结点
            }
            //cout<<then[i]<<endl;
            if(then[i] == k)
                return;
        }
    }
    return;
}

int main()
{
    while(scanf("%d%d",&n,&k) == 2)
    {
        ans = 0;
        front = 0;
        rear = 0;
        for(int i = 0; i < 2 * k; i++)
        {
            visit[i] = 0;
        }
        if(n == 0 && k != 0)
        {
            ans++;
            visit[0] = 1;
            n = 1;
        }
        bfs();
        int t,tt;
        t = before[k];
        while(t != -1)
        {
            tt = before[t];
            t = tt;
            ans++;
        }
        cout<< ans <<endl;
    }
    return 0;
}
