#include <iostream>
using namespace std;

int n;
int d[21][21];
int s[21][21];

int ver(int x1, int y1, int x2, int y2);
int hor(int x1, int y1, int x2, int y2);

int getjewel(int x1, int y1, int x2, int y2)
{
    return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}
int hor(int x1, int y1, int x2, int y2)
{
    int jewel = getjewel(x1, y1, x2, y2);
    if (jewel <= 1)
    {
        return jewel;
    }
    int sum = 0;
    for (int i = x1; i <= x2; i++)
    {
        for (int j = y1; j <= y2; j++)
        {
            if (d[i][j] == 1 && getjewel(i, y1, i, y2) == 0)
            {
                sum += ver(x1, y1, i - 1, y2) * ver(i + 1, y1, x2, y2);
            }
        }
    }
    return sum;
}

int ver(int x1, int y1, int x2, int y2)
{
    int jewel = getjewel(x1, y1, x2, y2);

    if (jewel <= 1)
    {
        return jewel;
    }
    int sum = 0;
    for (int i = x1; i <= x2; i++)
    {
        for (int j = y1; j <= y2; j++)
        {
            if (d[i][j] == 1 && getjewel(x1, j, x2, j) == 0)
            {
                sum += hor(x1, y1, x2, j - 1) * hor(x1, j + 1, x2, y2);
            }
        }
    }
    return sum;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int t;
            cin >> t;
            d[i][j] = t;
            if (t > 0)
                t--;
            s[i][j] = t + (s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1]);
        }
    }
    int ans = hor(1, 1, n, n) + ver(1, 1, n, n);
    if (ans == 0)
        ans = -1;
    cout << ans;
    return 0;
}