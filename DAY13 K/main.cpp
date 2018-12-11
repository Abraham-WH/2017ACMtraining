#include <iostream>
#include <stdio.h>
using namespace std;

int sample,n,m,l,r,father[1005],ans;

void initset()
{
    for(int i = 1; i <= n; i++)
        father[i] = i;
    return;
}

int searchset(int a)
{
    /* if(father[a] != a)
         searchset(father[a]);
     return father[a];*/
    int x;//减少递归的使用
    while(a != father[a])
        a = father[a];
    return a;
}

void mergeset(int a,int b)
{
    int x = searchset(a);
    int y = searchset(b);

    if(x!=y)
    {
        if(x>y)
            father[y]=x;
        else
            father[x]=y;//将两个集合的根节点合并！！
    }
    return;
}

int main()
{
    cin>>sample;
    for(int i = 0; i < sample; i++)
    {
        cin>>n>>m;
        ans = 0;
        initset();
        for(int j = 0; j < m; j++)
        {
            cin>>l>>r;
            mergeset(l,r);
        }
        for(int j = 1; j <= n; j++)
        {
            if(father[j] == j)
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
