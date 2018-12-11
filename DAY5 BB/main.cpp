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

bool DFS(int m,int left)    //m为剩余的未用的木棒数，left为当前正在拼接的木棒和假定的木棒长度L比还缺少的长度
{
    if(m==0&&left==0)
        return true;
    if(left==0)     //一根刚刚拼完开始拼新的一根
        left=L;
    for(int i=0; i<n; ++i)
    {
        if(!used[i]&&len[i]<=left)
        {
            if(i>0)
            {
                if(!used[i-1]&&len[i]==len[i-1])    //第一次剪枝：
                    continue;                        //如果当前的没用过的棒子不可用，那么和他长度相同的未使用的棒子也不可用，直接跳过
            }
            used[i]=true;
            if(DFS(m-1,left-len[i]))
                return true;
            else
            {
                used[i]=false;//说明不能用i作为第一条，那么要拆以前的木棒，i还可能用在以前的木棒中，所以回溯
                if(len[i]==left||left==L)  //重要剪枝---很重要否则会超时
                    return false;          //将开始搜索一支长为 L 的木棍时，我们总是以当前最长的未
            }                               //被使用的 木棍开始，如果搜索不成功，那么以比它短的开始
        }                                   //也一定不能取得全局的成功。因为每一支题目给出的木棍都要被用到。
    }                                       //这里用时16Ms，去掉len[i]==left这个条件(不太懂---网上说当前木棒是最后一根木棒  )变成47Ms，而去掉left--L这个条件会超时
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
