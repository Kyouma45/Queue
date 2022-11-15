#include <stdio.h>
typedef struct Queue
{
    int data[10];
    int front,rear;
} Queue;

void enqueue(Queue *que,int k)
{
    if ((que->front == 0 && que->rear ==9)||(que->rear == (que->front - 1) % (9)))
    {
        printf("Overflow!!!\n");
    }
    else if(que->front==-1)
    {
        que->front=que->rear=0;
        que->data[que->front]=k;
    }
    else
    {
        que->rear+=1;
        if(que->rear==10)
        que->rear=0;
        que->data[que->rear]=k;
    }
}

void dequeue(Queue *que)
{
    if(que->front==-1||(que->front==que->rear))
    {
        printf("Underflow!!!\n");
    }
    else
    {
        que->front+=1;
        if(que->front==10)
        {
            que->front=0;
        }
        if(que->front==que->rear+1)
        {
            que->front=que->rear=-1;
        }
    }
}

void display(Queue *que)
{
    int k=que->front;
    while(k!=que->rear)
    {
        printf("%d\n",que->data[k]);
        k++;
        if(k==10)
        k=0;
    }
    printf("%d\n",que->data[que->rear]);
    printf("Front:%d\tRear:%d\n",que->front,que->rear);
}

int main()
{
    Queue q1;
    q1.front=q1.rear=-1;
    int p,r;
    while(1)
    {
        printf("Enter 1 To Insert:\n");
        printf("Enter 2 To Delete:\n");
        printf("Enter 3 To Display:\n");
        printf("Enter -1 To Exit:\n");
        scanf("%d", &p);
        if (p == -1)
        {
            return 0;
        }
        if (p == 1)
        {
            printf("Enter Data To Be Inserted:\n");
            scanf("%d", &r);
            enqueue(&q1, r);
        }
        else if (p == 2)
        {
            dequeue(&q1);
        }
        else if (p == 3)
        {
            display(&q1);
        }
    }

    return 0;
}