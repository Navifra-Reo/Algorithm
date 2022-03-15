#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int d[10000];
int main()
{
    int n, ans, idx;
    double avg = 0, diff = 300000;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
        //값을 입력받은 후에 평균계산을 위해 실수형으로 형변환 후 평균값에 더한다.
        avg += (double)d[i];
    }
    //모두 더한 값을 값을 n으로 나눈다.
    avg /= (double)n;
    for (int i = 0; i < n; i++)
    {
        //평균과 차는 절대값으로 구해야 하기때문에 i번째 값에서 평균값을 빼고 그 값의 절대값을 취해서 비교한다.
        double t = abs((float)d[i] - avg);
        //기존의 최소 차이값이 작은값보다 현재 값이 더 차가 작으면 그 값으로 갱신
        if (t < diff)
        {
            diff = t;
            ans = d[i];
            idx = i;
        }
    }
    cout << idx + 1 << ' ' << ans;
    return 0;
}