#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int inf = 10000;
int n,a[105],dp1[105][105],dp2[105][105],l,r,len,sum[105];

int mmin(int a,int b)
{
    return a < b ? a : b;
}

int mmax(int a,int b)
{
    return a > b ? a : b;
}

void solve()
{
    for(int i = 1; i <= n; i++)
    {
        dp1[i][i] = 0;//边界
        dp2[i][i] = 0;
    }
    for(len = 1; len <= n; len++) //区间长度//一定注意<还是<=，否则可能导致区间溢出
    {
        for(l = 1; (r = l + len) <= n; l++) //区间端点
        {
            for(int k = l; k < r; k++) //子区间
            {
                int temp1 = dp1[l][k] + dp1[k + 1][r];
                dp1[l][r] = mmin(dp1[l][r],temp1);
                int temp2 = dp2[l][k] + dp2[k + 1][r];
                dp2[l][r] = mmax(dp2[l][r],temp2);
            }
            dp1[l][r] += sum[r] - sum[l - 1];
            dp2[l][r] += sum[r] - sum[l - 1];
        }
    }
}

int main()
{
    while(scanf("%d",&n) == 1)
    {
        memset(dp1,inf,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        memset(sum,0,sizeof(sum));
        for(int i = 1; i <= n; i++)
        {
            cin>>a[i];
            sum[i] = a[i] + sum[i - 1];
        }
        solve();
        cout<<dp1[1][n]<<' '<<dp2[1][n]<<endl;
    }
    return 0;
}
