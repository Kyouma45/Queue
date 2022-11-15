#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} * node;

node front = NULL, rear = NULL;

void enqueue(int k)
{
    node ptr = malloc(sizeof(struct Node));
    ptr->data = k;
    if (front == NULL)
    {
        ptr->next == NULL;
        front = rear = ptr;
    }
    else
    {
        rear->next = ptr;
        rear = ptr;
    }
}

void dequeue()
{
    node ptr = front;
    if (rear == front)
    {
        front = rear = NULL;
        free(ptr);
    }
    else if (front == NULL)
    {
        printf("Underflow!!!");
    }
    else
    {
        front = ptr->next;
        free(ptr);
    }
}

void display()
{
    node ptr = front;
    while (ptr != rear)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n", ptr->data);
}

int main()
{
    while (1)
    {

        int p, r;
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
            enqueue(r);
        }
        else if(p==2)
        {
            dequeue();
        }
        else
        {
            display();
        }
    }
}