#include<iostream>
#include<stdio.h>
#include<queue>
#include<map>
using namespace std;

int n, m;
int d[10002][10002];
int group[10000000];

void init(int k)
{
    for(int i=0;i<=k;i++)group[i]=i;
}
int Find(int x)
{
    if(x==group[x]) return x;
    return group[x]=Find(group[x]);
}
void Union(int x,int y)
{
    x=Find(x);
    y=Find(y);
    group[x]=y;
}

int bfs(int _x, int _y)
{
    int sum=0, u = (_x-1) * m+_y;
    queue<pair<int,int>> q;
    queue<pair<int,int>> k;

    q.push({_x,_y});
    d[_x][_y]=-1;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        k.push({x,y});
        Union(u,(x-1)*m+y);
        if(d[x-1][y]==0) { q.push({x-1,y}); d[x-1][y] = -1; }
        if(d[x+1][y]==0) { q.push({x+1,y}); d[x+1][y] = -1; }
        if(d[x][y-1]==0) { q.push({x,y-1}); d[x][y-1] = -1; }
        if(d[x][y+1]==0) { q.push({x,y+1}); d[x][y+1] = -1; }
        q.pop();
        sum++;
    }
    while(!k.empty())
    {
        int x = k.front().first;
        int y = k.front().second;
        d[x][y] = sum;
        k.pop();
    }
    return 0;
}
int main()
{
    int ans = 0;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char t;
            cin >> t;
            if(t=='1')d[i][j]=-1;
        }
    }
    init(n*m);
    for(int i=0;i<=n+1;i++) d[i][0] = d[i][m+1] = -1;
    for(int i=0;i<=m+1;i++) d[0][i] = d[n+1][i] = -1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(d[i][j]==0) bfs(i,j);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(d[i][j]!=-1) { cout << 0; continue; }
            int e=1;
            int up,down,left,right;
            up = 1 < i ? Find((i-2)*m+j) : 0;
            down = i < n ? Find(i*m+j) : 0;
            left = 1 < j ? Find((i-1)*m+j-1) : 0;
            right = j < m ? Find((i-1)*m+j+1) : 0;
            if(up!=0 && d[i-1][j]!=-1) e+=d[i-1][j];
            if(down!=up && down!=0 && d[i+1][j]!=-1)e+=d[i+1][j];
            if(left!=up && left!=down && left!=0 && d[i][j-1]!=-1) e+=d[i][j-1];
            if(right!=up && right!=down && right!=left && right!=0 && d[i][j+1]!=-1)e+=d[i][j+1];
            cout << e;
        }
        cout <<endl;
    }

    return 0;
}