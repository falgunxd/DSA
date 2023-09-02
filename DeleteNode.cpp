#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} * head;

void display(struct Node *p)
{
    while (p != 0)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

void InsertStart(struct Node *p)
{
    struct Node *new1 = new struct Node;
    cout << "Enter data at the top of ll";
    cin >> (new1->data);
    new1->next = head;
    head = new1;
}

void InsertEnd(struct Node *p)
{
    struct Node *t;
    t = new struct Node;
    t->next = NULL;
    cout << "Enter the data for inserting at the end";
    cin >> t->data;

    while (p->next != 0)
    {
        p = p->next;
    }
    p->next = t;
}
void InsertBtw(struct Node *p, int find, int key)
{
    struct Node *current = p, *other;
    while (current->data == find)
    {
        current = current->next;
    }
    other = current->next;
    struct Node *naya = new struct Node;
    naya->data = key;
    naya->next = other;
    current->next = naya;
}

void DeleteStart(struct Node *p)
{
    struct Node *temp;
    temp = p;
    p = p->next;
    free(temp);
}

void DeleteEnd(struct Node *p)
{
    struct Node *last, *point;
    last = p;
    while ((last->next)->next != NULL)
    {
        last = last->next;
    }
    point = last->next;
    last->next = NULL;
    free(point);
    head = p;
}

void DeleteBtw(struct Node *p, int key)
{
    struct Node *last, *cont;
    last = p;
    while ((last->next)->data != key)
    {
        last = last->next;
    }
    cont = last->next->next;
    free(last->next);
    last->next = cont;
    head = p;
}

int main()
{
    head = new struct Node;
    head->data = 1;
    head->next = NULL;
    struct Node *t, *last;
    last = head;
    for (int i = 1; i < 10; i++)
    {
        t = new struct Node;
        t->data = i + 1;
        t->next = NULL;
        last->next = t;
        last = t;
    }
    display(head);
    InsertEnd(head);
    display(head);
    InsertStart(head);
    display(head);
    InsertBtw(head, 8, 366);
    display(head);
    DeleteStart(head);
    display(head);
    DeleteEnd(head);
    display(head);
    DeleteBtw(head, 366);
    display(head);
    return 0;
}