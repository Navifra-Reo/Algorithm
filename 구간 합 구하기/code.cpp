#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct node
{
    int s,e;
    long long sum;
    node* lNode;
    node* rNode;
};
int n, m, k;
long long d[1000000];

node* cunstructor(int s, int e)
{
    int e1,s1;
    node* Node = (node*)malloc(sizeof(node));
    Node->s=s;
    Node->e=e;

    if(s==e)
    {
        Node->sum=d[s];
        return Node;
    }
    
    e1= (s+e)/2;
    s1= e1+1;
    if(s<=e1) Node->lNode = cunstructor(s,e1);
    if(s1<=e) Node->rNode = cunstructor(s1,e);

    Node->sum = Node->lNode->sum + Node->rNode->sum;
    return Node;
}
void change(node* Node, int pos, long long value)
{
    Node->sum += (value - d[pos]);
    if(Node->s == Node->e) return;
    if(Node->lNode->s <= pos && pos <= Node->lNode->e)
    {
        change(Node->lNode,pos,value);
    }
    if(Node->rNode->s <= pos && pos <= Node->rNode->e)
    {
        change(Node->rNode,pos,value);
    }
    return;
}
long long getSum(node* Node, int s, int e)
{
    long long sum=0;
    
    if(Node->s == Node->e) return Node->sum;
    if(s <= Node->s && Node->e <= e)
    {
        return Node->sum;
    }
    
    if(s <= Node->lNode->e)
    {
        sum+=getSum(Node->lNode,s,e);
    }
    if(Node->rNode->s <= e)
    {
        sum+=getSum(Node->rNode,s,e);
    }
    return sum;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;
    for(int i =0 ; i<n; i++)
    {
        cin >> d[i];
    }

    node* tree = cunstructor(0,n-1);

    for(int i=0; i<k+m; i++)
    {
        int task, pos;
        long long a;
        cin >> task >> pos >> a;
        if(task==1)
        {
            change(tree, pos-1, a);
            d[pos-1]=a;
            continue;
        }
        cout << getSum(tree,pos-1,a-1) << '\n';
    }
    return 0;
}