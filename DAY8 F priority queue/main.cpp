#include <iostream>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;

typedef long long ll;

int n,a[10010];//������ÿ������
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
            q.push(a[i]);//�������ȶ���
        for(int i = 1; i <= n - 1; i++)
        {
            t1 = q.top();
            q.pop();
            t2 = q.top();//��С������
            q.pop();
            nn = t1 + t2;
            ans += nn;//��¼
            q.push(nn);//�¶����
        }
        cout<< ans << endl;
    }
    return 0;
}
