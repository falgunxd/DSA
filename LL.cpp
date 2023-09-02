#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} * first;

void create(int a[], int n)
{
    int i;
    struct Node *t, *last;
    first = new struct Node;
    first->data = a[0];
    first->next = NULL;
    last = first;

    for (i = 1; i++; i < n)
    {
        t = new struct Node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void display(struct Node *p)
{
    while (p != 0)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int main()
{
    int s[] = {1, 2, 3, 4, 5};
    create(s, 5);
    display(first);

    return 0;
}