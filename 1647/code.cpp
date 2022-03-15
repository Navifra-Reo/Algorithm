#include <iostream>
#include <queue>
using namespace std;

int e, v;
int group[100001];
priority_queue<pair<int, pair<int, int>>> d;

void init(int k)
{
    for (int i = 1; i <= k; i++)
        group[i] = i;
}
int Find(int x)
{
    if (group[x] == x)
        return x;
    return group[x] = Find(group[x]);
}
void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x != y)
        group[y] = x;
}

int main()
{
    cin >> e >> v;
    init(e);
    for (int i = 0; i < v; i++)
    {
        int sp, ep, value;
        cin >> sp >> ep >> value;
        d.push({-value, {sp, ep}});
    }
    int cnt = 0, ans = 0;
    while (cnt + 1 < e - 1 && !d.empty())
    {
        int t = -d.top().first;
        int x = d.top().second.first;
        int y = d.top().second.second;
        d.pop();
        if (Find(x) == Find(y))
            continue;
        Union(x, y);
        cnt++;
        ans += t;
    }
    cout << ans;
    return 0;
}