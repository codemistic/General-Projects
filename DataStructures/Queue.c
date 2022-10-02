#include <stdio.h>
#include <stdlib.h>
#define MAXQUEUE 5
#define TRUE 1
#define FALSE 0

struct queue
{
    int item[MAXQUEUE];
    int front;
    int rear;
};

void init(struct queue *pq);
void insert(struct queue *pq, int x);
int remov(struct queue *pq);
int empty(struct queue *pq);

void main()
{
    struct queue q;
    int x, c;
    char ch;
    system("cls");
    init(&q);

start:
    printf("1. Initialise the queue\n");
    printf("2. Insert in the queue\n");
    printf("3. Remove from the queue\n");
    printf("4. Exit\n");
    printf("==============================\n");
    printf("Enter your choice :\t");
    scanf("%d", &c);

    switch (c)
    {
    case 1:
        init(&q);
        break;
    case 2:
        printf("Enter the element to be inserted :\n");
        scanf("%d", &x);
        insert(&q, x);
        break;
    case 3:
        x = remov(&q);
        printf("Removed item is :=>\t%d\n", x);
        break;
    case 4:
        exit(1);
    default:
        printf("Wrong choice!\n");
        break;
    }

    printf("Do you wish to continue? (y/n)\n");
    fflush(stdin);
    scanf(" %c", &ch);
    if (ch == 'y' || ch == 'Y')
    {
        goto start;
    }
}

void init(struct queue *pq)
{
    pq->rear = -1;
    pq->front = 0;
}

void insert(struct queue *pq, int x)
{
    if (pq->rear == MAXQUEUE - 1)
    {
        printf("Queue overflow\n");
        exit(1);
    }
    pq->rear++;
    pq->item[pq->rear] = x;
}

int remov(struct queue *pq)
{
    int x;
    if (empty(pq))
    {
        printf("Queue underflow\n");
        exit(1);
    }
    x = pq->item[pq->front];
    pq->front++;
    return x;
}

int empty(struct queue *pq)
{
    if (pq->rear - pq->front + 1 == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}