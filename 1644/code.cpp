#include<iostream>
#include<map>
using namespace std;

long long list[4000001];
map<long long, bool> d;
int n,ans=0;

bool isprime(int k)
{
    for(int i=2;i*i<=k;i++)
    {
        if(k%i==0)return false;
    }
    return true;
}
int main()
{
    long long t=0;
    int idx=0;
    d[0]=true;
    cin >> n;
    for(int i=2;i<=n;i++)
    {
        if(isprime(i))
        {
            t+=i;
            d[t]=true;
            list[++idx]=t;
        }
    }
    for(int i=idx;i>=0;i--)
    {
        if(list[i]<n) break;
        if(d[list[i]-n])ans++;
    }
    cout << ans;
    return 0;
}