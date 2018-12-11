#include <iostream>
using namespace std;

int n,sum;
int ans[12],sel[12];

int Abs(int n)  //求绝对值
{
    return n>0?n:-n;
}

void f(int h) //确定第i行的皇后位置
{
    if(h>n)     //成功，计数+1
    {
        ++sum;
        return ;
    }
    int i,x,y;    //（x，y）假定要放置的位置
    x = h;  //确定纵坐标
    for(y=1; y<=n; y++) //确定横坐标
    {
        //检测竖直方向，横着的方向就不用检测了，因为是一行行来的
        for(i=1; i<x; i++)
            if(y==sel[i])
                break;
        if(i<x)     //失败
            continue;
        //检测斜着的方向
        for(i=1; i<x; i++)
            if(Abs(sel[i]-y)==x-i)
                break;
        if(i<x)    //失败
            continue;

        sel[x] = y; //通过检测，存储当前位置的横坐标
        f(h+1);
    }
}

int main()
{
    for(n=1; n<=10; n++) //打表
    {
        sum = 0;
        f(1);
        ans[n] = sum;
    }
    while(cin>>n)
    {
        if(n==0) break;
        cout<<ans[n]<<endl;
    }
    return 0;
}
