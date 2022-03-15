#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int n;

vector<ll> a;
vector<ll> b;
ll sum[8000000];
ll ans = 0, d;

void getSum(int depth, ll s)
{
    if (depth >= a.size())
    {
        sum[s + 3000000]++;
        return;
    }
    getSum(depth + 1, s + a[depth]);
    getSum(depth + 1, s);
    return;
}
void checkSum(int depth, ll s)
{
    if (depth >= b.size())
    {
        ans += sum[(d - s) + 3000000];
        return;
    }
    checkSum(depth + 1, s + b[depth]);
    checkSum(depth + 1, s);
    return;
}

int main()
{
    cin >> n >> d;
    for (int i = 1; i <= n / 2; i++)
    {
        int t;
        cin >> t;
        a.push_back(t);
    }
    for (int i = n / 2 + 1; i <= n; i++)
    {
        int t;
        cin >> t;
        b.push_back(t);
    }
    getSum(0, 0);
    checkSum(0, 0);
    if (d == 0)
        ans--;
    cout << ans;
}