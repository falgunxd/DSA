#include <stdio.h>
#include <stdlib.h>
#define q 10;
typedef struct task
{
    char name[50];
    int p;
    int cb;
} task;
typedef struct task_ll
{
    char name[50];
    int p;
    int cb;
    struct task_ll *next;
} task_ll;
typedef struct heap
{
    int size;
    task **tasks;
} heap;
void fcfs()
{
    FILE *f = fopen("input.txt", "r");
    int n;
    fscanf(f, "%d\n", &n);
    task *t[n];
    for (int i = 0; i < n; i++)
    {
        task *temp = (task *)malloc(sizeof(task));
        fscanf(f, "%s %d %d\n", temp->name, &temp->p, &temp->cb);
        // fscanf(f, "%s %d %d\n", &t[i].name, &t[i].p, &t[i].cb);
        // t[i].name=
        // t[i].p
        // t[i].cb
        t[i] = temp;
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("< %s >", t[i]->name);
    }
    printf("\n");
    fclose(f);
}
void heap_insert(heap *h, task *t, int sorp)
{
    h->tasks[h->size] = t;
    if (h->size == 0)
        return;
    int s = h->size;
    while (s > 0 && sorp ? ((h->tasks[(s - 1) / 2])->cb >
                            (h->tasks[s])->cb)
                         : ((h->tasks[(s - 1) / 2])->p < (h->tasks[s])->p))
    {
        task *temp = h->tasks[(s - 1) / 2];
        h->tasks[(s - 1) / 2] = h->tasks[s];
        h->tasks[s] = temp;
        s = (s - 1) / 2;
    }
}
void heapify(heap *h, int ind, int sorp)
{
    int l = 2 * ind + 1;
    int r = 2 * ind + 2;
    int s = ind;
    if (l < h->size && (sorp ? (h->tasks[l]->cb <
                                h->tasks[s]->cb)
                             : (h->tasks[l]->p > h->tasks[s]->p)))
    {
        s = l;
    }
    if (r < h->size && (sorp ? (h->tasks[r]->cb <
                                h->tasks[s]->cb)
                             : (h->tasks[r]->p > h->tasks[s]->p)))
    {
        s = r;
    }
    if (s != ind)
    {
        task *temp = h->tasks[ind];
        h->tasks[ind] = h->tasks[s];
        h->tasks[s] = temp;
        heapify(h, s, sorp);
    }
}
task *heap_delete(heap *h, int sorp)
{
    task *st = h->tasks[0];
    h->tasks[0] = h->tasks[h->size - 1];
    h->size--;
    heapify(h, 0, sorp);
    return st;
}


void sjf_ps(int sorp)
{
    FILE *f = fopen("input.txt", "r");
    int n;
    fscanf(f, "%d\n", &n);
    heap *h = (heap *)malloc(sizeof(heap));
    h->size = 0;
    h->tasks = (task **)malloc(n * sizeof(task));
    for (int i = 0; i < n; i++)
    {
        task *t = (task *)malloc(sizeof(task));
        fscanf(f, "%s %d %d\n", t->name, &t->p, &t->cb);
        heap_insert(h, t, sorp);
        h->size++;
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        task *st = heap_delete(h, sorp);
        printf("| %s ", st->name);
    }
    printf("|\n");
}
void rr()
{
    FILE *f = fopen("input.txt", "r");
    int n;
    fscanf(f, "%d\n", &n);
    task_ll *thead = (task_ll *)malloc(sizeof(task_ll)), *temp = thead;
    for (int i = 0; i < n; i++)
    {
        fscanf(f, "%s %d %d\n", temp->name, &temp->p, &temp->cb);
        temp->next = i != n - 1 ? (task_ll *)malloc(sizeof(task_ll)) : thead;
        temp = i != n - 1 ? temp->next : temp;
    }
    task_ll *pre = temp;
    temp = thead;
    printf("\n");
    while (1)
    {
        temp->cb -= q;
        if (temp->cb <= 0)
        {
            printf("< %s >", temp->name);
            pre->next = temp->next;
            if (pre == temp)
            {
                free(temp);
                break;
            }
            free(temp);
            temp = pre->next;
            if (pre == temp)
            {
                printf("< %s >", temp->name);
                break;
            }
        }
        else
        {
            pre = temp;
            temp = temp->next;
        }
    }
    printf("\n");
    fclose(f);
}

int main()
{
    while (1)
    {
        int c;
        printf("\nWhat CPU algorithm do you wanna use\n");
        printf("1. First Come First Server\n");
        printf("2. Shortest Job First\n");
        printf("3. Shortest Remaining Time First\n");
        printf("4. Priority Scheduling\n");
        printf("5. Round Robin\n");
        printf("6. Multilevel Feedback queue\n");
        printf("7. Exit\n");
        printf("\nEnter your choice\n");

        scanf("%d", &c);
        if (c == 7)
            break;
        switch (c)
        {
        case 1:
            fcfs();
            break;
        case 2:
            sjf_ps(1);
            break;
        case 3:
            sjf_ps(1);
            break;
        case 4:
            sjf_ps(0);
            break;
        case 5:
            rr();
            break;
        case 6:
            printf("Sorry I couldn't implement this algorithm yet");
            break;
        default:
            printf("\nEnter a valid choice\n");
            break;
        }
    }
    return 0;
}
