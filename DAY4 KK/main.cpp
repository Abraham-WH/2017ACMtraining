#include <iostream>
#include <string.h>
using namespace std;
int t,flag;
int arr[15][15];
int col[15][15],row[15][15],nine[15][15];
void out()
{
	for (int i=1;i<=9;i++)
		for (int j=1;j<=9;j++)
		{
			cout<<arr[i][j];
			if (j==9) cout<<endl;
		}
	return;
}

int cal(int x,int y)
{
	return (x-1)/3*3+(y-1)/3+1;
}

int can(int x,int y,int t)
{
	if (col[x][t]==1 || row[y][t]==1 || nine[cal(x,y)][t]==1)
		return 0;
	return 1;
}

void ins(int x,int y,int t,int f)
{
	col[x][t]=row[y][t]=nine[cal(x,y)][t]=f;
	return;
}

void dfs(int x,int y)
{
	if (x==10)
	{
		out();
		flag=1;
		return;
	}
	if (flag) return;
	if (arr[x][y])
	{
		if (y==9) dfs(x+1,1);
		else dfs(x,y+1);
		return;
	}
	for (int now=1;now<=9;now++)
	if (can(x,y,now))
	{
		ins(x,y,now,1);
		arr[x][y]=now;
		if (y==9) dfs(x+1,1);
		else dfs(x,y+1);
		arr[x][y]=0;
		ins(x,y,now,0);
	}
}

int main()
{
	cin>>t;
	while (t--)
	{
		flag=0;
		char c;
		for (int i=1;i<=9;i++)
			for (int j=1;j<=9;j++)
			{
				cin>>c;
				arr[i][j]=c-'0';
				if (arr[i][j]!=0)
					ins(i,j,arr[i][j],1);
			}
		dfs(1,1);
		memset(arr,0,sizeof(arr));
		memset(col,0,sizeof(col));
		memset(row,0,sizeof(row));
		memset(nine,0,sizeof(nine));
	}
}
