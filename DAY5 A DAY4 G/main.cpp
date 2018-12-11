#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int n,m,t;
int a[10][10];//0������,1���У�2�յ�
int visit[10][10];
char ch;
int sx,sy;//���
int dx,dy;//�յ�
int flag;
int stop;//�ϰ���
int cnt;//��ǰʱ��
int next[4][2] = {0,-1,0,1,1,0,-1,0};
void dfs(int x,int y,int cnt)//��ǰ����
{
    if(x <= 0 || x >n || y <= 0 || y > m || cnt > t)
        return;//����
    if(cnt == t && x == dx && y == dy)
    {
        flag = 1;
        return;//�ҵ��յ㣬ʱ�����
    }

    int s1,s2;
    if((dx -x) >= 0)
        s1 = dx - x;
    else s1 = x - dx;
    if((dy - y) >= 0)
        s2 = dy - y;
    else s2 = y - dy;
    if((s1 +s2) > t || (t - cnt - x + sx - y + sy) % 2 != 0)//���·����ż��֦
    //   if((s1 +s2) > t )  return;
    for(int i = 0; i < 4 ; i++)
    {
        for(int j = 0; j <2; j++)
        {
            if( a[x + i][y + j] != 0)//��һ������
            {
                a[x + i][y + j] = 0;//����һ��
                cnt++;
                dfs(x + i,y + j,cnt);
                a[x + i][y + j] = 1;//������һ��
                cnt--;
            }
        }
    }
}

int main()
{
    while(scanf("%d%d%d",&n,&m,&t) == 3)
    {
        if(!n && !m && !t)
            break;
        flag = 0;
        stop = 0;
        cnt = 0;
        getchar();//ע��getchar������
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                scanf("%c",&ch);
                if(ch == 'S')
                {
                    sx = i;
                    sy = j;//���
                    a[i][j] = 1;
                }
                else if(ch == 'D')
                {
                    dx = i;
                    dy = j;
                    a[i][j] = 2;
                }
                else if(ch == 'X')
                {
                    a[i][j] = 0;
                    stop++;
                }
                else if(ch == '.') a[i][j] = 1;
            }
            getchar();
        }
        if(((dx - sx + dy - sy - t) % 2) != 0)//��ż��֦
        {
            cout<<"NO"<<endl;
            continue;
        }
        int s1,s2;
        if((dx - sx) >= 0)
            s1 = dx - sx;
        else s1 = sx - dx;
        if((dy - sy) >= 0)
            s2 = dy - sy;
        else s2 = sy - dy;
        if((s1 + s2) > t)//���·����ʱ��
        {
            cout<<"NO"<<endl;
            continue;
        }
        dfs(sx,sy,0);
        if(flag == 1)
        {
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}
