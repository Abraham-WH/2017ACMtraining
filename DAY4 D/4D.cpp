#include <iostream>
#include <stdio.h>
using namespace std;

int n,k;
int a[8][8];
char ch;
int visit[8];//��i���Ƿ�Ź�����
int ans;
int cnt;

void dfs(int x);

void dfs(int x)//�����x��
{
    if(cnt == k)
    {
        ans++;
        return;
    }
    if(x >= n ) return;//����if˳��  ����
    for(int i = 0 ; i < n ; i++)//��x�е�i���Ƿ����
    {
        if( visit[i] == 0 && a[x][i] == 1)
        {
            visit[i] = 1;
            cnt++;
            dfs(x + 1);//�ɷ�
            cnt--;
            visit[i] = 0;
        }
    }
    dfs(x + 1);//������һ��
}

int main()
{
    while(scanf("%d%d",&n,&k)  == 2 && !(n == -1 && k == -1))
    {
        ans = 0;
        cnt = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                cin>>ch;
                if(ch == '#')
                    a[i][j] = 1;
                else a[i][j] = 0;
            }
            visit[i]  = 0;
        }
      //  for(int i = 0; i < n - k; i++)�Ƿ�Ҫѭ����
            dfs(0);
        cout<<ans<<endl;
    }
    return 0;
}
