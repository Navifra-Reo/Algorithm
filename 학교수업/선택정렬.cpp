#include <iostream>
#include <string>
#include <math.h>
using namespace std;

//�߰����� ��ȯ ������ ���� �ʱ� ������ �����÷ο츦 �����ϱ� ���ؼ� �� ū �ڷ��� ���
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
        //�ʱ� ���ʰ��� i��° ������ ����
        int min = d[i], idx = i;

        // i+1~n-1���� ���鼭 ���� ���� �ּҰ��� ã��
        for (int j = i + 1; j < n; j++)
        {
            if (min > d[j])
            {
                min = d[j];
                idx = j;
            }
        }
        //�ּҰ��� ���ŵ��� �ʾҴٸ� �ٲ��ʿ䰡 ���⶧���� ���� ������ ��ŵ��
        if (i == idx)
            continue;

        //�ּҰ����� ������ �ε����� i��° ���� ��ȯ
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