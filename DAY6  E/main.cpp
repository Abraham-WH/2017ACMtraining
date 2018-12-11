#include <iostream>
#include <stdio.h>
using namespace std;

int n,m;
int a[10][10];
int ans;
int visit[10][10];
int sx,sy;
int p[4][2] = {-1,0,1,0,0,-1,0,1};
int queue[100][2];
int front,rear;
int before[5][5][2];//Ç°Çý½áµã
void bfs(int x,int y)
{
    visit[x][y] = 1;
    before[0][0][0] = -1;
    before[0][0][1] = -1;
    queue[rear][0] = x;//
    queue[rear][1] = y;
    rear++;
    while(front != rear)
    {
        int fx = queue[front][0];
        int fy = queue[front][1];
        for(int i = 0 ; i < 4; i++)
        {
            int nx = fx + p[i][0];
            int ny = fy + p[i][1];
            if(a[nx][ny] ==0 && visit[nx][ny] ==0 && nx >= 0 && nx < n && ny >= 0 && ny <m)
            {
                visit[nx][ny] = 1;
                queue[rear][0] = nx;
                queue[rear][1] = ny;
                rear++;
                before[nx][ny][0] = fx;
                before[nx][ny][1] = fy;
                if(nx == (n - 1) && ny == (m - 1))
                    return;
            }
        }
        front++;
    }
    return;
}


int main()
{
    n = 5;
    m = 5;
    ans = 0;
    front = 0;
    rear = 0;
    for(int i = 0; i < n ; i++)
        for(int j = 0; j < m; j++)
        {
            cin>>a[i][j];
            visit[i][j] = 0;
            before[i][j][0]= 0;
            before[i][j][1] = 0;
        }
    bfs(0,0);

    int ii = 4,jj = 4;
    int cnt = 1;
    int save[25][2];
    while(!(ii == 0 &&jj ==0))
    {
        save[cnt][0] = before[ii][jj][0];
        save[cnt][1] = before[ii][jj][1];
        ii = save[cnt][0];
        jj = save[cnt][1];
        cnt++;
    }

    for(int i =cnt - 1;i >= 1;i--)
        cout<<'('<<save[i][0]<<", "<<save[i][1]<<')'<<endl;
    cout<<"(4, 4)"<<endl;
    return 0;
}
