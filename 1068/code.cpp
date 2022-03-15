#include <iostream>
#include <vector>

using namespace std;
vector<int> d[50];
int n, e;

int dfs(int node)
{
    int leafCount = 0;
    for (int i = 0; i < d[node].size(); i++)
    {
        if (d[node][i] == e)
            continue;
        leafCount += dfs(d[node][i]);
    }
    if (leafCount == 0)
        return 1;
    return leafCount;
}

int main()
{
    int root = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if (t == -1)
            root = i;
        d[t].push_back(i);
    }
    cin >> e;
    if (e == root)
    {
        cout << 0;
        return 0;
    }
    cout << dfs(root);
    return 0;
}