#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int n;

enum direction{
    east,
    north
};
struct Cow
{
    int x;
    int y;
    int idx;
    int distance = -1;
    Cow(int a,int b,int c) : x(a),y(b),idx(c){};
};
vector<Cow> cowE, cowN;
int ans[51];
bool compare1(const Cow& p1, const Cow& p2)
{
    if(p1.x < p2.x) return true;
    return false;
}
bool compare2(const Cow& p1, const Cow& p2)
{
    if(p1.y < p2.y) return true;
    return false;
}

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        char c;
        cin >> c >> a >> b;
        Cow cow = Cow(a, b, i);
        if(c=='N') cowN.push_back(cow);
        else cowE.push_back(cow);
    }

    sort(cowE.begin(),cowE.end(),compare2);
    sort(cowN.begin(),cowN.end(),compare1);

    for(int i=0; i<cowN.size(); i++)
    {
        for(int j=0; j<cowE.size(); j++)
        {
            if(cowE[j].x < cowN[i].x && cowE[j].y > cowN[i].y)
            {
                int a = cowE[j].y - cowN[i].y;
                int b  = cowN[i].x-cowE[j].x;
                if(a == b || cowE[j].distance != -1) continue;

                else if(a > b)
                {
                    cowN[i].distance = cowE[j].y - cowN[i].y;
                    ans[cowN[i].idx] = cowE[j].y - cowN[i].y;
                    break;
                }

                else
                {
                    cowE[j].distance = cowN[i].x - cowE[j].x;
                    ans[cowE[j].idx] = cowN[i].x - cowE[j].x;
                }
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(ans[i] == 0) cout << "Infinity" << endl;
        else cout << ans[i] << endl;
    }
    return 0;
}