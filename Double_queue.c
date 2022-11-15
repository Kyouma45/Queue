#include <stdio.h>
typedef struct Queue
{
    int data[10];
    int front, rear;
} Queue;

void enqueue(Queue *que, int k, int t, int p)
{
    if (t == 0)
    {
        // input restricted
        if(que->front==0&&que->rear==9)
        {
            printf("Overflow!!!\n");
        }
        else if(que->front == -1)
        {
            que->front = que->rear = 0;
            que->data[que->front] = k;
        }
        else
        {
            que->rear += 1;
            que->data[que->rear] = k;
        }
    }
    else if(t==1)
    {
        // output restricted
        if (p == 0)
        {
            // input from the front
            if (que->front == 0 &&que->rear == 9)
            {
                printf("Overflow!!!\n");
            }
            else if(que->front == -1)
            {
                que->front = que->rear = 0;
                que->data[que->front] = k;
            }
            else
            {
                int i = que->rear;
                while (i >= 0)
                {
                    que->data[i + 1] = que->data[i];
                    i--;
                }
                que->data[que->front] = k;
                que->rear+=1;
            }
        }
        else if (p == 1)
        {
            // input from the rear
            if (que->front == 0 &&que->rear == 9)
            {
                printf("Overflow!!!\n");
            }
            else if (que->front == -1)
            {
                que->front = que->rear = 0;
                que->data[que->front] = k;
            }
            else
            {
                que->rear += 1;
                que->data[que->rear] = k;
            }
        }
    }
}

void dequeue(Queue *que, int t, int p)
{
    if(que->rear==que->front-1)
    {
        printf("Underflow!!!\n");
    }
    else if(t == 0)
    {
        // input restricted
        if (p == 0)
        {
            // delete from front
            que->front += 1;
        }
        else if (p == 1)
        {
            // delete from rear
            que->rear -= 1;
        }
    }
    else if(t==1)
    {
        // output restricted
        que->front += 1;
    }
}

void display(Queue *que)
{
    int k = que->front;
    while (k != que->rear)
    {
        printf("%d\n", que->data[k]);
        k++;
    }
    printf("%d\n", que->data[k]);
    printf("Front:%d\tRear:%d\n", que->front, que->rear);
}

int main()
{
    Queue q1;
    q1.front = q1.rear = -1;
    int l, m, k;
    printf("Enter 1 For Input Restricted Queue:\n");
    printf("Enter 2 For Output Restricted Queue:\n");
    scanf("%d", &l);
    if (l == 1)
    {
        while (1)  //input restricted
        {
            printf("Enter 1 To Enqueue:\n");
            printf("Enter 2 To Dequeue From Front:\n");
            printf("Enter 3 To Dequeue From Rear:\n");
            printf("Enter 4 To Display:\n");
            printf("Enter -1 To Exit\n");
            scanf("%d", &m);
            if (m == -1)
                return 0;
            if (m == 1)
            {
                printf("Enter Data To Insert:\n");
                scanf("%d", &k);
                enqueue(&q1, k, 0, 0);
            }
            else if (m == 2)
            {
                dequeue(&q1, 0, 0);
            }
            else if (m == 3)
            {
                dequeue(&q1, 0, 1);
            }
            else if (m == 4)
            {
                display(&q1);
            }
        }
    }
    else if (l == 2)
    {
        while (1)  //output restricted
        {
            printf("Enter 1 To Enqueue From Front:\n");
            printf("Enter 2 To Enqueue From Rear:\n");
            printf("Enter 3 To Dequeue:\n");
            printf("Enter 4 To Display:\n");
            printf("Enter -1 To Exit\n");
            scanf("%d", &m);
            if (m == -1)
                return 0;
            if (m == 1)
            {
                printf("Enter Data To Be Inserted:");
                scanf("%d", &k);
                enqueue(&q1, k, 1, 0);
            }
            else if (m == 2)
            {
                printf("Enter Data To Be Inserted:");
                scanf("%d", &k);
                enqueue(&q1, k, 1, 1);
            }
            else if (m == 3)
            {
                dequeue(&q1, 1, 0);
            }
            else if (m == 4)
            {
                display(&q1);
            }
        }
    }
}