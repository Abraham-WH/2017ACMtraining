#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

char in[1000];
int dp[1000][1000],n,num;//�ӵ�i������j�������м���Ҫ�ӵĸ���������������DP  1.����ѭ��2.�̶�����ͷβѭ��  ת�Ʒ��̣�3.�����м��ѭ�����ָ����� ת�Ʒ��̣�

bool test(char a,char b)//�ж�a,b�Ƿ�ƥ��
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
        dp[i][i]=1;//���ַ���Ҫ1��
    for(int len=1; len<=n; len++)//��ʼ����dp  ���䳤��  ע���������
    {
        for(int l=1,r; (r=l+len)<=n; l++)//�������Ҷ˵㣬�Ƿ�ƥ��
        {
            dp[l][r] = r - l + 1;//�������߽�
            if(test(in[l],in[r]))
            {
                dp[l][r] = mmin(dp[l][r],dp[l + 1][r - 1]);//ƥ���ת�Ʒ���  ��[][]��ת�Ƶ�][,�����������С

            }
            for(int k = l; k < r; k++)
            {
                dp[l][r] = mmin(dp[l][r],dp[l][k] + dp[k + 1][r]);//�����ڲ���������С
            }
        }
    }
}

void display(int l,int r)
{
    if(l > r) return;
    if(l == r) //��ӡ���ַ�
    {
        if(in[l] == '(' || in[l] == ')')
            cout<<"()";
        if(in[l] == '[' || in[l] == ']')
            cout<<"[]";
        return;
    }
    int temp = dp[l][r];
    if(test(in[l],in[r]) && temp == dp[l + 1][r - 1])//����ƥ��ʱ
    {
        cout<<in[l];
        display(l + 1,r - 1);//�ݹ鴦���м�������
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
        n=strlen(in+1);//���ĳ���
        while(in[n]=='\n'||in[n]=='\r')
            n--;
        searchnum();//��ȷ�������Ž⣬��ͨ��������ӡ
        display(1,n);
        cout<<endl;
    }
    return 0;
}
