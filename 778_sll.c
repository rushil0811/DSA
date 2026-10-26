#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int reg_no;
    char name[10];
    struct node *next;
};

void create(struct node *head)
{
    struct node *curr, *prev;
    char ch;

    prev = head;

    do
    {
        curr = (struct node *)malloc(sizeof(struct node));

        if (curr == NULL)
        {
            printf("Memory allocation failed!\n");
            return;
        }

        curr->next = NULL;

        printf("\nEnter Registration Number: ");
        scanf("%d", &curr->reg_no);

        printf("Enter Name: ");
        scanf("%9s", curr->name);

        prev->next = curr;
        prev = curr;

        printf("Want to add more? (Y/N): ");
        scanf(" %c", &ch);

    } while (ch == 'Y' || ch == 'y');
}

void display(struct node *head)
{
    struct node *curr;

    curr = head->next;

    if (curr == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }

    printf("\n===== LINKED LIST =====\n");

    while (curr != NULL)
    {
        printf("\nRegistration No : %d", curr->reg_no);
        printf("\nName            : %s", curr->name);
        printf("\nCurrent Node    : %p", (void *)curr);
        printf("\nNext Node       : %p", (void *)curr->next);
        printf("\n-------------------------");

        curr = curr->next;
    }
}

void count(struct node *head)
{
    struct node *curr;
    int count = 0;

    curr = head->next;

    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }

    printf("\nTotal Participants = %d\n", count);
}

void reverse(struct node *head)
{
    struct node *prev = NULL;
    struct node *curr = head->next;
    struct node *next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head->next = prev;

    printf("\nList reversed successfully.\n");
}

void sort(struct node *head)
{
    struct node *i, *j;
    int tempReg;
    char tempName[10];

    for (i = head->next; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->reg_no > j->reg_no)
            {
                tempReg = i->reg_no;
                i->reg_no = j->reg_no;
                j->reg_no = tempReg;

                strcpy(tempName, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, tempName);
            }
        }
    }

    printf("\nList sorted successfully.\n");
}

void removeStudent(struct node *head)
{
    struct node *prev, *curr;
    int reg_no;

    printf("\nEnter Registration Number to remove: ");
    scanf("%d", &reg_no);

    prev = head;
    curr = head->next;

    while (curr != NULL && curr->reg_no != reg_no)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL)
    {
        printf("\nStudent not found.\n");
        return;
    }

    prev->next = curr->next;
    free(curr);

    printf("\nStudent removed successfully.\n");
}

int main()
{
    struct node *head;
    int choice;

    head = (struct node *)malloc(sizeof(struct node));

    if (head == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    head->next = NULL;

    do
    {
        printf("\n\n SINGLY LINKED LIST ");
        printf("\n1. Create / Add Students");
        printf("\n2. Display");
        printf("\n3. Count Total Participants");
        printf("\n4. Sort List");
        printf("\n5. Reverse List");
        printf("\n6. Remove Student");
        printf("\n7. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                create(head);
                break;

            case 2:
                display(head);
                break;

            case 3:
                count(head);
                break;

            case 4:
                sort(head);
                break;

            case 5:
                reverse(head);
                break;

            case 6:
                removeStudent(head);
                break;

            case 7:
                printf("\nProgram terminated.\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 7);

    return 0;
}

