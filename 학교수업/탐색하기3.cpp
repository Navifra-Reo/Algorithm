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
        //���� �Է¹��� �Ŀ� ��հ���� ���� �Ǽ������� ����ȯ �� ��հ��� ���Ѵ�.
        avg += (double)d[i];
    }
    //��� ���� ���� ���� n���� ������.
    avg /= (double)n;
    for (int i = 0; i < n; i++)
    {
        //��հ� ���� ���밪���� ���ؾ� �ϱ⶧���� i��° ������ ��հ��� ���� �� ���� ���밪�� ���ؼ� ���Ѵ�.
        double t = abs((float)d[i] - avg);
        //������ �ּ� ���̰��� ���������� ���� ���� �� ���� ������ �� ������ ����
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