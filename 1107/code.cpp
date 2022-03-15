#include <iostream>
#include <cstdlib>
using namespace std;

int g, ans;
bool d[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

void f(int n, int depth)
{
    if (depth > 7)
        return;

    if (depth > 0)
    {
        ans = abs(g - n) + depth < ans ? abs(g - n) + depth : ans;
    }
    for (int i = 0; i < 10; i++)
    {
        if (!d[i] || (n == 0 && i == 0 && depth > 0))
            continue;
        f(n * 10 + i, depth + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;

    cin >> g >> k;
    for (int i = 1; i <= k; i++)
    {
        int temp;
        cin >> temp;
        d[temp] = 0;
    }

    ans = abs(100 - g);
    f(0, 0);
    cout << ans;
    return 0;
}