#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
struct point
{
    int x,y;
    // point(int a,int b) : x(a),y(b){};
};
vector<point> pos;
int n;

double f(int positive, int negative, int level, double x, double y)
{
    double a = 40000000007.0, b = 40000000007.0;
    if(positive + negative == n)
    {
        return sqrt(x*x + y*y);
    }
    if(positive < n/2)
    {
        a = f(positive+1, negative, level+1, x + (double)pos[level].x, y + (double)pos[level].y);
    }
    
    if(negative < n/2)
    {
        b = f(positive, negative+1, level+1, x - (double)pos[level].x, y - (double)pos[level].y);
    }
    
    return a > b ? b : a;
}
double process()
{
    cin >> n;

    pos.resize(n);
    for(int i=0;i<n;i++)
    {
        cin >> pos[i].x >> pos[i].y;
    }
    return f(0, 0, 0, 0, 0);
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

	cout << fixed;
    cout.precision(12);

    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cout << process() << '\n';
    }
    return 0;
}