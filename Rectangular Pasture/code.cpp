#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int n;

long ans = 1;

int idx[2501][2501];

struct Cow
{
    int x;
    int y;
    Cow(int a,int b) : x(a),y(b){};
};
vector<Cow> cows;

bool compare1(const Cow& p1, const Cow& p2)
{
    if(p1.x < p2.x) return true;
    else if(p1.x == p2.x && p1.y < p2.y) return true;
    return false;
}
bool compare2(const Cow& p1, const Cow& p2)
{
    if(p1.y < p2.y) return true;
    else if(p1.y == p2.y && p1.x < p2.x) return true;
    return false;
}

void normalize()
{
    sort(cows.begin(),cows.end(),compare2);
    int counter=1;
    for(int i=1; i<=n; i++) cows[i-1].y = counter++;

    sort(cows.begin(),cows.end(),compare1);
    counter=1;
    for(int i=1;i<=n;i++) cows[i-1].x = counter++;

    for(int i=0; i<n; i++) idx[cows[i].x][cows[i].y]=1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j<=n; j++) idx[i][j] += (idx[i-1][j] + idx[i][j-1] - idx[i-1][j-1]);
    }
}

long query(int x1, int x2)
{
    int y1 = cows[x1-1].y < cows[x2-1].y ? cows[x1-1].y : cows[x2-1].y;
    int y2 = cows[x1-1].y > cows[x2-1].y ? cows[x1-1].y : cows[x2-1].y;

    int upperCase = idx[x2][n] - (idx[x2][y2] + idx[x1-1][n] - idx[x1-1][y2]) + 1;
    int lowerCase = idx[x2][y1] - idx[x1-1][y1];

    return upperCase * lowerCase;
}

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin >> a >> b;
        Cow cow = Cow(a,b);
        cows.push_back(cow);
    }
    normalize();

    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j++)
        {
            ans+=query(i,j);
        }
    }
    cout << ans;
    return 0;
}