#include <iostream>
#include <stdio.h>
using namespace std;

int n,k;
int a[8][8];
char ch;
int visit[8];//第i列是否放过棋子
int ans;
int cnt;

void dfs(int x);

void dfs(int x)//处理第x行
{
    if(cnt == k)
    {
        ans++;
        return;
    }
    if(x >= n ) return;//两个if顺序  问题
    for(int i = 0 ; i < n ; i++)//第x行第i列是否放置
    {
        if( visit[i] == 0 && a[x][i] == 1)
        {
            visit[i] = 1;
            cnt++;
            dfs(x + 1);//可放
            cnt--;
            visit[i] = 0;
        }
    }
    dfs(x + 1);//处理下一行
}

int main()
{
    while(scanf("%d%d",&n,&k)  == 2 && !(n == -1 && k == -1))
    {
        ans = 0;
        cnt = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                cin>>ch;
                if(ch == '#')
                    a[i][j] = 1;
                else a[i][j] = 0;
            }
            visit[i]  = 0;
        }
      //  for(int i = 0; i < n - k; i++)是否要循环？
            dfs(0);
        cout<<ans<<endl;
    }
    return 0;
}
