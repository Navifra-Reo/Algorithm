#include <iostream>
using namespace std;

struct node
{
    char key;
    node *left;
    node *right;
};
node tree[101];

void root(char key)
{
    tree[0].key = key;
}
void set_left(char key, int parentID)
{
    tree[parentID].left = &tree[(parentID + 1) * 2 - 1];
    tree[parentID].left->key = key;
}
void set_right(char key, int parentID)
{
    tree[parentID].right = &tree[(parentID + 1) * 2];
    tree[parentID].right->key = key;
}
void print_tree()
{
    int k;
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < (1 << i); j++)
        {
            if (tree[k].key != 0)
            {
                cout << tree[k].key << '(' << k << ')';
            }
            k++;
        }
        cout << endl;
    }
}
int main()
{
    root('A');
    set_left('B', 0);
    set_left('C', 0);
    set_right('C', 0);
    set_left('D', 1);
    set_right('E', 3);
    print_tree();
    return 0;
}