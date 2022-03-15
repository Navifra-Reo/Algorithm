#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, ans = 0;
vector<pair<int, int>> d[10001];

int f(int node, int parent)
{
    int fir = 0, sec = 0;
    for (int i = 0; i < d[node].size(); i++)
    {
        int k;
        if (d[node][i].first == parent)
            continue;
        k = f(d[node][i].first, node) + d[node][i].second;
        if (fir < k)
        {
            sec = fir;
            fir = k;
        }
        else if (sec < k)
        {
            sec = k;
        }
    }
    if (ans < fir + sec)
        ans = fir + sec;
    return fir;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[a].push_back({b, c});
        d[b].push_back({a, c});
    }
    f(1, 0);
    cout << ans;
    return 0;
}
