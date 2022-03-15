#include <iostream>
using namespace std;
int d[1000];
int a[1000];
int b[1000];
int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    for (int i = 0; i < n; i++)
    {
        int max = 0;
        for (int j = 0; j < i; j++)
        {
            if (a[j] + 1 > a[i] && d[i] > d[j])
            {
                a[i] = a[j] + 1;
            }
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int max = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (b[j] + 1 > b[i] && d[i] > d[j])
            {
                b[i] = b[j] + 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        ans = ans < a[i] + b[i] ? a[i] + b[i] : ans;
    }
    cout << ans + 1;
    return 0;
}