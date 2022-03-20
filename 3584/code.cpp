#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> edge;
int ans = 0,fir,sec;
int f(int node)
{
    cout << node << endl;
    int k=0;
    if(node == fir || node == sec) k++;
    for(int i=0;i<edge[node].size();i++)
    {
        k+=f(edge[node][i]);
    }
    // cout << node << ' ' << k << endl;
    if(k==2)
    {
        ans=node;
        k=0;
    }
    return k;
}

int solve()
{
    int n;
    cin >> n;
    edge=vector<vector<int>>(n+1,vector<int>());
    vector<int> rootCheck = vector<int>(n+1);

    for(int i=1;i<n;i++)
    {
        int a,b;
        cin >> a >> b;
        edge[a].push_back(b);
        rootCheck[b]++;
    }
    cin >> fir >> sec;
    int root=0;
    ans=0;
    for(int i=1; i<=n; i++)
    {
        if(rootCheck[i]==0) root=i;
    }
    cout << root;
    f(root);
    return ans;
}
int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cout << solve() << endl;
    }
    return 0;
}