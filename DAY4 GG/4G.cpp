#include<stdio.h>
#include<string.h>
int flag,sx,sy,ex,ey,num;
int n,m,t,vis[10][10];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
char map[10][10];
int abs(int p)
{
	return p>=0?p:-p;
}
void dfs(int x,int y,int sum)
{
	int i,xx,yy;
	if(flag==1)
		return;
	if(x==ex&&y==ey&&sum==t)
	{
		flag=1;
		return;
	}
	int mindis=abs(x-ex)+abs(y-ey);  /*当前点到终点的最短距离*/
	if(mindis>t-sum||(mindis+ t-sum )%2!=0)
		return;
	for(i=0;i<4;i++)
	{
		xx=x+dx[i];
		yy=y+dy[i];
		if(xx>=0&&xx<n&&yy>=0&&yy<m&&!vis[xx][yy]&&map[xx][yy]!='X')  /*在map范围内且可以继续搜下去*/
		{
			vis[xx][yy]=1;
			dfs(xx,yy,sum+1);
			vis[xx][yy]=0;
		}
	}
}
int main()
{
	int i,j;
	while(~scanf("%d%d%d",&n,&m,&t))
	{
		if(n==0&&m==0&&t==0)
			break;
		num=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",map[i]);
			for(j=0;j<m;j++)
			{
				if(map[i][j]=='S')
				{
					sx=i;
					sy=j;  /*记录起点坐标*/
				}
				if(map[i][j]=='D')
				{
					ex=i;
					ey=j; /*记录终点坐标*/
				}
				if(map[i][j]=='X')
					num++;  /*记录墙的数量*/
			}
		}
		if(n*m-num-1<t)
        {
            printf("NO\n");
            continue;
        }
        flag = 0;
        memset(vis, 0, sizeof(vis));
        vis[sx][sy] = 1;
           dfs(sx, sy, 0);
        if(flag)
           printf("YES\n");
        else
           printf("NO\n");
	}
	return 0;
}
