#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int inf = 0x3f3f3f3f;
int n,a[210],dp1[210][210],dp2[210][210],sum[210];// 环变成2*n数组

int main()
{
    while(scanf("%d",&n) == 1)
    {
        sum[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&a[i]);
            a[n + i] = a[i];
        }
        memset(dp1,inf,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        for(int i = 1; i <= 2 * n; i++)
        {
            sum[i] = sum[i - 1] + a[i];
            dp1[i][i] = 0;//边界
            dp2[i][i] = 0;
        }
        for(int i=2; i<=2*n; i++)
        {
            for(int j=i-1; j>=(i<=n?1:i-n+1); j--)
            {
                for(int k=j; k<i; k++)
                {
                    dp1[j][i]=min(dp1[j][i],dp1[j][k]+dp1[k+1][i]+sum[i]-sum[j-1]);
                    dp2[j][i]=max(dp2[j][i],dp2[j][k]+dp2[k+1][i]+sum[i]-sum[j-1]);
                }
            }
        }


        int ans1 = inf;
        int ans2 = 0;
        for(int i = 1; i <= n; i++)
        {
            ans1 = min(ans1 , dp1[i][i + n - 1]);
            ans2 = max(ans2 , dp2[i][i + n - 1]);
        }
        printf("%d %d\n",ans1,ans2);

    }
    return 0;
}
