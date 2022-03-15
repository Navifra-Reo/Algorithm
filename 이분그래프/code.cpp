#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

//�񿬰� ����Ʈ�� �Ǻ� ������Ѵ�.

using namespace std;

int testCase, tempV, tempE, startPoint, endPoint, indexs, color = 1;

void Porcess()
{
    cin >> tempV >> tempE;
    vector<int> e[tempV + 1];
    queue<int> q;
    int *map = new int[tempV + 1];
    memset(map, 0, (tempV + 1) * sizeof(int));

    for (int i = 0; i < tempE; i++)
    {
        cin >> startPoint >> endPoint;
        e[startPoint].push_back(endPoint);
        e[endPoint].push_back(startPoint);
    }
    for (int j = 1; j <= tempV; j++)
    {
        if (map[j] != 0)
        {
            continue;
        }
        map[j] = color;
        q.push(j);
        while (!q.empty())
        {
            indexs = q.front();
            q.pop();
            color = (map[indexs] == 1) ? 2 : 1;
            for (int i = 0; i < e[indexs].size(); i++)
            {
                //�湮���̶��
                if (map[e[indexs][i]] == 0)
                {
                    //������ ĥ����
                    map[e[indexs][i]] = color;
                    //�����ְ� �־���
                    q.push(e[indexs][i]);
                }
                //�̹� ĥ�����µ� ���� �ٸ���?
                else if (map[e[indexs][i]] != color)
                {
                    cout << "No\n";
                    for (int k = 1; k <= tempV; k++)
                    {
                        cout << map[k] << " ";
                    }
                    cout << "\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
    for (int k = 1; k <= tempV; k++)
    {
        cout << map[k] << " ";
    }
    cout << "\n";
    return;
}

int main()
{
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        color = 1;
        Porcess();
    }
}