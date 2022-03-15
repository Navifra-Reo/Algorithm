#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int post[100001];
int in[100001];

struct node
{
    int v = 0;
    node *right = nullptr;
    node *left = nullptr;
};

void tree(node *a)
{
    cout << a->v << ' ';
    if (a->left != nullptr)
    {
        tree(a->left);
    }
    if (a->right != nullptr)
    {
        tree(a->right);
    }
}

node *f(int s, int e, int s1, int e1)
{
    int mid;
    node *k = new node;
    k->v = post[e1];

    for (mid = s; mid <= e; mid++)
    {
        if (in[mid] == post[e1])
            break;
    }
    if (s < mid && mid <= e)
        k->left = f(s, mid - 1, s1, s1 + (mid - s) - 1);
    if (mid < e && mid >= s)
        k->right = f(mid + 1, e, e1 - (e - mid), e1 - 1);

    return k;
}
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> in[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> post[i];
    }
    node *k = f(1, n, 1, n);
    tree(k);
    return 0;
}