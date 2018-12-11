#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 99999;
int dp[1<<12][12],n,m,cnt,ans,xx[12],yy[12];//状态压缩DP，走过的点集合S当前所在点v

int mmin(int a,int b)
{
    return a < b ? a : b;
}

int abs(int a,int b)
{
    return a > b ? (a - b) : (b - a);
}

int sol(int s,int v)
{
    if(dp[s][v] >= 0)
        return dp[s][v];
    if(s == (1<<cnt) - 1 &&v == 0)
        return dp[s][v] = 0;
    ans = inf;
    for(int i = 0; i < cnt; i++) //遍历每个不属于S的新点
    {
        if(!(s >> i & 1))
            ans = mmin(ans,sol(s + (1<<i), i) + abs(xx[i],xx[v]) + abs(yy[i] , yy[v]));//递归记忆化搜索
    }
     if(ans == inf) return dp[s][v] = xx[v] + yy[v];
    return dp[s][v] = ans;
}

int main()
{

    while(scanf("%d%d",&n,&m)!=EOF)
    {
        cnt = 0;
        memset(xx,-1,sizeof(xx));
        memset(yy,-1,sizeof(yy));
        memset(dp,-1,sizeof(dp));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                int t;
                cin>>t;
                if(t)
                {
                    xx[cnt] = i;
                    yy[cnt] = j;
                    cnt++;
                }

            }
        cout<<sol(0,0)<<endl;
        for(int i = 0; i < 1<<cnt; i++)
            for(int j = 0; j < cnt; j++)
                cout<<dp[i][j]<<' ';

    }
    return 0;
}
