#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Cqueue
{
    int f;
    int r;
    int size;
    int *arr;
};
int isFull(struct Cqueue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {

        return 1;
    }
    else
        return 0;
}
int isEmpty(struct Cqueue *q)
{
    if (q->r == q->f)
    {

        return 1;
    }
    else
        return 0;
}
void enqueue(struct Cqueue *q, int val)
{
    // check overflow condn.
    if (isFull(q))
    {
        cout << "\nQueue overflow\n";
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
    }
}
int dequeue(struct Cqueue *q)
{
    int a = -1;
    // check underflow condn.
    if (isEmpty(q))
    {
        cout << "Empty queue\n";
    }
    // push the queue and insert
    else
    {
        q->f = (q->f + 1) % q->size;
        a = q->arr[q->f];
    }
    return a;
}
int main()
{
    struct Cqueue q;
    // assign initial values
    q.size = 6;
    q.f = q.r = 0;
    // creating a dynamic array
    q.arr = (int *)malloc(q.size * sizeof(int));
    // enqueue(&q, 20)->shows overflow as would exceed the size
    enqueue(&q, 25);
    enqueue(&q, 89);
    enqueue(&q, 73);
    enqueue(&q, 21);
    enqueue(&q, 44);
    for (int i = 1; i < q.size; i++)
    {
        cout << q.arr[i] << "\t";
    }
    cout << "\ndequeueing Element:" << dequeue(&q) << endl;
    if (isFull(&q))
    {
        cout << "\nQueue is full\n";
    }
    return 0;
}