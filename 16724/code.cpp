#include<iostream>
#include<queue>
#include<map>
using namespace std;

int n, m;
struct direct
{
    int x = 0, y = 0;
    bool visit = false;
};
direct d[1000][1000];

int bfs(int x, int y)
{
    pair<int, int> pos;
    map<pair<int,int>,bool> check;
    pos.first=x;
    pos.second=y;
    check[pos]=true;
    while(!d[pos.first][pos.second].visit)
    {
        int _x=pos.first;
        int _y=pos.second;
        check[pos]=true;
        d[_x][_y].visit = true;
        pos.first+=d[_x][_y].x;
        pos.second+=d[_x][_y].y;
    }
    if(check[pos]) return 1;
    return 0;
}
int main()
{
    int ans = 0;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char t;
            cin >> t;
            if('D' == t) d[i][j].x=1;
            if('U' == t) d[i][j].x=-1;
            if('R' == t) d[i][j].y=1;
            if('L' == t) d[i][j].y=-1;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!d[i][j].visit) ans += bfs(i,j);
        }
    }
    cout << ans;
    return 0;
}