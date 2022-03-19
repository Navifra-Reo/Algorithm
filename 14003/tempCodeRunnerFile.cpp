#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> l;

int d[1000001];
int k[1000001];
int dd[1000001];
int n,kk;

void print(int idx)
{
    if(idx==k[idx])return;
    print(k[idx]);
    cout << dd[idx] << ' ';
    return;
}

int main()
{
    cin >> n;
    l.push_back(0);
    for(int i=1;i<=n;i++)
    {
        int t,idx;
        cin >> t;
        dd[i]=t;
        idx = lower_bound(l.begin(),l.end(),t)-l.begin();
        if(idx==l.size())
        {
            kk=i;
            l.push_back(t);
        }
        d[idx]=i;
        l[idx]=t;
        k[i]=d[idx-1];
    }
    print(kk);
    return 0;
}