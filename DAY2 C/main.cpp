#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int a[4010];
int b[4010];
int c[4010];
int d[4010];
int n;
long long ans = 0;
void Bsearch();
int target[4010*4010];

void Bsearch()
{
    for(int i = 0; i < n ; i++)
        for(int j = 0; j < n; j++)
        {
            target[i*n+j] = -(a[i] + b[j]);
        }//ab和的相反数
    sort(target,target + n*n);
    int temp;
    for(int i = 0; i < n ; i++)
        for(int j = 0; j < n; j++)
        {
            temp = upper_bound(target,target+n*n,c[i] + d[j])-lower_bound(target,target+n*n,c[i] + d[j]);
            ans +=temp;
            //    if(temp!=0)
            //     cout<<c[i]<<' '<<d[j]<<endl;
        }
}

int main()
{
    while(scanf("%d",&n) == 1)
    {
        ans = 0;//答案清零
        for(int i = 0; i < n; i++)
            cin>>a[i]>>b[i]>>c[i]>>d[i];
        Bsearch();
        cout<<ans<<endl;
    }
    return 0;
}
