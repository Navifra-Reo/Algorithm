#include <iostream>
using namespace std;
int main()
{
    long long int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        // 1~i���� ���� ans �� ����
        ans += (1 + i) * i / 2;
    }
    cout << ans;

    return 0;
}