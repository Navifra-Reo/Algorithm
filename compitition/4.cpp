#include <iostream>
using namespace std;
int main()
{
	int n,m,a=0;
	cin >> n >> m;
	int d[10000][10000] = { 0 };
	int ans[10000][10000] = { 0 };
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin >> d[i][j];
			if((d[i][j] !=2 || d[i-1][j-1]!=2) && d[i-1][j]==1 && d[i][j-1]==1) ans[i-1][j]=ans[i][j-1]=1;
			if(d[i][j]!=1)continue;
			if(d[i-1][j]==1) ans[i-1][j] = ans[i][j] = 1;
			if(d[i][j-1]==1) ans[i][j-1] = ans[i][j] = 1;
			else if((d[i-1][j]!=2 || d[i][j-1]!=2) && d[i-1][j-1]==1) ans[i-1][j-1] = ans[i][j] = 1;
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a+=ans[i][j];
		}
	}
	cout << a;
	return 0;
}