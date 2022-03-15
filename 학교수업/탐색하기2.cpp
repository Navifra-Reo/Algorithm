#include <iostream>
#include <string>
using namespace std;
string d[10000];
int main()
{
    int n, s = -1, e = -1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
        // i번째 문자열이 아주대학교인지 확인한다
        if (d[i] == "AJOU")
        {
            // s가 갱신되었는지 확인하고 갱신이 되어있으면 e를 않으면 s에 값을 갱신한다.
            if (s == -1)
                s = i;
            else
                e = i;
        }
    }

    cout << s + 1 << ' ' << e + 1;
    return 0;
}