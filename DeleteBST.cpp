#include <iostream>
using namespace std;
struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
} * root;

void Insert(int data)
{
    struct Node *t = root;
    struct Node *p, *r = 0;
    if (!root)
    {
        p = new struct Node;
        p->data = data;
        p->left = 0;
        p->right = 0;
        root = p;
    }
    else
    {
        while (!t)
        {
            r = t;
            if (t->data > data)
                t = t->left;
            else if (t->data < data)
                t = t->right;
            else
                return;
        }
        p = new struct Node;
        p->data = data;
        p->left = 0;
        p->right = 0;
        if (r->data > data)
            r->left = p;
        else // if (r->data < data)//
            r->right = p;
        // else
        //     return -1;
    }
}

struct Node *RInsert(struct Node *p, int key)
{
    // struct node *t = NULL;
    if (!p)
    {
        struct Node *t = 0;
        t = new struct Node;
        t->left = 0;
        t->right = 0;
        t->data = key;
        return t;
    }
    if (key > p->data)
        p->right = RInsert(p->right, key);
    else if (key < p->data)
        p->left = RInsert(p->left, key);
    else
        return p;
}
void Delete(int key)
{
}

int main()
{
    root = RInsert(root, 10);
    RInsert(root, 5);
    RInsert(root, 20);
    RInsert(root, 8);
    RInsert(root, 30);

    return 0;
}