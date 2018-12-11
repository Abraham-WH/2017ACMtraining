#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

long long n,k,i;
long long a[100001];
int maxtime;
int upper;
int mid;
int lower;
int ans;
void Bsearch();

void Bsearch()
{
    lower = 1;
    upper = maxtime;
    while(lower <= upper )
    {
        mid = (upper + lower) / 2;
        int temp = 0;
        for( i = 0; i<n ; i++)
        {
            if(a[i]>mid)
                temp +=ceil((a[i]-mid)*1.0/(k-1));
        }
        if(temp<= mid)
        {
            ans = mid;
            upper = mid -1;
        }
        else  lower = mid +1;
    }
}

int main()
{
    while(scanf("%d",&n)==1)
    {
        for( i = 0; i<n ; i++)
        {
            cin>>a[i];
            if(maxtime< a[i])
                maxtime = a[i];
        }
        cin>>k;
        if(k !=1)
            Bsearch();
        else
            ans = maxtime;
        cout<<ans<<endl;
    }
    return 0;
}
