#include<vector>
#include<iostream>
#include<algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> Cow;

int n, ans = 0;
int pasture[4001][4001];
bool visit[4001][4001];

queue<Cow> cows;
const int _X[4]= { 1, -1, 0, 0 };
const int _Y[4]= { 0, 0, 1, -1 };

int findNull(int x,int y)
{
    for(int i=0; i<4; i++)
    {
        if(!visit[x+_X[i]][y+_Y[i]])return i;
    }
    return -1;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin >> x >> y;
        x+=2000;
        y+=2000;

        if(pasture[x][y] == 3)
        {
            cows.emplace(x,y);
        }
        for(int i=0; i<4; i++)
        {
            int _x = x + _X[i];
            int _y = y + _Y[i];

            if(!visit[x][y]) pasture[_x][_y]++;
            
            if(pasture[_x][_y] == 3 && visit[_x][_y]) cows.emplace(_x, _y);
        }

        if(visit[x][y]) ans--;
        visit[x][y] = true;

        while(!cows.empty())
        {
            auto [x,y] = cows.front();
            cows.pop();

            int nullpoint = findNull(x, y);
            
            if (nullpoint == -1)continue;

            int _x = x + _X[nullpoint], _y = y + _Y[nullpoint];
            ans++;
            visit[_x][_y] = true;
            if(pasture[_x][_y] == 3) cows.emplace(_x,_y);
            
            for(int i=0; i<4; i++)
            {
                int __x = _x + _X[i];
                int __y = _y + _Y[i];
                pasture[__x][__y]++;
                if(pasture[__x][__y] == 3 && visit[__x][__y]) cows.emplace(__x,__y);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}