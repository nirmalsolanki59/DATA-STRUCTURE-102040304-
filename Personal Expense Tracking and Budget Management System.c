/*
    Data Structures Mini Project

    Title:
    Personal Expense Tracking and Budget Management System

    Data Structure Used:
    Singly Linked List
*/

#include <stdio.h>
#include <stdlib.h>

struct Expense
{
    int id;
    char category[30];
    float amount;
    char description[50];
    struct Expense *next;
};

struct Expense *head = NULL;
float budget = 0;


/* Create a new node */
struct Expense* createNode()
{
    struct Expense *newNode;

    newNode = (struct Expense*)malloc(sizeof(struct Expense));

    if(newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("\nEnter Expense ID: ");
    scanf("%d", &newNode->id);

    printf("Enter Category: ");
    scanf("%s", newNode->category);

    printf("Enter Amount: ");
    scanf("%f", &newNode->amount);

    printf("Enter Description: ");
    scanf(" %[^\n]", newNode->description);

    newNode->next = NULL;

    return newNode;
}


/* Add a new expense */
void addExpense()
{
    struct Expense *newNode;
    struct Expense *temp;

    newNode = createNode();

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("\nExpense added successfully.\n");
}


/* Display all expenses */
void displayExpenses()
{
    struct Expense *temp = head;

    if(head == NULL)
    {
        printf("\nNo expenses found.\n");
        return;
    }

    printf("\n---------------- EXPENSE LIST ----------------\n");
    printf("ID\tCategory\tAmount\tDescription\n");
    printf("----------------------------------------------\n");

    while(temp != NULL)
    {
        printf("%d\t%s\t\t%.2f\t%s\n",
               temp->id,
               temp->category,
               temp->amount,
               temp->description);

        temp = temp->next;
    }
}


/* Search an expense */
void searchExpense()
{
    int id;
    struct Expense *temp = head;

    printf("\nEnter Expense ID to search: ");
    scanf("%d", &id);

    while(temp != NULL)
    {
        if(temp->id == id)
        {
            printf("\nExpense Found\n");
            printf("ID          : %d\n", temp->id);
            printf("Category    : %s\n", temp->category);
            printf("Amount      : %.2f\n", temp->amount);
            printf("Description : %s\n", temp->description);

            return;
        }

        temp = temp->next;
    }

    printf("\nExpense not found.\n");
}


/* Delete an expense */
void deleteExpense()
{
    int id;
    struct Expense *temp = head;
    struct Expense *prev = NULL;

    printf("\nEnter Expense ID to delete: ");
    scanf("%d", &id);

    while(temp != NULL)
    {
        if(temp->id == id)
        {
            if(prev == NULL)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }

            free(temp);

            printf("\nExpense deleted successfully.\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("\nExpense not found.\n");
}


/* Calculate total expense */
float calculateTotal()
{
    struct Expense *temp = head;
    float total = 0;

    while(temp != NULL)
    {
        total = total + temp->amount;
        temp = temp->next;
    }

    return total;
}


/* Set budget */
void setBudget()
{
    printf("\nEnter Budget: ");
    scanf("%f", &budget);

    printf("Budget set successfully.\n");
}


/* Check budget status */
void checkBudget()
{
    float total;
    float difference;

    if(budget <= 0)
    {
        printf("\nPlease set a valid budget first.\n");
        return;
    }

    total = calculateTotal();

    printf("\n------------- BUDGET STATUS -------------\n");
    printf("Budget        : %.2f\n", budget);
    printf("Total Expense : %.2f\n", total);

    if(total <= budget)
    {
        difference = budget - total;

        printf("Remaining     : %.2f\n", difference);
        printf("Status        : Within Budget\n");
    }
    else
    {
        difference = total - budget;

        printf("Exceeded By   : %.2f\n", difference);
        printf("Status        : Budget Exceeded\n");
    }
}


/* Free all allocated memory */
void freeList()
{
    struct Expense *temp;

    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}


/* Main function */
int main()
{
    int choice;

    do
    {
        printf("\n============================================");
        printf("\n     PERSONAL EXPENSE TRACKING SYSTEM");
        printf("\n============================================");

        printf("\n1. Add Expense");
        printf("\n2. Display Expenses");
        printf("\n3. Search Expense");
        printf("\n4. Delete Expense");
        printf("\n5. Calculate Total Expense");
        printf("\n6. Set Budget");
        printf("\n7. Check Budget");
        printf("\n8. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addExpense();
                break;

            case 2:
                displayExpenses();
                break;

            case 3:
                searchExpense();
                break;

            case 4:
                deleteExpense();
                break;

            case 5:
                printf("\nTotal Expense = %.2f\n", calculateTotal());
                break;

            case 6:
                setBudget();
                break;

            case 7:
                checkBudget();
                break;

            case 8:
                freeList();
                printf("\nProgram ended.\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while(choice != 8);

    return 0;
}