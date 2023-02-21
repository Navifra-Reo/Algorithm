#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n,ans=0;
	int d[100000];
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> d[i];
	}
	sort(d,d+n);
	for(int i=2;i<=d[0];i++)
	{
		bool check = true;
		for(int j=1;j<n;j++)
		{
			if(d[j-1]%i != d[j]%i)
			{
				check=false;
				break;
			}
		}
		if(check)ans++;
	}
	cout << ans;
	return 0;
}