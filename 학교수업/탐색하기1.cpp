#include <iostream>
using namespace std;
int d[10000];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }

    //�ε����� ��ȸ�ϸ鼭 ���� ã�´�
    for (int i = 0; i < n; i++)
    {
        //�ش� ���� ã���� �ش� �ε����� ����ϰ� ���α׷��� ����
        if (d[i] == m)
        {
            cout << i;
            return 0;
        }
    }
    //��ã�� ��쿡�� ���α׷��� ������� �ʱ⶧���� -1�� ����Ѵ�.
    cout << "-1";

    return 0;
}