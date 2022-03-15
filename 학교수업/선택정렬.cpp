#include <iostream>
#include <string>
#include <math.h>
using namespace std;

//추가적인 교환 변수를 쓰지 않기 때문에 오버플로우를 방지하기 위해서 더 큰 자료형 사용
long long int d[1000];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    for (int i = 0; i < n; i++)
    {
        //초기 최초값을 i번째 값으로 지정
        int min = d[i], idx = i;

        // i+1~n-1까지 돌면서 그중 가장 최소값을 찾음
        for (int j = i + 1; j < n; j++)
        {
            if (min > d[j])
            {
                min = d[j];
                idx = j;
            }
        }
        //최소값이 갱신되지 않았다면 바꿀필요가 없기때문에 다음 내용을 스킵함
        if (i == idx)
            continue;

        //최소값으로 지정된 인덱스와 i번째 값을 교환
        d[i] = d[i] + d[idx];
        d[idx] = d[i] - d[idx];
        d[i] = d[i] - d[idx];
    }

    for (int k = 0; k < n; k++)
    {
        cout << d[k] << ' ';
    }

    return 0;
}