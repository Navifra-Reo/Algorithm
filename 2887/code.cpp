#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
int n;
struct p { int x,y,z; int id; };
struct edge { int x,y; int v; };

vector<p> d;
vector<p> dx,dy,dz;
vector<edge> q;

int group[100000];

int getGroup(int a)
{
    if(a==group[a])return a;
    return group[a]=getGroup(group[a]);
}
void merge(int a, int b)
{
    a=getGroup(a);
    b=getGroup(b);
    if(a!=b)group[b]=a;
}

bool comparex(p a,p b)
{
    if(a.x < b.x) return true;
    return false;
}
bool comparey(p a,p b)
{
    if(a.y < b.y) return true;
    return false;
}
bool comparez(p a,p b)
{
    if(a.z < b.z) return true;
    return false;
}
bool compare(edge a,edge b)
{
    if(a.v < b.v) return true;
    return false;
}


int main()
{
    int ans = 0;
    cin >> n;
    for(int i=0;i<n; i++)
    {
        group[i]=i;

        int x, y, z;
        cin >> x >> y >> z;
        d.push_back({x,y,z,i});
    }

    dx.assign(d.begin(), d.end());
    dy.assign(d.begin(), d.end());
    dz.assign(d.begin(), d.end());
    
    std::sort(dx.begin(),dx.end(),comparex);
    std::sort(dy.begin(),dy.end(),comparey);
    std::sort(dz.begin(),dz.end(),comparez);

    for(int i=0; i<n-1; i++)
    {
        q.push_back({dx[i].id, dx[i+1].id, dx[i+1].x-dx[i].x});
        q.push_back({dy[i].id, dy[i+1].id, dy[i+1].y-dy[i].y});
        q.push_back({dz[i].id, dz[i+1].id, dz[i+1].z-dz[i].z});
    }

    sort(q.begin(),q.end(),compare);

    for(int i=0;i<q.size();i++)
    {
        int a,b;
        a = q[i].x;
        b = q[i].y;
        if(getGroup(a) == getGroup(b)) continue;
        merge(a,b);

        ans = ans + q[i].v;
    }
    cout << ans;
    return 0;
}