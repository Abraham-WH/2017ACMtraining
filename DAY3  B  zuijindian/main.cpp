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
    int visit;//�Ƿ��Ǹõ� 0���迼�� 1���� 2�Ұ��
};
node sample[100010];
node ssample[100010];
double ans;

double binarysearch(int l,int r);
double dist(int l,int r);
bool xcmp(node a,node b)//sort��������
{
    return a.x < b.x;
}

bool ycmp(node a,node b)
{
    return a.y < b.y;
}

double dist(node a,node b)//�������
{
    return sqrt(pow(a.x - b.x,2.0) + pow(a.y - b.y,2.0));
}

double binarysearch(int l,int r)//��������С����
{
    int mid = (l + r) / 2;
    double lans,rans;
    if(l == r) return 0;//һ����
    else if(l == r - 1)//��ײ�������
        return dist(sample[l],sample[r]);
    else if(l == r - 2)//������
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
    double lstandard = sample[mid].x - ans;//��������߽�
    double rstandard = sample[mid].x + ans;//�ұ߽�
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
    }//����м���Ҫ����ĵ㣬ѡ�еĵ���������С���룬��Ȼ������֮��С��ans!!!
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
        ans = 0;//������
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
