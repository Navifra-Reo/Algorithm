#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
long long ans;

vector<pair<int, int>> jewel;
vector<int> bag;
priority_queue<int> pq;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first <= b.first;
}

int main()
{
    cin.tie(0); // cin 실행속도 향상
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        jewel.push_back({a, b});
    }
    for (int i = 0; i < k; i++)
    {
        int b;
        cin >> b;
        bag.push_back(b);
    }
    sort(jewel.begin(), jewel.end(), compare);
    sort(bag.begin(), bag.end());
    int j = 0;
    for (int i = 0; i < k; i++)
    {
        for (; j < n; j++)
        {
            if (jewel[j].first > bag[i])
                break;
            pq.push(jewel[j].second);
        }
        if (pq.empty())
            continue;
        ans += pq.top();
        pq.pop();
    }
    cout << ans;
    return 0;
}