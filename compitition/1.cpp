#include <iostream>
#include <queue>
using namespace std;
int d[100001] = { 0 };
int main()
{
	int n,k,ans=0;
	pair<int,int> tt;
	priority_queue<pair<int,int>> q;
	
	cin >> n >> k;
	
	for(int i=0;i<k;i++)
	{
		int t;
		cin >> t;
		d[t]++;
	}
	for(int i=1;i<=n;i++)
	{
		q.push({-d[i],i});
	}
	
	tt=q.top();
	q.pop();
	ans += tt.second;
	for(int i=1;i<n;i++)
	{
		if(tt.first != q.top().first)break;
		tt=q.top();
		q.pop();
		ans+=tt.second;
	}
	cout << ans;
	return 0;
}