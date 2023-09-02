#include <iostream>
using namespace std;
struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
} * root;
void Insert(int key)
{
    struct Node *t = root;
    struct Node *r, *p;
    if (root == NULL)
    {
        p = new struct Node;
        p->data = key;
        p->left = NULL;
        p->right = NULL;
        root=p;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (key < t->data)
        {
            t = t->left;
        }
        else if (key > t->data)
        {
            t = t->right;
        }
        else
        {
            return;
        }
    }
    p = new struct Node;
    p->data = key;
    p->left = NULL;
    p->right = NULL;

    if (key < r->data)
        r->left = p;

    else
        r->right = p;
}
void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->left);
        cout<<p->data;
        Inorder(p->right);
    }
}
int main()
{
    Insert(10);
    Insert(5);
    Insert(20);
    Insert(8);
    Insert(30);
    // Insert();
    Inorder(root);
    return 0;
}