#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int n,m;

priority_queue<int> k;
vector<int> d[1001];
vector<int> ans;
int cnt[1001];

int main()
{
    cin >> n >> m;
    for(int i=0;i<m; i++)
    {
        int t,tt;
        cin >> t >> tt;
        for(int j=1;j<t;j++)
        {
            int ttt=tt;
            cin >> tt;
            d[ttt].push_back(tt);
            cnt[tt]++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(cnt[i]==0) k.push(i);
    }
    while(!k.empty())
    {
        int t = k.top();
        ans.push_back(t);
        k.pop();
        for(int i=0;i<d[t].size();i++)
        {
            cnt[d[t][i]]--;
            if(cnt[d[t][i]]==0) k.push(d[t][i]);
        }
    }
    if(ans.size()<n)
    {
        cout << 0;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}