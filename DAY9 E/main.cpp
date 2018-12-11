#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int n,m,a[25][25],ans;//状态压缩dp
int dp[2][1 << 20];//集合S处理完的方法数,滚动数组

int main()
{
    while(scanf("%d%d",&n,&m) == 2)
    {
        int kk,x;
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        for(int i = 1; i <= n; i++)
        {
            cin >> kk;
            for(int j = 0; j < kk; j++)
            {
                cin >> x;
                a[i][x - 1] = 1;
            }
        }//牛1~n，场地0~n-1

        dp[0][0] = 1;//0一头都不放一种方案
        for(int i=1; i<=n; ++i)//遍历所有牛
        {
            for(int j=0; j<(1<<m); ++j)//遍历所有场地状态
            {
                if(dp[1-(i&1)][j])//表示前一头牛在j状态下有值
                {
                    for(int k=0; k<m; ++k)//遍历所有场地
                    {
                        if(a[i][k] && (!(j >> k & 1)))//表示第i头牛能放进k位置且k位置没有其他的牛
                            dp[i&1][j|(1<<k)]+=dp[1-(i&1)][j];
                    }
                }
            }
            memset(dp[1-(i&1)],0,sizeof(dp[1-(i&1)]));//更新滚动数组
        }
        int ans = 0;
        for (int i=1; i<(1<<m); i++)
        {
            ans+=dp[n & 1][i];//所有可以放置n头牛的状态，将其方法数相加
        }
        cout<<ans<<endl;
    }
    return 0;
}
