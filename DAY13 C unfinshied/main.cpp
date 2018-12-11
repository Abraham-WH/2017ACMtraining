#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const int maxn = 1000005;
int a[maxn],dp[maxn];//以i结尾的子序列最大长度
int n,m,k,f1,f2,r1,r2,l1,l2,ans;
int minq[maxn],maxq[maxn];//单调队列索引下标

int max(int a,int b)
{
    return a > b ? a : b;
}

int main()
{
    while(scanf("%d%d%d",&n,&m,&k) == 3)
    {
        memset(dp,0,sizeof(dp));
        memset(minq,0,sizeof(minq));
        memset(maxq,0,sizeof(maxq));
        f1=1;
        f2=1;
        r1=1;
        r2=1;
        ans=0;
        l1=0;
        l2=0;
        for(int i = 1; i <= n; i++)
            cin>>a[i];
        for(int i = 1; i <= n; i++)
        {
            while(f1 <= r1 && a[minq[r1]] > a[i])
                r1--;
            minq[++r1] = i;//维护最小值
             while(f2 <= r2 && a[maxq[r2]] > a[i])
                r2--;
            maxq[++r2] = i;//维护最大值
            while(a[maxq[f2]] - a[minq[f1]] > k)
            {
                if(maxq[f2] < minq[f1])
                    l2 = maxq[f2++];
                else l1 = minq[f1++];
            }
            if(a[maxq[f2]] - a[minq[f1]] >= m)
            {
                ans = max(ans , i - max(l1,l2));
            }
        }
        cout<<ans<<endl;
    }
}
