#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int m,n;//总行数列数
char ch;
int visit[100][100] = {0};//标记数组
int a[100][100] = {0};//有无油田

void dfs(int x,int y,int dep);//当前状态x,y和遍历层数

void dfs(int x,int y,int dep)
{
    if(x>=0 && x < m && y >= 0 && y < n && visit[x][y] == 0 && a[x][y] == 1)
    {
        visit[x][y] = 1;
        for(int i = -1; i < 2; i++)
            for(int j = -1; j < 2; j++)
            {
                if(!(i == 0 && j ==  0))
                    dfs(x + i , y + j , dep);
            }
    }
    else return;
}

int main()
{
    while(scanf("%d%d",&m,&n) == 2 && !(m == 0 && n == 0))
    {
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                cin>>ch;
                if(ch == '@')
                  {
                      a[i][j] = 1;
                  }
                else a[i][j] = 0;
                visit[i][j] = 0;
            }

        int ans = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                if(visit[i][j] == 0 && a[i][j] == 1)
                    dfs(i,j,++ans);//以根节点计数
            }
        cout<<ans<<endl;
    }

    return 0;
}
