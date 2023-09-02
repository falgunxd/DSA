#include <iostream>
#include <queue>
using namespace std;
typedef struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
} Node;
Node *head;

// void Leftchild(struct Node *p, key)
// {
//     temp = new struct Node;
//     temp->data = key;
//     temp->right = 0;
//     temp->left = 0;
//     p->left = temp;
// }
// void Rightchild(struct Node *p, key)
// {
//     temp = new struct Node;
//     temp->data = key;
//     temp->right = 0;
//     temp->left = 0;
//     p->right = temp;
// }
// void Preorder(struct Node *p)
// {
//     while (p->left->left != 0)
//     {
//         cout << (p->left->data) << " ";
//         p=p->left;

//     }
// }
void create()
{
    queue<struct Node *> q;
    Node *p, *t, *head;
    int x;
    cout << "Enter the node value";
    cin >> x;
    head = new struct Node;
    head->data = x;
    head->left = 0;
    head->right = 0;
    q.push(head);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        cout << "Enter left child";
        cin >> x;
        if (x != -1)
        {
            t = new struct Node;
            t->data = x;
            t->left = 0;
            t->right = 0;
            p->left = t;
            q.push(t);
        }
        cout << "Enter the right child";
        cin >> x;
        if (x != -1)
        {
            t = new struct Node;
            t->data = x;
            t->left = 0;
            t->right = 0;
            p->right = t;
            q.push(t);
        }
        // p=q.front();
    }
}

void Preorder(Node *p)
{
    if (p)
    {
        cout << (p->data);
        Preorder(p->left);
        Preorder(p->right);
    }
}

int main()
{

    create();
    Preorder(head);
    return 0;
}
