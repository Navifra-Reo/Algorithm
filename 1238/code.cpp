#include <iostream>
using namespace std;

int n, m, x;
int d[1001][1001];
int k1[1001];
int k2[1001];
int visit[1001] = { false };

int main()
{
    cin >> n >> m >> x;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        d[a][b]=c;
        if(a==x) k1[b]=c;
        if(b==x) k2[a]=c;
    }
    while(1)
    {
        int temp=0;
        for(int i=1; i<=n; i++) {
            if(i==x) continue;
            if((k1[temp] > k1[i] || k1[temp]==0) && k1[i]!=0 && !visit[i]){
                temp=i;
            }
        }
        if(temp==0)break;
        visit[temp] = true;
        for(int i=1; i<=n; i++)
        {
            if(i==x) continue;
            if((k1[i]==0 || k1[temp]+d[temp][i] < k1[i]) && d[temp][i]!=0)
            {
                k1[i] = k1[temp] + d[temp][i];
            }
        }
    }
    while(1)
    {
        int temp=0;
        for(int i=1; i<=n; i++) {
            if(i==x) continue;
            if((k2[temp] > k2[i] || k2[temp]==0) && k2[i]!=0 && visit[i]){
                temp=i;
            }
        }
        if(temp==0)break;
        visit[temp] = false;
        for(int i=1; i<=n; i++)
        {
            if(i==x) continue;
            if((k2[i]==0 || k2[temp]+d[i][temp] < k2[i]) && d[i][temp]!=0)
            {
                k2[i] = k2[temp] + d[i][temp];
            }
        }
    }
    int max=0;
    for(int i=1; i<=n; i++)
    {
        if(max < k1[i]+k2[i]) max = k1[i]+k2[i];
    }
    cout << max;
    return 0;
}