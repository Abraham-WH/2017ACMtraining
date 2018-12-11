#include <iostream>

using namespace std;

int T;
int n;//10e5
int q;//50000
int num[100001];
int lower;
int upper;

void init();
int Bsearchup();
int Bsearchlow();

void init()
{
    cin>>n;
    cin>>q;
    for ( int i = 1; i < n + 1; i++)
        cin>>num[i];
}

int Bsearchup(int k)
{
    int low = 1;
    int up = n;
    int mid;
    while(low <= up)
    {
        mid = (low + up) / 2;
        if(num[mid] <= k)
            low = mid + 1;
        else up = mid - 1;
    }
    return low;
}

int Bsearchlow(int k)
{
    int low = 1;
    int up = n;
    int mid;
    while(low <= up)
    {
        mid = (low + up) / 2;
        if(num[mid] < k)
            low = mid + 1;
        else up = mid - 1;
    }
    return low;
}

int main()
{
    cin>>T;
    for(int i = 1; i < T + 1; i++)
    {
        init();
        cout<<"Case"<<' '<<T<<":"<<endl;
        for (int i = 1; i < q + 1; i++)
        {
            cin>>lower;
            cin>>upper;
            lower = Bsearchlow(lower);
            upper = Bsearchup(upper);
            cout<< upper - lower<<endl;
        }
    }
    return 0;
}
