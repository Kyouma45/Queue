#include <stdio.h>

struct Queue
{
    int data[40];
    int front, rear;
};

void insertion(struct Queue *que, int k)
{
    if (que->front == -1 && que->rear == -1)
    {
        que->front += 1;
        que->rear += 1;
        que->data[que->rear] = k;
    }
    else if (que->rear == 39)
    {
        printf("List Is Full!!!");
    }
    else
    {
        que->rear += 1;
        que->data[que->rear] = k;
    }
}

/*void delete(struct Queue *que)  //O(1)
{
    if(que->front==-1&&que->rear==-1)
    {
        printf("Queue Underflow!!!");
    }
    else if(que->front==que->rear)
    {
        que->front=que->rear=-1;
    }
    else
    {
        que->front-=1;
    }
}*/

void delete (struct Queue *que)  //O(n)
{
    if (que->front == -1 && que->rear == -1)
    {
        printf("Queue Underflow!!!\n");
    }
    else if (que->front == que->rear)
    {
        que->front = que->rear = -1;
    }
    else
    {
        for(int i=0;i<que->rear;i++)
        {
            que->data[i]=que->data[i+1];
        }
        que->rear-=1;
    }
}

void Display(struct Queue *que)
{
    for (int k = que->front; k <= que->rear; k++)
    {
        printf("%d\n", que->data[k]);
    }
}

int main()
{
    int p, r;
    struct Queue q1;
    q1.front = -1;
    q1.rear = -1;
    while (1)
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
            insertion(&q1, r);
        }
        else if (p == 2)
        {
            delete (&q1);
        }
        else if (p == 3)
        {
            Display(&q1);
        }
    }
}