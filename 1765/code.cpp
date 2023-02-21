#include <iostream>
using namespace std;
int answer=0;
int group[1001];
int eEdge[1001][1001];
void init(int n)
{
    for(int i=0;i<=n;i++) group[i]=i;
}
int Find(int x)
{
    if(x==group[x]) return x;
    group[x] = Find(group[x]);
    return group[x];
}
void Union(int x, int y)
{
    x=Find(x);
    y=Find(y);
    if(x!=y)group[y]=x;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n,m;
    cin >> n >> m;
    init(n);
    for(int i=0; i<m; i++)
    {
        char r;
        int x,y;
        cin >> r >> x >> y;
        if(r=='F')
        {
            Union(x,y);
            continue;
        }
        eEdge[x][++eEdge[x][0]]=y;
        eEdge[y][++eEdge[y][0]]=x;
        for(int j=1; j<eEdge[x][0]; j++)
        {
            Union(eEdge[x][j],y);
        }
        for(int j=1; j<eEdge[y][0]; j++)
        {
            Union(eEdge[y][j],x);
        }
    }
    for(int i=1;i<=n;i++) if(i==Find(i))answer++;
    cout << answer;
    return 0;
}