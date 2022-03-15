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

    //인덱스를 순회하면서 값을 찾는다
    for (int i = 0; i < n; i++)
    {
        //해당 값을 찾으면 해당 인덱스를 출력하고 프로그램을 종료
        if (d[i] == m)
        {
            cout << i;
            return 0;
        }
    }
    //못찾은 경우에는 프로그램에 종료되지 않기때문에 -1을 출력한다.
    cout << "-1";

    return 0;
}