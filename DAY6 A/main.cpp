#include <iostream>
#include <stdio.h>
using namespace std;

int n,m;
int a[25][25];
int ans;
int visit[25][25];
char ch;
int sx,sy;
int p[4][2] = {-1,0,1,0,0,-1,0,1};
int queue[500][2];
int front,rear;


void bfs(int x,int y,int sum)
{
    visit[x][y] = 1;
    sum++;
    queue[rear][0] = x;//∏√µÍ»Î∂”
    queue[rear][1] = y;
    rear++;
    while(front != rear)
    {
        int fx = queue[front][0];
        int fy = queue[front][1];
        for(int i = 0 ; i < 4; i++)
        {
            if(a[fx + p[i][0]][fy + p[i][1]] ==1 && visit[fx + p[i][0]][fy + p[i][1]] ==0 && (fx + p[i][0]) >= 0 && (fx + p[i][0]) < n && (fy + p[i][1]) >= 0 && (fy + p[i][1]) <m)
            {
                visit[fx + p[i][0]][fy + p[i][1]] = 1;
                queue[rear][0] = fx + p[i][0];
                queue[rear][1] = fy + p[i][1];
                rear++;
                sum++;
            }
        }
        front++;
    }
    ans = sum;
}


int main()
{
    while(scanf("%d%d",&m,&n) == 2 && !(n == 0 && m == 0))
    {
        ans = 0;
        front = 0;
        rear = 0;
        getchar();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                scanf("%c",&ch);
                visit[i][j] = 0;
                if(ch == '#')
                    a[i][j] = 0;
                else if(ch == '.')
                    a[i][j] = 1;
                else
                {
                    a[i][j] = 1;
                    sx = i;
                    sy = j;
                }
            }
            getchar();
        }

        bfs(sx,sy,0);
        cout<<ans<<endl;
    }
    return 0;
}
