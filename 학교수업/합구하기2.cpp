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

        //�Է°� ���ÿ� �ش� �ο��� �������ѿ� �ɸ����� Ȯ��
        if (p >= t)
        {
            //���� ���ѿ� �ɸ��� �ʴ°�� ü�����ѿ� �ɸ��� ���� �ο����� 1�� ���ϰ� ü���� �� ������ ���Ѵ�.
            count++;
            sum += t;
        }
    }
    // ü�����ѿ� �ɸ��� ���� ����� ���� �ش� ������� ü���� ���� ����Ѵ�.
    cout << count << ' ' << sum << '\n';

    //ü���� ���� q���� ũ�� NO, �۰ų� ������ YES�� ����Ѵ�/
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