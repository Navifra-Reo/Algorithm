#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int> d;
int count[32001];
vector<int> k[32001];
int v, e;
int main()
{
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        count[b]++;
        k[a].push_back(b);
    }
    for (int i = 1; i <= v; i++)
    {
        if (count[i] == 0)
        {
            d.push(-i);
        }
    }
    while (!d.empty())
    {
        int t = -d.top();
        d.pop();
        cout << t << ' ';
        for (int i = 0; i < k[t].size(); i++)
        {
            count[k[t][i]]--;
            if (count[k[t][i]] == 0)
            {
                d.push(-k[t][i]);
            }
        }
    }
    return 0;
}