#include <iostream>
using namespace std;
int main()
{
	char d[3][3];
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin >> d[i][j];
		}
	}
	
	if(d[0][0]==d[0][1] && d[0][1]==d[0][2] && d[0][0]!='.')
	{
		cout<<"YES";
		return 0;
	}
	if(d[1][0]==d[1][1] && d[1][1]==d[1][2] && d[1][0]!='.')
	{
		cout<<"YES";
		return 0;
	}
	if(d[2][0]==d[2][1] && d[2][1]==d[2][2] && d[2][0]!='.')
	{
		cout<<"YES";
		return 0;
	}
	
	if(d[0][0]==d[1][0] && d[1][0]==d[2][0] && d[0][0]!='.')
	{
		cout<<"YES";
		return 0;
	}
	if(d[0][1]==d[1][1] && d[1][1]==d[2][1] && d[0][1]!='.')
	{
		cout<<"YES";
		return 0;
	}
	if(d[0][2]==d[1][2] && d[1][2]==d[2][2] && d[0][2]!='.')
	{
		cout<<"YES";
		return 0;
	}
	
	if(d[0][0]==d[1][1] && d[1][1]==d[2][2] && d[1][1]!='.')
	{
		cout<<"YES";
		return 0;
	}
	if(d[0][2]==d[1][1] && d[1][1]==d[2][0] && d[1][1]!='.')
	{
		cout<<"YES";
		return 0;
	}
	
	
	cout << "NO";
	return 0;
}