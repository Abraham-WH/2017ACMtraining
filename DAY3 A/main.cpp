#include <iostream>
#include <stdio.h>
using namespace std;

int n,k;
int a[100010];
int b[100010];
int l,r;
int mid;
int cnt = 0;
int ans = 0;

void binary(int lower,int upper);
void merge(int lower,int upper);

void merge(int lower,int upper)
{
    mid = (lower + upper) / 2;
    int i,j;
    i = lower;
    j = mid + 1;
    for(int k = lower; k <= upper; k++)
    {
        if(i <= mid &&(j >upper||a[i]<=a[j]))
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
            cnt += (mid - i + 1);
        }
    }
    for(int k = lower; k <= upper; k++)
    {
        a[k]= b[k];
    }
}

void binary(int lower,int upper)
{
    mid = (lower + upper) / 2;
    if(lower < upper)
    {
        binary(lower,mid);
        binary(mid + 1,upper);
    }
    merge(lower,upper);
}

int main()
{
    while(scanf("%d",&n) == 1)
    {
        cin>>k;
        for(int i = 1; i <= n; i++)
            cin>>a[i];

        l =1;
        r = n;
        binary(l,r);
        cout<<"排序后数组为";
        for(int i = 1; i <= n; i++)
            cout<<a[i];
        cout<<endl;


        if(k > cnt) ans = 0;
        else
            ans = cnt - k;
        cout<<ans<<endl;
    }

    return 0;
}
