#include <iostream>
#include <queue>
#include <functional> // greater, less
#include <cstdlib>
using namespace std;

struct compare
{
    bool operator()(int a, int b)
    {
        if (abs(a) == abs(b))
            return a > b;
        return abs(a) > abs(b);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    priority_queue<int, vector<int>, compare> pq; // - >  priority_queue<int, vector<int>, less<int>> pq;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        if (temp == 0)
        {
            if (pq.empty())
            {
                cout << 0 << '\n';
                continue;
            }
            cout << pq.top() << '\n';
            pq.pop();
            continue;
        }
        pq.push(temp);
    }
    return 0;
}