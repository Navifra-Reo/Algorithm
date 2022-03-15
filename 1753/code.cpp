#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
int v, e, s;
int d[20001];
bool visit[20001] = {false};
vector<pair<int, int>> edge[20001];

struct cmp
{
    //연산자 오버로딩
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.second == b.second)
        {
            return a.first > b.first;
        }
        else
        {
            return a.second > b.second;
        }
    }
};
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> dd;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> v >> e;
    cin >> s;

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back(make_pair(b, c));
        if (a == s)
        {
            // dd.push(make_pair(b, c));
            // d[b] = c;
        }
    }
    dd.push({s, 0});

    while (!dd.empty())
    {
        int k = 0, min = 0;
        k = dd.top().first;
        min = dd.top().second;
        dd.pop();
        cout << k << ", " << min << endl;
        if (visit[k])
            continue;
        visit[k] = true;

        for (int i = 0; i < edge[k].size(); i++)
        {
            if (edge[k][i].second + min < d[edge[k][i].first] || d[edge[k][i].first] == 0)
            {
                d[edge[k][i].first] = edge[k][i].second + min;
                dd.push(make_pair(edge[k][i].first, edge[k][i].second + min));
            }
        }
    }
    for (int i = 1; i <= v; i++)
    {
        if (i == s)
            cout << "0\n";
        else if (d[i] == 0)
            cout << "INF\n";
        else
            cout << d[i] << '\n';
    }

    return 0;
}
