#include<iostream>
#include<algorithm>
using namespace std;
long long c[100005],sz[100005],cnt, k;

void merge(int first,int mid,int end)
{
    int i,j;
    i = first;
    j = mid+1;
    int k = 0;
    while(i <= mid || j <= end)
    {
        if(j > end || (i <= mid && sz[i] <= sz[j]))
            c[k++] = sz[i++];
        else
        {
            c[k++] = sz[j++];
            cnt += mid - i + 1;
        }
    }
    for(i = 0; i < k; i++)
        sz[i + first] = c[i];
}

void merge_sort(int first,int end)
{
    if(first == end) return;
    int mid = (first + end) / 2;
    merge_sort(first,mid);
    merge_sort(mid + 1,end);
    merge(first,mid,end);
}

int main()
{
    int n;
    long long i;
    long long result;
    while(cin >> n && cin >> k)
    {
        for(i = 0; i < n; i++)
            cin >> sz[i];
        merge_sort(0,n-1);

        if(k >= cnt)
            result = 0;
        else
            result = cnt - k;
        cout << result << endl;
        cnt = 0;
    }
}
