#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int n, ans=0;

struct qNode
{
    int parent;
    int number;
    int time = 0;
    vector<qNode*> child;
};

struct tree
{
    vector<int> edge;
};
bool compare(const qNode* p1, const qNode* p2)
{
    if(p1->time > p2->time) return true;    
    return false;
}

tree d[100001];

bool check[100001] = { false };

qNode queue[100001];

int s = -1;
int e = 0;

void f()
{
    queue[0].number = 1;
    queue[0].parent = 0;
        check[1]=true;
    while(s<e)
    {
        s++;

        //자식들 큐에 집어넣기
        for(int i = 0; i < d[queue[s].number].edge.size(); i++)
        {
            int node = queue[s].number;
            int childNum = d[node].edge[i];

            if(check[childNum]) continue;
            
            e++;
            check[childNum]=true;

            queue[e].number = childNum;
            queue[e].parent = node;
            queue[s].child.push_back(&queue[e]);
        }

        //감염되는데 걸리는 시간
        int childCount = queue[s].child.size();
        int count =0, patient =1;
        while(patient <= childCount)
        {
            count++;
            patient*=2;
        }
        queue[s].time = count;
    }
}

int main()
{
    cin >> n;
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin >> a >> b;
        d[a].edge.push_back(b);
        d[b].edge.push_back(a);
    }
    f();

    for(int i=e;i>=0;i--)
    {
        int childCount = queue[i].child.size();
        sort(queue[i].child.begin(),queue[i].child.end(),compare);
        int max = 0;
        for(int j = 1; j <= childCount; j++)
        {
            int value = 1 + queue[i].child[j - 1]->time;
            max += value;
        }
        queue[i].time += max;
    }
    cout << queue[0].time;
    return 0;
}