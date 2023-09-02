#include <iostream>
using namespace std;

struct Node
{
    struct Node *lchild;
    string Name;
    int Marks;
    struct Node *rchild;
} *root = NULL;
// void RInsert(stuct node *p, string naam, int key)
// {
//     if (naam > p->Name)
//         p->rchild = RInsert(p->rchild)
// }
void Insert(string naam, int key)
{
    struct Node *t = root;
    struct Node *p, *r = NULL;

    if (root == NULL)
    {
        p = new struct Node;
        p->Marks = key;
        p->Name = naam;
        p->lchild = NULL;
        p->rchild = NULL;
        root = p;
        return;
    }

    while (t != NULL)
    {
        r = t;
        if (naam < t->Name)
            t = t->lchild;
        else if (naam > t->Name)
            t = t->rchild;
        else
            return;
    }
    p = new struct Node;
    p->Marks = key;
    p->Name = naam;
    p->lchild = NULL;
    p->rchild = NULL;
    if (naam < r->Name)
        r->lchild = p;
    else
        r->rchild = p;
}
void delete (string naam)
{
    struct Node *t = root;
    struct Node *r = t;
    while (t)
    {
        if (naam == t->Name)
        {
            if ((!t->lchild) && (!t->rchild))
                free(t);
            else if (!t->lchild)
            {
                struct Node *p = t;
                t = t->rchild;
                r->rchild = t;
                free(p);
            }
        }
        else if (naam < t->Name)
        {
            r = t;
            t = t->lchild;
        }
        else
        {
            r = t;
            t = t->rchild;
        }
    }
}
void RecursiveInsert(struct Node *p, int key)
{
    if (p)
}

void getPrevious(string naam)
{
    struct Node *t = root;
    while (t != NULL)
    {
        if (naam == t->Name)
        {
            t = t->lchild;
            while (t->rchild != NULL)
            {
                t = t->rchild;
            }
            cout << t->Marks;
        }
        else if (naam < t->Name)
            t = t->lchild;
        else
            t = t->rchild;
    }
}

int main()
{
    Insert("Falgun", 100);
    Insert("ChaChaJo", 99);
    Insert("Abhay", 69);
    Insert("Sakshi", 64);
    Insert("Priya", 84);
    Insert("WowBhai", 12);
    Insert("LolBhai", 33);
    // Insert("Qutub Minar", 3986);
    // Insert("Acr", 0);

    getPrevious("Sakshi");
    getPrevious("Falgun");
    // getPrevious("ChaChaJo");
    // getPrevious("Gaurav");

    return 0;
}