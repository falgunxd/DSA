#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *head;

void display(Node *p)
{
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl
         << "End of the list\n\n";
}

void create(Node *p, int n)
{
    if (!p)
    {
        while (p->next != 0)
        {
            p = p->next;
        }
    }
    Node *last = p;
    while (n--)
    {
        Node *t = new struct Node;
        t->data = n;
        t->next = 0;
        last->next = t;
        last = t;
    }
}

void InsertEnd(Node *p, int k)
{
    if (p != NULL)
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
    }
    Node *t = new struct Node;
    t->data = k;
    t->next = 0;
    p->next = t;
}
Node *InsertStart(Node *p, int k)
{
    if (p != NULL)
    {
        Node *t = new struct Node;
        t->data = k;
        t->next = p;
        p = t;
        return p;
    }
    Node *t = new struct Node;
    t->data = k;
    t->next = NULL;
    return t;
}
void reverse()
{
    // Initialize current, previous and next pointers
    struct Node *current = head;
    struct Node *prev = NULL, *next = NULL;

    while (current != NULL)
    {
        // Store next
        next = current->next;
        // Reverse current node's pointer
        current->next = prev;
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;
}
int main()
{
    Node *head = new Node;
    head->data = 100;
    head->next = 0;
    create(head, 10);
    printf ("This is the original linked list");
    display(head);
    // InsertEnd(head, 346);
    // display(head);
    // head = InsertStart(head, 23);
    // display(head);
    printf("This is the reversed linked list");
    reverse();
    display(head);
    return 0;
}
