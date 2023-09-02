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
    struct Node *new1;
    new1= new struct Node;
    cout<<"Enter data at the top of ll";
    cin>>new1->data;
    new1->next=p;
    head=new1;
    p=new1;
}
void InsertEnd(struct Node *p)
{
    struct Node *t;
    t=new struct Node;
    t->next = NULL;
    int a;
    cout << "Enter the data for inserting at the end";
    cin >> a;
    t->data=a;
    // struct Node *old;
    // old=p;
    while (p->next != 0)
    {
        p=p->next;
    }
    p->next=t;

}

void InsertBtw(struct Node *p)
{
    int s;
    cout<<"Enter the element after which you want to enter the new node";
    cin>>s;
    struct Node *point;
    point= new struct Node;
    point =p;
    while (point->next!=0)
    {
        if(point->data==s)
        {
            struct Node *neww;
            neww=new struct Node;
            cout<<"Enter the data in the new node after "<<s;
            cin>>neww->data;
            neww->next=point->next;
            point->next=neww;
            
        }
        point=point->next;
    }
    
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
        t->data = i+1;
        t->next = NULL;
        last->next = t;
        last = t;
    }
    display(head);
    InsertEnd(head);
    display(head);
    InsertStart(head);
    display(head);
    InsertBtw(head);
    display(head);
    
    return 0;
}