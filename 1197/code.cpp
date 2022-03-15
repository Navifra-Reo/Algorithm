#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int v, e, ans = 0;
int d[10001];
priority_queue<pair<int, pair<int, int>>> edge;

int find(int x)
{
    if (d[x] == x)
        return x;
    d[x] = find(d[x]);
    return d[x];
}

bool combine(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x == y)
        return true;

    d[x] = y;
    return false;
}
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> v >> e;

    for (int i = 1; i <= v; i++)
        d[i] = i;

    for (int i = 1; i <= e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push({-c, {a, b}});
    }
    while (!edge.empty())
    {
        pair<int, pair<int, int>> k = edge.top();
        edge.pop();
        if (combine(k.second.first, k.second.second))
            continue;
        ans -= k.first;
    }

    cout << ans;
    return 0;
}