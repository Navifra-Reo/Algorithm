#include <iostream>
using namespace std;
int d[10000];
int main()
{
    int n, p, q, sum = 0, count = 0;
    cin >> n >> p >> q;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;

        //입력과 동시에 해당 인원이 무게제한에 걸리는지 확인
        if (p >= t)
        {
            //무게 제한에 걸리지 않는경우 체중제한에 걸리지 않은 인원값에 1을 더하고 체중을 합 변수에 더한다.
            count++;
            sum += t;
        }
    }
    // 체중제한에 걸리지 않은 사람의 수와 해당 사람들의 체중의 합을 출력한다.
    cout << count << ' ' << sum << '\n';

    //체중의 합이 q보다 크면 NO, 작거나 같으면 YES를 출력한다/
    if (sum > q)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }
    return 0;
}