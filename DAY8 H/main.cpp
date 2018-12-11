#include <iostream>
#include <stdio.h>
using namespace std;

int n,m,ans;
int a[110][110];
int dp[110][110] = {0};//滑雪问题，记忆化搜索，因为难以判定dp的方向和边界条件
int next[4][2] = {-1,0,1,0,0,-1,0,1};
int solve(int x,int y)
{
    if(dp[x][y] != 0)//边界条件
        return dp[x][y];
    int nx,ny;
    int mmax = 0;
    int mm[4] = {};
    for(int i = 0; i < 4; i++)
    {
        nx = x + next[i][0];
        ny = y + next[i][1];
        if(nx > 0 && nx <= n && ny > 0 && ny <= m && a[x][y] > a[nx][ny])//题意条件
        {
            mm[i] = solve(nx,ny);
            if(mm[i] > mmax)
                mmax = mm[i];
        }
    }
    dp[x][y] = mmax + 1;//转移方程
    return dp[x][y];
}

int main()
{
    while(scanf("%d%d",&n,&m) == 2)
    {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                cin>>a[i][j];
        ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                if(solve(i,j) > ans)
                    ans = solve(i,j);
            }
        cout<<ans<<endl;
    }
    return 0;
}
