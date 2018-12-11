#include <iostream>
#include <cmath>
using namespace std;

int dp[1 << 10][10],n,ans;
const int inf = 99999;
 int d[5][5]= {0,3,inf,4,inf,
            inf,0,5,inf,inf,
            4,inf,0,5,inf,
            inf,inf,inf,0,3,
            7,6 ,inf,inf,0
                 };

int sol(int s,int v)
{
    if(dp[s][v] >= 0)
        return dp[s][v];
    if(s == (1 << n) - 1 && v == 0)
        return dp[s][v] = 0;
    ans = inf;
    for(int i =0; i < n; i++)
    {
        if(!(s >> i & 1))
            ans = min(ans,sol(s | 1 << i,i) + d[v][i]);
    }
    return dp[s][v] = ans;
}

int main()
{
    n = 5;
    cout <<sol(0,0)<< endl;
    return 0;
}
