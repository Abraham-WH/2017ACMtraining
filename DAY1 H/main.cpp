#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int ans = 0;
struct node
{
    int att;
    int def;
};
node enemy[100];
bool cmp(node a,node b);

bool cmp(node a,node b)
{
    return (a.att * b.def) > (b.att * a.def);//若直接采用除法，比值   会丧失精度，造成排序错误 如14/10 = 15/10
}

int main()
{
    while(scanf("%d",&n) != -1)
    {
        for(int i=0; i<n; i++)
        {
            cin>>enemy[i].att;
            cin>>enemy[i].def;
        }

        sort(enemy,enemy+n,cmp);

        int temp = 0;
        for(int i=0; i<n; i++)
        {
            temp += enemy[i].def;
            ans += (enemy[i].att * temp);
        }
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}
