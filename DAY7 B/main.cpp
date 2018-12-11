#include <iostream>
using namespace std;

int sample,height,a[105][105],dp[105][105];

int mmax(int p,int q)
{
    return  p > q ? p : q;
}

int solve(int i,int j)
{
    if(dp[i][j] != 0) return dp[i][j];
    return dp[i][j] = a[i][j] + (i == height ? 0 : mmax(solve(i + 1,j),solve(i + 1,j + 1)));
}

int main()
{
    cin>>sample;
    for(int k = 0; k < sample; k++)
    {
        cin>>height;
        for(int i = 1; i <= height; i++)
            for(int j = 1; j <= i; j++)
            {
                cin>>a[i][j];
                dp[i][j] = 0;
                dp[height][j] = a[height][j];
            }
        int ans = solve(1,1);
        cout << ans << endl;
    }
    return 0;
}
