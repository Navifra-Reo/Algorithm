#include <iostream>
using namespace std;

int n;
int d[801][801];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int e;

    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = c;
        d[b][a] = c;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (k == i)
                continue;
            for (int j = 1; j <= n; j++)
            {
                if (d[i][k] * d[k][j] == 0 || i == j || j == k)
                    continue;
                if (d[i][j] > d[i][k] + d[k][j] || d[i][j] == 0)
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }

    int a, b, min = 0;
    cin >> a >> b;
    if (d[1][n] == 0 || d[a][b] == 0 || d[1][b] == 0 || d[a][n] == 0)
    {
        cout << -1;
        return 0;
    }
    int a1 = d[1][a] + d[a][b] + d[b][n];
    int a2 = d[1][b] + d[b][a] + d[a][n];
    min = a1 > a2 ? a2 : a1;
    cout << min;
    return 0;
}