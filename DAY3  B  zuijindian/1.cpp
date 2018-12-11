#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
struct node
{
    double x;
    double y;
};
node a[100010];
node sa[100010];
double ans;

bool xcmp(node a,node b){return a.x < b.x;}
bool ycmp(node a,node b){return a.y < b.y;}
double dist(node a,node b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double binarysearch(int l,int r)//分治求最小距离
{
    int mid = (l + r) / 2;
    double lans,rans;
    if(l == r) 
		return 0;
    else if(l == r - 1)
        return dist(a[l],a[r]);
    else if(l == r - 2)
    {
        double ans1,ans2,ans3;
        ans1 = dist(a[l],a[r]);
        ans2 = dist(a[l],a[l + 1]);
        ans3 = dist(a[l + 1],a[r]);
        ans = min(ans1,ans2);
        ans = min(ans,ans3);
        return ans;
    }
        lans = binarysearch(l,mid);
        rans = binarysearch(mid + 1,r);
        ans = min(lans,rans);
        int k =0;
        double tans;
        for(int i = l; i <= r; i++)
            if(abs(a[i].x - a[mid].x) < ans)
				sa[k++] = a[i];
       
		sort(sa, sa + k, ycmp);
		for(int i = 0; i < k - 1; i++) 
		for (int j = i + 1; j < k && abs(sa[i].y - sa[j].y) < ans; j++) {
			tans = dist(sa[i],sa[i + 1]);
			ans = min(ans,tans);
		}
        return ans;
}

int main()
{
    int left,right;
    while(scanf("%d",&n) == 1 && n)
    {
        ans = 0;
        for(int i = 0; i < n; i++)
            scanf("%lf %lf", &a[i].x, &a[i].y);
        sort(a, a + n, xcmp);
        printf("%.2lf\n",binarysearch(0, n - 1) / 2);
    }
    return 0;
}
