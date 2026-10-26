/*
    Data Structures Practical 5(A)
    Aim: Implement a simple queue using an array and
         perform enqueue(), dequeue() and display().
*/

#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue()
{
    int value;

    if(rear == MAX - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        printf("Enter value: ");
        scanf("%d", &value);

        if(front == -1)
            front = 0;

        rear++;
        queue[rear] = value;

        printf("%d inserted into queue\n", value);
    }
}

void dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("%d deleted from queue\n", queue[front]);
        front++;
    }
}

void display()
{
    int i;

    if(front == -1 || front > rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements are: ");

        for(i = front; i <= rear; i++)
            printf("%d ", queue[i]);

        printf("\n");
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n--- SIMPLE QUEUE ---\n");
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