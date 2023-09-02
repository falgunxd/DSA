#include <iostream>
using namespace std;


struct Node
{
    int data;
    struct Node * next;

}*first=NULL;



void createLL(int A[], int n)
{
    int i;
    struct Node *t,*last;
    first = new struct Node;
    first -> data = A[0];
    first ->next=NULL;
    last=first;
    for (i =1; i<n; i++)
    {
        t = new struct Node;
        t-> data =A[i];
        t->next=NULL;
        last->next =t;
        last =t;

    }
}


void DisplayLL(struct Node *p)
{   
    while (p!=0)
    {
        cout<<p->data<<" ";
        p=p->next;
    }


}

int main()
{
    int A[]={3,5,7,10,15};
    createLL(A,5);
    DisplayLL(first);
    return 0;
}