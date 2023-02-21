#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
int t;

int count(int k)
{
    int sum=0;
    while(k>0)
    {
        sum+=(k%2);
        k = (k>>1);
    }
    return sum;
}

int solve(int n, int m)
{
    int max = 1 << m;
    int d[11][1024];
    int map[11];
    char ip[11];
    for(int i=0;i<n;i++)
    {
        map[i]=0;
        for(int j=0;j<max;j++)
        {
            d[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        cin >> ip;
        for(int j=0;j<m;j++)
        {
            int k=ip[j];
            map[i] = map[i]<<1;
            k = (k=='x') ? 0 : 1;
            map[i]+=k;
            d[i][j]=0;
        }
    }
    for(int i=0; i<max; i++)
    {
        if((map[0]&i) != i) continue;
        if((i&(i<<1)) !=0) continue;
        d[0][i]=count(i);
    }
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<max; j++)
        {
            if((j & (j<<1)) != 0 || (map[i]&j)!=j)continue;
            for(int k=0;k<max;k++)
            {
                if(((k<<1) & j) !=0 || ((k>>1) & j) !=0) continue;
                if((k & (k<<1)) !=0 || (map[i-1]&k)!=k)continue;
                if(d[i][j] < d[i-1][k]+count(j))
                {
                    d[i][j]=d[i-1][k]+count(j);
                }
            }
        }
    }
    int ans=0;
    for(int i=0; i<max; i++)
    {
        ans = ans > d[n-1][i] ? ans : d[n-1][i];
    }
    return ans;
}

int main()
{
    cin >> t;
    for(int i=0;i<t;i++)
    {
        int n,m;
        cin >> n >> m;
        cout << solve(n,m) << endl;
    }
    return 0;
}