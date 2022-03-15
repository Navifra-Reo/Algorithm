#include <iostream>
#include <queue>
#include <map>

using namespace std;

priority_queue<long long> pq_desc;
priority_queue<long long> pq_inc;
map<long long, int> m;
void insert(long long key)
{
    pq_desc.push(key);
    pq_inc.push(-key);
    m[key]++;
}
void delete_top()
{
    long long v;
    do
    {
        if (pq_desc.empty())
            return;

        v = pq_desc.top();
        pq_desc.pop();

    } while (m[v] == 0);

    m[v]--;
}
void delete_bottom()
{
    long long v;
    do
    {
        if (pq_inc.empty())
            return;

        v = -pq_inc.top();
        pq_inc.pop();

    } while (m[v] == 0);

    m[v]--;
}

void solve()
{
    m.clear();
    pq_desc = priority_queue<long long>();
    pq_inc = priority_queue<long long>();

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char c;
        long long k;
        cin >> c >> k;
        if (c == 'I')
        {
            insert(k);
        }
        else if (k == 1)
            delete_top();
        else if (k == -1)
            delete_bottom();
    }

    while (!pq_desc.empty() && m[pq_desc.top()] == 0)
        pq_desc.pop();
    while (!pq_inc.empty() && m[-pq_inc.top()] == 0)
        pq_inc.pop();

    if (pq_desc.empty() || pq_inc.empty())
    {
        cout << "EMPTY" << endl;
        return;
    }
    cout << pq_desc.top() << ' ' << -pq_inc.top() << endl;
}

int main()
{
    int t;

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}