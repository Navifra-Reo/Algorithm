#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

//비연결 리스트도 판별 해줘야한다.

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
                //방문전이라면
                if (map[e[indexs][i]] == 0)
                {
                    //색으로 칠해줌
                    map[e[indexs][i]] = color;
                    //갈수있게 넣어줌
                    q.push(e[indexs][i]);
                }
                //이미 칠해졌는데 색이 다르면?
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