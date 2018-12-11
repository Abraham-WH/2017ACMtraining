#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;//dp[i][j][ii][jj]两条路同时走到(i,j)(ii,jj)时的最大

int n,r,c,a[12][12],dp[12][12][12][12];

int mmax(int a,int b,int c,int d)
{
    int s[4] = {a,b,c,d};
    sort(s,s + 4);//不是sort(s,s+3)
    int ans;
    ans = s[3];
    return ans;
}

void solve()
{
    memset(dp,0,sizeof(dp));
    int i,j,ii,jj;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            for(ii = 1; ii <= n; ii++)
                for(jj = 1; jj <= n; jj++)
                {
                    if(i == ii && j == jj)
                        dp[i][j][ii][jj] = mmax(dp[i - 1][j][ii - 1][jj],dp[i][j - 1][ii - 1][jj],dp[i - 1][j][ii][jj - 1],dp[i][j - 1][ii][jj - 1]) + a[i][j];
                    else
                        dp[i][j][ii][jj] = mmax(dp[i - 1][j][ii - 1][jj],dp[i][j - 1][ii - 1][jj],dp[i - 1][j][ii][jj - 1],dp[i][j - 1][ii][jj - 1]) + a[i][j] + a[ii][jj];
                }
    return;
}

int main()
{
    while(scanf("%d",&n) != EOF)
    {
        memset(a,0,sizeof(a));
        while(1)
        {
            cin>>r>>c;
            cin>>a[r][c];
            if(r == 0 && c == 0)
                break;
        }
        solve();
        cout<<dp[n][n][n][n]<<endl;
    }
    return 0;
}
