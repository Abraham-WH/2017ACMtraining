#include <iostream>
using namespace std;

int n,sum;
int ans[12],sel[12];

int Abs(int n)  //�����ֵ
{
    return n>0?n:-n;
}

void f(int h) //ȷ����i�еĻʺ�λ��
{
    if(h>n)     //�ɹ�������+1
    {
        ++sum;
        return ;
    }
    int i,x,y;    //��x��y���ٶ�Ҫ���õ�λ��
    x = h;  //ȷ��������
    for(y=1; y<=n; y++) //ȷ��������
    {
        //�����ֱ���򣬺��ŵķ���Ͳ��ü���ˣ���Ϊ��һ��������
        for(i=1; i<x; i++)
            if(y==sel[i])
                break;
        if(i<x)     //ʧ��
            continue;
        //���б�ŵķ���
        for(i=1; i<x; i++)
            if(Abs(sel[i]-y)==x-i)
                break;
        if(i<x)    //ʧ��
            continue;

        sel[x] = y; //ͨ����⣬�洢��ǰλ�õĺ�����
        f(h+1);
    }
}

int main()
{
    for(n=1; n<=10; n++) //���
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
