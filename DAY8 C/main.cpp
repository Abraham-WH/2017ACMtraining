#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

char in[1000];
int dp[1000][1000],n,num;//从第i个到第j个符号中间需要加的个数————区间DP  1.长度循环2.固定区间头尾循环  转移方程？3.区间中间点循环，分个区间 转移方程？

bool test(char a,char b)//判断a,b是否匹配
{
    if(a=='(')return b==')';
    if(a=='[')return b==']';
    return 0;
}

int mmin(int a,int b)
{
    return a <= b ? a : b;
}

void searchnum()
{
    for(int i=1; i<=n; i++)
        dp[i][i]=1;//单字符需要1个
    for(int len=1; len<=n; len++)//开始区间dp  区间长度  注意遍历方向
    {
        for(int l=1,r; (r=l+len)<=n; l++)//区间左右端点，是否匹配
        {
            dp[l][r] = r - l + 1;//最坏情况，边界
            if(test(in[l],in[r]))
            {
                dp[l][r] = mmin(dp[l][r],dp[l + 1][r - 1]);//匹配的转移方程  如[][]可转移到][,尽量将区间分小

            }
            for(int k = l; k < r; k++)
            {
                dp[l][r] = mmin(dp[l][r],dp[l][k] + dp[k + 1][r]);//区间内部划分找最小
            }
        }
    }
}

void display(int l,int r)
{
    if(l > r) return;
    if(l == r) //打印单字符
    {
        if(in[l] == '(' || in[l] == ')')
            cout<<"()";
        if(in[l] == '[' || in[l] == ']')
            cout<<"[]";
        return;
    }
    int temp = dp[l][r];
    if(test(in[l],in[r]) && temp == dp[l + 1][r - 1])//左右匹配时
    {
        cout<<in[l];
        display(l + 1,r - 1);//递归处理中间子区间
        cout<<in[r];
        return;
    }
    for(int k = l; k < r; k++)
    {
        if(temp == dp[l][k] + dp[k + 1][r])
        {
            display(l,k);
            display(k + 1,r);
            return;
        }
    }
}

int main()
{
    cin >> num;
    getchar();
    for(int i = 0; i < num ; i++)
    {
        gets(in+1);
        n=strlen(in+1);//串的长度
        while(in[n]=='\n'||in[n]=='\r')
            n--;
        searchnum();//先确定好最优解，在通过遍历打印
        display(1,n);
        cout<<endl;
    }
    return 0;
}
