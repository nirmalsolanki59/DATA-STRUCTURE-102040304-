/*
    Data Structures Practical 5(B)
    Aim: Implement a circular queue using an array and
         perform enqueue(), dequeue() and display().
*/

#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue()
{
    int value;

    if((rear + 1) % MAX == front)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        printf("Enter value: ");
        scanf("%d", &value);

        if(front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX;
        }

        queue[rear] = value;

        printf("%d inserted into circular queue\n", value);
    }
}

void dequeue()
{
    if(front == -1)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("%d deleted from circular queue\n", queue[front]);

        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }
}

void display()
{
    int i;

    if(front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Circular queue elements are: ");

        i = front;

        while(1)
        {
            printf("%d ", queue[i]);

            if(i == rear)
                break;

            i = (i + 1) % MAX;
        }

        printf("\n");
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n--- CIRCULAR QUEUE ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 4);

    return 0;
}