#include <iostream>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;

typedef long long ll;

int n,a[10010];//种数和每种数量
priority_queue <int,vector<int>,greater<int> > q;
int main()
{
    while(1)
    {
        int t1,t2,nn;
        ll ans = 0;
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1,a + n + 1);
        for(int i = 1; i <= n; i++)
            q.push(a[i]);//进入优先队列
        for(int i = 1; i <= n - 1; i++)
        {
            t1 = q.top();
            q.pop();
            t2 = q.top();//最小的两堆
            q.pop();
            nn = t1 + t2;
            ans += nn;//记录
            q.push(nn);//新堆入队
        }
        cout<< ans << endl;
    }
    return 0;
}
