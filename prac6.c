/*
    Data Structures Practical 6
    Aim: Implement a singly linked list and perform
         insertion, deletion and display operations.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertBeginning()
{
    int value;

    struct node *newNode =
        (struct node *)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertEnd()
{
    int value;

    struct node *newNode =
        (struct node *)malloc(sizeof(struct node));

    struct node *temp;

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void insertAfter()
{
    int value, key;

    struct node *temp;
    struct node *newNode;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);

    printf("Insert after which node: ");
    scanf("%d", &key);

    temp = head;

    while(temp != NULL && temp->data != key)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("Node not found\n");
        return;
    }

    newNode =
        (struct node *)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFirst()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;

    printf("%d deleted\n", temp->data);

    free(temp);
}

void deleteLast()
{
    struct node *temp, *prev;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if(head->next == NULL)
    {
        printf("%d deleted\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;

    printf("%d deleted\n", temp->data);

    free(temp);
}

void deleteAfter()
{
    int key;

    struct node *temp;
    struct node *deleteNode;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Delete node after which node: ");
    scanf("%d", &key);

    temp = head;

    while(temp != NULL && temp->data != key)
        temp = temp->next;

    if(temp == NULL || temp->next == NULL)
    {
        printf("Node not available\n");
        return;
    }

    deleteNode = temp->next;
    temp->next = deleteNode->next;

    printf("%d deleted\n", deleteNode->data);

    free(deleteNode);
}

void display()
{
    struct node *temp = head;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n--- SINGLY LINKED LIST ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After Given Node\n");
        printf("4. Delete First Node\n");
        printf("5. Delete Last Node\n");
        printf("6. Delete Node After Given Node\n");
        printf("7. Display All Nodes\n");
        printf("8. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: insertBeginning(); break;
            case 2: insertEnd(); break;
            case 3: insertAfter(); break;
            case 4: deleteFirst(); break;
            case 5: deleteLast(); break;
            case 6: deleteAfter(); break;
            case 7: display(); break;
            case 8: break;
            default: printf("Invalid choice\n");
        }

    } while(choice != 8);

    return 0;
}