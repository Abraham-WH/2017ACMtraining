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
    int visit;//是否考虑该点 0无需考虑 1左半边 2右半边
};
node sample[100010];
node ssample[100010];
double ans;

double binarysearch(int l,int r);
double dist(int l,int r);
bool xcmp(node a,node b)//sort函数辅助
{
    return a.x < b.x;
}

bool ycmp(node a,node b)
{
    return a.y < b.y;
}

double dist(node a,node b)//两点距离
{
    return sqrt(pow(a.x - b.x,2.0) + pow(a.y - b.y,2.0));
}

double binarysearch(int l,int r)//分治求最小距离
{
    int mid = (l + r) / 2;
    double lans,rans;
    if(l == r) return 0;//一个点
    else if(l == r - 1)//最底层两个点
        return dist(sample[l],sample[r]);
    else if(l == r - 2)//三个点
    {
        double ans1,ans2,ans3;
        ans1 = dist(sample[l],sample[r]);
        ans2 = dist(sample[l],sample[l + 1]);
        ans3 = dist(sample[l + 1],sample[r]);
        ans = min(ans1,ans2);
        ans = min(ans,ans3);
        return ans;
    }
    lans = binarysearch(l,mid);
    rans = binarysearch(mid + 1,r);
    ans = min(lans,rans);
    double lstandard = sample[mid].x - ans;//搜索的左边界
    double rstandard = sample[mid].x + ans;//右边界
    int k =0;
    double tans;
    for(int i = l; i <= r; i++)
    {
        if(sample[i].x > lstandard && i<=mid)
        {
            sample[i].visit = 1;
            ssample[k++] = sample[i];
        }
        if(sample[i].x < rstandard && i>mid)
        {
            sample[i].visit = 2;
            ssample[k++] = sample[i];
        }
    }//标记中间需要处理的点，选中的点若存在最小距离，必然纵坐标之差小于ans!!!
    sort(ssample,ssample + k,ycmp);
    for(int i = 0; i < k; i++)

    {
        if(ssample[i].visit != ssample[i + 1].visit)
        {
            tans = dist(ssample[i],ssample[i +1]);
            ans = min(ans,tans);
        }
    }
    return ans;
}

int main()
{
    int left,right;
    while(scanf("%d",&n) == 1 && n != 0)
    {
        ans = 0;//答案清零
        left = 0;
        right = n -1;
        for(int i = 0; i < n; i++)
        {
            cin>>sample[i].x>>sample[i].y;
            sample[i].visit = 0;
        }
        sort(sample,sample + n,xcmp);
        printf("%.2f\n",binarysearch(left,right) / 2);
    }
    return 0;
}
