#include<cstdio>
#include<cstdlib>
#include<cstring>

int len[65];
bool used[65];
int sum,L,n;

int cmp(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;
}

bool DFS(int m,int left)    //mΪʣ���δ�õ�ľ������leftΪ��ǰ����ƴ�ӵ�ľ���ͼٶ���ľ������L�Ȼ�ȱ�ٵĳ���
{
    if(m==0&&left==0)
        return true;
    if(left==0)     //һ���ո�ƴ�꿪ʼƴ�µ�һ��
        left=L;
    for(int i=0; i<n; ++i)
    {
        if(!used[i]&&len[i]<=left)
        {
            if(i>0)
            {
                if(!used[i-1]&&len[i]==len[i-1])    //��һ�μ�֦��
                    continue;                        //�����ǰ��û�ù��İ��Ӳ����ã���ô����������ͬ��δʹ�õİ���Ҳ�����ã�ֱ������
            }
            used[i]=true;
            if(DFS(m-1,left-len[i]))
                return true;
            else
            {
                used[i]=false;//˵��������i��Ϊ��һ������ôҪ����ǰ��ľ����i������������ǰ��ľ���У����Ի���
                if(len[i]==left||left==L)  //��Ҫ��֦---����Ҫ����ᳬʱ
                    return false;          //����ʼ����һ֧��Ϊ L ��ľ��ʱ�����������Ե�ǰ���δ
            }                               //��ʹ�õ� ľ����ʼ������������ɹ�����ô�Ա����̵Ŀ�ʼ
        }                                   //Ҳһ������ȡ��ȫ�ֵĳɹ�����Ϊÿһ֧��Ŀ������ľ����Ҫ���õ���
    }                                       //������ʱ16Ms��ȥ��len[i]==left�������(��̫��---����˵��ǰľ�������һ��ľ��  )���47Ms����ȥ��left--L��������ᳬʱ
    return false;
}

int main()
{
    while(scanf("%d",&n),n)
    {
        sum=0;
        for(int i=0; i<n; ++i)
        {
            scanf("%d",&len[i]);
            sum+=len[i];
        }
        qsort(len,n,sizeof(int),cmp);
        for(L=len[0]; L<=sum/2; ++L)
        {
            if(sum%L)
                continue;
            memset(used,false,sizeof(used));
            if(DFS(n,L))
            {
                printf("%d\n",L);
                break;
            }
        }
        if(L>sum/2)
            printf("%d\n",sum);
    }
    return 0;
}
