#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long

using namespace std;

vector<int> l;

ll d[1000001];
ll k[1000001];
ll value[1000001];
ll n,kk;

void print(int idx)
{
    if(idx==k[idx])return;
    print(k[idx]);
    cout << value[idx] << ' ';
    return;
}

int main()
{
    cin >> n;
    l.push_back(-2000000000);
    for(int i=1;i<=n;i++)
    {
        ll t,idx;
        cin >> t;
        value[i]=t;
        idx = lower_bound(l.begin(),l.end(),t)-l.begin();
        if(idx==l.size())
        {
            kk=i;
            l.push_back(t);
        }
        l[idx]=t;
        d[idx]=i;
        k[i]=d[idx-1];
    }
    cout << l.size()-1 << '\n';
    print(kk);
    return 0;
}