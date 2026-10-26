---#include <stdio.h>
#include <string.h>

#define MAX 5

struct que
{
    int jobid;
    char title[50];
};

struct que q[MAX];
int front = 0, rear = 0;

int isQueueFull()
{
    if ((rear + 1) % MAX == front)
        return 1;
    else
        return 0;
}

int isQueueEmpty()
{
    if (front == rear)
        return 1;
    else
        return 0;
}

void addCQ()
{
    struct que item;
    if (isQueueFull())
    {
        printf("\nQueue is Full!\n");
        return;
    }

    printf("\nEnter Job ID: ");
    scanf("%d", &item.jobid);

    printf("Enter Job Title: ");
    scanf(" %[^\n]", item.title);

    rear = (rear + 1) % MAX;
    q[rear] = item;

    printf("\nJob inserted successfully.\n");
}

void delCQ()
{
    struct que item;
    if (isQueueEmpty())
    {
        printf("\nQueue is Empty!\n");
        return;
    }

    front = (front + 1) % MAX;
    item = q[front];

    printf("\nDeleted Job:\n");
    printf("Job ID    : %d\n", item.jobid);
    printf("Job Title : %s\n", item.title);
}

void displayCQ()
{
    int i;
    if (isQueueEmpty())
    {
        printf("\nQueue is Empty!\n");
        return;
    }

    printf("\n--- Circular Queue ---\n");

    i = (front + 1) % MAX;

    while (i != (rear + 1) % MAX)
    {
        printf("Job ID: %d\tJob Title: %s\n",
               q[i].jobid, q[i].title);

        i = (i + 1) % MAX;
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n1. Add Job\n");
        printf("2. Delete Job\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addCQ();
                break;

            case 2:
                delCQ();
                break;

            case 3:
                displayCQ();
                break;

            case 4:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}

