#include <iostream>
#include <stdio.h>
using namespace std;
int sample,n,m,p[105],h[105],c[105];//总金额，大米种类，价格，重量，袋数
int dp[105][105];//dp[i][j] = max(  dp[i -1][j] ,  k * h[i] + dp[i - 1][j - k * p[i]] )(  0 <= k <= c[i] )  i种物品剩余资金j

int max(int a,int b)
{
    return a > b ? a : b;
}

void solve()
{
    for(int i = 0; i <= n; i++)
        dp[0][i] = 0;
    for(int i = 1; i <= m; i++)
    {
        for(int j = n; j >= 0; j--)
        {
            for(int k = 0; k <= c[i]; k++)
            {
                if((j + k * p[i]) <= n && (j + k * p[i]) >= 0)
                    dp[i][j] = max(dp[i - 1][j] , k * h[i] + dp[i -1][j + k * p[i]]);
            }
        }
    }
}

int main()
{
    cin >> sample;
    for(int i = 0; i < sample; i++)
    {
        cin >> n >> m;
        for(int j = 1; j <= m; j++)
            cin >> p[j] >> h[j] >> c[j];
        solve();
   //     for(int i = 0; i <= m; i++)
 //       {
           // for(int j = 0; j <= n; j++)
         //       cout<<dp[i][j]<<' ';
       //     cout<<endl;
      //  }
        cout << dp[m][0] << endl;
    }
    return 0;
}



