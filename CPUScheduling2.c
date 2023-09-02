#include<stdio.h>
#include<stdlib.h>

int qsiz = 10;

typedef struct queue{
    char element[50];
    int p;
    int cb;
}queue;

typedef struct queue_l{
    char element[50];
    int p;
    int cb;
    struct queue_l *next;
}queue_l;

typedef struct heapNode{
    int size;
    queue **tasks;
}heapNode;

void FCFS_Imp(){
    FILE *f=fopen("input.txt","r");
    int n;
    fscanf(f,"%d\n",&n);
    queue *t[n];
    for(int i=0;i<n;i++){
        queue temp=(queue)malloc(sizeof(queue));
        fscanf(f,"%s %d %d\n",temp->element,&temp->p,&temp->cb);
        t[i]=temp;
    }
    printf("\n");

    for (int i = 0; i < n; i++){
 
        printf("< %s >",t[i]->element);
    }
    
    printf("[]\n");

    fclose(f);
}

void heap_insert(heapNode *h,queue *t,int sorp){
    h->tasks[h->size]=t;
    if(h->size==0) return;
    int s=h->size;
    while(s>0 && sorp?((h->tasks[(s-1)/2])->cb > (h->tasks[s])->cb):((h->tasks[(s-1)/2])->p < (h->tasks[s])->p) ){
        queue *temp = h->tasks[(s-1)/2];
        h->tasks[(s-1)/2] = h->tasks[s];
        h->tasks[s] = temp;
        s=(s-1)/2;
    }
}

void heapify(heapNode *h,int ind,int sorp){
    int l=2*ind+1;
    int r=2*ind+2;
    int s=ind;
    if (l < h->size && (sorp?(h->tasks[l]->cb < h->tasks[s]->cb):(h->tasks[l]->p > h->tasks[s]->p))) {
        s = l;
    }
    if (r < h->size && (sorp?(h->tasks[r]->cb < h->tasks[s]->cb):(h->tasks[r]->p > h->tasks[s]->p)) ){
        s = r;
    }
    if (s != ind){
        queue *temp = h->tasks[ind];
        h->tasks[ind] = h->tasks[s];
        h->tasks[s] = temp;
        heapify(h, s,sorp);
    }
}

queue *heap_delete(heapNode *h,int sorp){
    queue *st=h->tasks[0];
    h->tasks[0]=h->tasks[h->size-1];
    h->size--;
    heapify(h,0,sorp);
    return st;
}

void SJFirst(int sorp){
    FILE *f=fopen("input.txt","r");
    int n;
    fscanf(f,"%d\n",&n);
    heapNode h=(heapNode)malloc(sizeof(heapNode));
    h->size=0;
    h->tasks=(queue**)malloc(n*sizeof(queue));
    for(int i=0;i<n;i++){
        queue t=(queue)malloc(sizeof(queue));
        fscanf(f,"%s %d %d\n",t->element,&t->p,&t->cb);
        heap_insert(h,t,sorp);
        h->size++;
    }
    printf("\n");
    for(int i=0;i<n;i++){
        queue *st=heap_delete(h,sorp);
        printf("[] %s ",st->element);
    }
    printf("[]\n");
}

void rr(){
    FILE *f=fopen("input.txt","r");
    int n;
    fscanf(f,"%d\n",&n);
    queue_l thead=(queue_l)malloc(sizeof(queue_l)),*temp=thead;
    for(int i=0;i<n;i++){
        fscanf(f,"%s %d %d\n",temp->element,&temp->p,&temp->cb);
        temp->next=i!=n-1?(queue_l*)malloc(sizeof(queue_l)):thead;
        temp=i!=n-1?temp->next:temp;
    }
    queue_l *pre=temp;
    temp=thead;
    printf("\n");
    while(1){
        temp->cb-=qsiz;
        if(temp->cb<=0){
            printf("[] %s ",temp->element);
            pre->next=temp->next;
            if(pre==temp){
                free(temp);
                break;
            }
            free(temp);
            temp=pre->next;
            if(pre==temp){
                printf("[] %s ",temp->element);
                break;
            }
        }else{
            pre=temp;
            temp=temp->next;
        }
    }
    printf("[]\n");

    fclose(f);
}

void MultiLevel(){
    printf("\nImplement using an array of p_queue\n\n");
}

int main(){

    while(1){
        int c;
        printf("\nMENU\n\n");
        printf("\n1. First Come First Serve\n
        2. Shortest Job First\n
        3. Shortest Remaining Time First\n
        4. Priority Scheduling\n
        5. Round Robin\n
        6. Multilevel-Feedback Queue Scheduling\n
        7. Exit\n\n
        Enter Your choice :  ");
        scanf("%d",&c);
        if(c==7) break;
        switch (c)
        {
        case 1:
            FCFS_Imp();
            break;
        case 2:
            SJFirst(1);
            break;
        case 3:
            SJFirst(1);
            break;
        case 4:
            SJFirst(0);
            break;
        case 5:
            rr();
            break;
        case 6:
            MultiLevel();
            break;
        default:
            printf("\nEnter a valid choice\n");
            break;
        }
    }

    return 0;
}