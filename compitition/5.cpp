#include <iostream>
#include <vector>
using namespace std;
int n;
int value[700001];
int d[700001];
vector<vector<int>> edge;

int f(int idx)
{
	if(edge[idx].size()==0)
	{
		d[idx]=0;
		return 0;
	}
	int max=0,ans=0;
	for(int i=0;i<edge[idx].size();i++)
	{
		f(edge[idx][i]);
		max+=d[edge[idx][i]];
	}
	ans=max;
	for(int i=0;i<edge[idx].size();i++)
	{
		int child = edge[idx][i];
		int temp = ans-d[child] + value[idx] * value[child];
		for(int j=0;j<edge[child].size();j++)
		{
			temp+=d[edge[child][j]];
		}
		if(max<temp)max=temp;
	}
	d[idx]=max;
	return max;
}

int main()
{
	cin >> n;
	edge = vector<vector<int>>(n+1);
	for(int i=1;i<=n;i++)
	{
		int s, v;
		cin >> s >> v;
		edge[s].push_back(i);
		value[i]=v;
	}
	cout << f(1);
	return 0;
}