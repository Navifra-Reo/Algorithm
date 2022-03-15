#include <stdio.h>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

void solution()
{
    int n, v, t;
    pair<int, int> ans[101] = {0};
    vector<pair<pair<int, int>, int>> edge[101];
    priority_queue<pair<pair<int, int>, int>> pq;
    cin >> n >> v >> t;
    for (int i = 0; i <= n; i++)
    {
        int a, b, value, time;
        cin >> a >> b >> value >> time;
        edge[a].push_back({{time, -value}, b});
    }
    pq.push({{0, 0}, 1});
    while (!pq.empty())
    {
        pair<pair<int, int>, int> k = pq.top();
        for (int i = 0; i < edge[k.second].size(); i++)
        {
            int dist = edge[k.second][i].second;
            ans[dist] > k.first.first + edge[k.second][i].first.
        }
    }
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solution();
    }
    return 0;
}