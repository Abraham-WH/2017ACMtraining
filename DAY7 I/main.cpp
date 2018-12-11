#include <stdio.h>
#include <string.h>

int dp[1001][1001];

int main()
{
    int n,m,i,j;
    char a[1001],b[1001];
    while(~scanf("%s%s",a,b))
    {
        n = strlen(a);
        m = strlen(b);
        for(i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }
        for(i = 0; i <= m; i++)
        {
            dp[0][i] = 0;
        }
        for(i = 1; i <= n; i++)
            for(j = 1; j <= m; j++)
            {
                if(a[i - 1] == b[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = (dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1]);
            }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}
