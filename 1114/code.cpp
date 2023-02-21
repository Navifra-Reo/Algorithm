#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int l,k,c;
vector<int> d;

int f(int s, int e)
{
    if(s+1==e)return 0;
    int length = d[e]-d[s], idx;
    idx=s;
    int t=max(d[idx]-d[s],d[e]-d[idx]);
    for(int i=s+1;i<e;i++)
    {
        int t1 = d[i]-d[s];
        int t2 = d[e]-d[i];
        if(t>max(t1,t2))
        {
            t=max(t1,t2);
            idx=i;
        }
    }
    return idx;
}

int main()
{
    cin >> l >> k >> c;
    for(int i=0;i<k;i++)
    {
        int t;
        cin >> t;
        d.push_back(t);
    }
    d.push_back(0);

    if(d[k]!=l) d.push_back(l);

    q.push({l,{0,-d.size()+1}});

    sort(d.begin(),d.end());

    while(!q.empty() && c>0)
    {
        int s = -q.top().second.first;
        int e = -q.top().second.second;
        int length= q.top().first;
        
        if(s+1>=e)
        {
            cout << endl;
            if(s<e)anwser.push(q.top());
            q.pop();
            continue;
        }
        int cut = f(s,e);

        if(cut!=0)
        {
            q.pop();
            q.push({d[cut]-d[s],{-s,-cut}});
            q.push({d[e]-d[cut],{-cut,-e}});
            c--;
        }
    }
    int ans=0,idx=0;

    while(!q.empty())
    {
        int s = -q.top().second.first;
        int e = -q.top().second.second;
        int length= q.top().first;
        q.pop();
        if(ans<length)
        {
            idx=s;
            if(s==0)idx=e;
            ans = length;
        }
        if(ans==length && idx>s)
        {
            idx=s;
            if(s==0)idx=e;
            ans = length;
        }
        cout << d[s] << " " << d[e] << " " << length << endl;
    }
    cout << endl;
    while(!anwser.empty())
    {
        int s = anwser.top().second.first;
        int e = anwser.top().second.second;
        int length= anwser.top().first;
        anwser.pop();
        if(ans<length)
        {
            idx=s;
            if(s==0)idx=e;
            ans = length;
        }
        if(ans==length && idx>s)
        {
            idx=s;
            if(s==0)idx=e;
            ans = length;
        }
        cout << d[s] << " " << d[e] << " " << length << endl;
    }
    
    cout << ans << " " << d[idx];
    return 0;
}