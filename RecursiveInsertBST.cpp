#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} * root;

Node *RInsert(struct Node *p, int key)
{
    struct Node *t;
    if (p == NULL)
    {
        t = new struct Node;
        t->data = key;
        t->right = 0;
        t->left = 0;
        // p = t;
        return p;
    }
    else if (key < p->data)
    {
        p->left = RInsert(p->left, key);
    }
    else if (key > p->data)
    {
        p->right = RInsert(p->right, key);
    }
    return p;
}

struct Node *Search(int key)
{
    struct Node *t = root;
    while (t != 0)
    {
        if (key == t->data)
            return t;
        else if (key < t->data)
            t = t->left;
        else
            t = t->right;
    }
    return NULL;
}

int Height(struct Node *p)
{
    int x, y;
    if (p == NULL)
        return 0;
    x = Height(p->left);
    y = Height(p->right);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}
struct Node *InPre(struct Node *p)
{
    while (p && p->right != NULL)
        p = p->right;

    return p;
}
struct Node *InSucc(struct Node *p)
{
    while (p && p->left != NULL)
        p = p->left;

    return p;
}

struct Node *Delete(struct Node *p, int key)
{
    struct Node *q;

    if (p == NULL)
        return NULL;

    if ((p->left == 0) && (p->right == 0))
    {
        if (p == root)
            root = NULL;
        free(p);
        return NULL;
    }

    if (key < p->data)
    {
        p->left = Delete(p->left, key);
    }
    else if (key > p->data)
    {
        p->right = Delete(p->right, key);
    }
    else
    {
        if (Height(p->left) > Height(p->right))
        {
            q = InPre(p->left);
            p->data = q->data;
            p->left = Delete(p->left, q->data);
        }
        else
        {
            q = InSucc(p->right);
            p->data = q->data;
            p->right = Delete(p->right, q->data);
        }
    }

    return p;
}

void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->left);
        cout << p->data << " ";
        Inorder(p->right);
    }
}
int main()
{

    struct Node *temp;

    root = RInsert(root, 50);
    RInsert(root, 10);
    RInsert(root, 40);
    RInsert(root, 20);
    RInsert(root, 30);

    Delete(root, 30);

    Inorder(root);
    printf("\n");

    temp = Search(20);
    if (temp != NULL)
        printf("element %d is found\n", temp->data);
    else
        printf("element is not found\n");

    return 0;
}