#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

struct node
{
    int start;
    int end;
    int val;
};
node s1,s2,s3;

int T;
int n;
int a[100010];

node maxs(int l,int r)
{
    int mid = (l + r) /2;
    if(l == r)
    {
        s1.val = a[l];
        s1.start = l;
        s1.end = r;
        return s1;
    }
    if(l < r)
    {
        // s1 = max(maxs(l,mid),maxs(mid + 1,r));
        if(maxs(l,mid).val > maxs(mid + 1,r).val)
        {
            s1 = maxs(l,mid);
        }
        else s1 =maxs(mid + 1,r);
        int ll,rr,t;
        ll = 0;
        rr = 0;
        t = 0;
        for(int i = mid + 1; i <= r; i++)
        {
            t += a[i];
            s2.start = mid + 1;
            s2.end = mid + 1;
            //rr = max(rr, t);
            if(rr < t)
            {
                s2.end =  i;
                rr = t;
            }
        }
        t = 0;
        for(int i = mid; i >= l; i--)
        {
            t += a[i];
            s3.start = mid;
            s3.end = mid;
            //ll = max(ll, t);
            if(ll < t)
            {
                s3.start =  i;
                ll = t;
            }
        }
        // s1.val = max(s1.val,ll+rr);
        if(s1.val < ll+rr)
        {
            s1.val = ll+rr;
            s1.start = s3.start;
            s1.end = s2.end;
        }
        return s1;
    }
}

int main()
{
    int left,right,ans;
    cin>>T;
    for(int i = 0; i < T; i++)
    {
        cin>>n;
        for(int j = 1; j<= n; j++)
            cin>>a[j];
        left = 1;
        right = n;
        ans = maxs(left,right).val;
        cout <<ans<< endl;
        cout<<maxs(left,right).start<<endl;
        cout<<maxs(left,right).end<<endl;
    }
    return 0;
}
