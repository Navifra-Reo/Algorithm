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
        // i��° ���ڿ��� ���ִ��б����� Ȯ���Ѵ�
        if (d[i] == "AJOU")
        {
            // s�� ���ŵǾ����� Ȯ���ϰ� ������ �Ǿ������� e�� ������ s�� ���� �����Ѵ�.
            if (s == -1)
                s = i;
            else
                e = i;
        }
    }

    cout << s + 1 << ' ' << e + 1;
    return 0;
}