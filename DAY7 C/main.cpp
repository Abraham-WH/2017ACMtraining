#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
//概率对应重量限制，收益对应，案件数对应物品数（！！！概率为double，不同于重量）
double p,w[105],safe[105];//总概率，单个概率,单个安全概率
int v[105],n,c,mmoney,ans,i,j;//单个利益，事件数，总案例
double dp[105 * 105];//收益为j时，安全时的概率 （转化状态！）

double max(double a,double b)
{
    return a > b ? a : b;
}

void solve()//递推
{
    dp[0] = 1.0;
    for(i = 1; i <= n; i++)//第几件案件
        for(j = mmoney; j >= v[i]; j--)
            dp[j] = max(dp[j],dp[j - v[i]] * safe[i]);//不放？放？决策
    for(j = mmoney; j >= 0; j--)
    {
        if(dp[j]-(1.0 - p)>0.000000001)//精度问题
        {
            ans = j;
            break;
        }
    }
    return ;
}

int main()
{
    cin>>c;
    for(int k = 0; k < c; k++)
    {
        cin>>p>>n;//个数，总重量
        mmoney = 0;
        ans = 0;
        for(int i = 1; i <= n; i++)
        {
            cin>>v[i]>>w[i];
            mmoney += v[i];
            safe[i] = 1 - w[i];
        }
        memset(dp,0,sizeof(dp));
        solve();
        cout<<ans<<endl;//总重量为m的最多价值
    }
    return 0;
}
