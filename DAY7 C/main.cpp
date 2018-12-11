#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
//���ʶ�Ӧ�������ƣ������Ӧ����������Ӧ��Ʒ��������������Ϊdouble����ͬ��������
double p,w[105],safe[105];//�ܸ��ʣ���������,������ȫ����
int v[105],n,c,mmoney,ans,i,j;//�������棬�¼������ܰ���
double dp[105 * 105];//����Ϊjʱ����ȫʱ�ĸ��� ��ת��״̬����

double max(double a,double b)
{
    return a > b ? a : b;
}

void solve()//����
{
    dp[0] = 1.0;
    for(i = 1; i <= n; i++)//�ڼ�������
        for(j = mmoney; j >= v[i]; j--)
            dp[j] = max(dp[j],dp[j - v[i]] * safe[i]);//���ţ��ţ�����
    for(j = mmoney; j >= 0; j--)
    {
        if(dp[j]-(1.0 - p)>0.000000001)//��������
        {
            ans = j;
            break;
        }
    }
    return ;
}

int main()
{
    cin>>c;
    for(int k = 0; k < c; k++)
    {
        cin>>p>>n;//������������
        mmoney = 0;
        ans = 0;
        for(int i = 1; i <= n; i++)
        {
            cin>>v[i]>>w[i];
            mmoney += v[i];
            safe[i] = 1 - w[i];
        }
        memset(dp,0,sizeof(dp));
        solve();
        cout<<ans<<endl;//������Ϊm������ֵ
    }
    return 0;
}
