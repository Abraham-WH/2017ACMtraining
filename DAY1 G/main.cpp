#include <iostream>  
#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
int m,k;
int ans=0;

struct node
{
    int start;
    int end;
    int num=1;
};
node sample[100];

void init();

bool cmp(node a,node b)
{
    return a.end<b.end;
}
void init()
{
    while(scanf("%d",&n) == 1)
    {
        for(int i=0; i<n; i++)
        {
            cin>>m;
            sample[i].start=m;
            cin>>k;
            sample[i].end=k;
        }

        sort(sample,sample+n,cmp);
        if(n!=0)
        {
            ans = 1;
            int temp = 0;
            for (int i = 1; i < n; i++)
            {
                if(sample[temp].end <= sample[i].start)
                {
                    ans++;
                    temp = i;
                }
            }
        }
        else break;

        cout<<ans<<endl;
    }
}

int main()
{
    init();
    return 0;
}
