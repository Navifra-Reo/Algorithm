#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

int n, m;
int d[51][51];

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int k, ans;
    queue<int> known;

    cin >> n >> m;
    cin >> k;
    ans = m;
    for (int i = 1; i <= k; i++)
    {
        int temp;
        cin >> temp;
        d[temp][0] = 1;
        known.push(temp);
    }
    for (int i = 1; i <= m; i++)
    {
        int temp;
        cin >> temp;
        for (int j = 0; j < temp; j++)
        {
            int tmp;
            cin >> tmp;
            d[tmp][i] = 1;
        }
    }

    while (!known.empty())
    {
        int temp = known.front();
        for (int p = 1; p <= m; p++)
        {
            if (d[temp][p])
            {
                if (d[0][p] == 0)
                    ans--;
                d[0][p] = 1;
                for (int i = 1; i <= n; i++)
                {
                    if (d[i][p] && d[i][0] == 0)
                    {
                        known.push(i);
                        d[i][0] = 1;
                    }
                }
            }
        }
        known.pop();
    }
    cout << ans;
    return 0;
}