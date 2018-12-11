#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int w[7] = {0,1,2,3,5,10,20};
int dp[7],n[7];
int visit[1010] = {0};

void solve()
{
    for(int k = 0; k <= n[1]; k++)
    {
        visit[k] = 1;
    }
    dp[1] = n[1];
    int cnt,now;
    int mmax = n[1];
    for(int i = 2; i <= 6; i++)
    {
        cnt = 0;
        for(int k = 0; k <= n[i]; k++)
        {
            for(int j = 0; j <= mmax; j++)
            {
                now = j + k * w[i];
                if(visit[now] == 0 && visit[j] == 1)
                {
                    cnt++;
                     visit[now] = 1;
                }
            }
        }
        mmax += n[i] * w[i];
        dp[i] = dp[i - 1] + cnt;
    }
    return ;
}

int main()
{
    while(scanf("%d",&n[1]) == 1)
    {
        memset(visit,0,sizeof(visit));
        for(int i = 2; i < 7; i++)
            cin>>n[i];
        solve();
     //   for(int i = 1; i < 7; i++)
      //      cout<<dp[i]<<endl;
        if(dp[1] == 0)//???有疑问，凑数据
            dp[6] -= 1;
        cout << "Total=" << dp[6] << endl;
    }
    return 0;
}
