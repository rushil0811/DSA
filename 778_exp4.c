#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

/* Check if stack is full */
bool isFull()
{
    return top == MAX - 1;
}

/* Check if stack is empty */
bool isEmpty()
{
    return top == -1;
}

/* Push element into stack */
void push(char item)
{
    if (!isFull())
    {
        top++;
        stack[top] = item;
    }
    else
    {
        printf("Stack Overflow\n");
    }
}

/* Pop element from stack */
char pop()
{
    char temp;

    if (!isEmpty())
    {
        temp = stack[top];
        top--;
        return temp;
    }
    else
    {
        printf("Stack Underflow\n");
        return '\0';
    }
}

/* Display stack */
void display()
{
    int i;

    if (isEmpty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack: ");

        for (i = top; i >= 0; i--)
        {
            printf("%c ", stack[i]);
        }

        printf("\n");
    }
}

/* Incoming priority */
int icp(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;

    if (ch == '*' || ch == '/')
        return 2;

    if (ch == '^')
        return 4;

    if (ch == '(')
        return 5;

    return 0;
}

/* In-stack priority */
int isp(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;

    if (ch == '*' || ch == '/')
        return 2;

    if (ch == '^')
        return 3;

    if (ch == '(')
        return 0;

    return 0;
}

/* Reverse a string */
void reverse(char str[])
{
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

/* Swap opening and closing brackets */
void swapBrackets(char str[])
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(')
            str[i] = ')';

        else if (str[i] == ')')
            str[i] = '(';
    }
}

/* Infix to Postfix */
void in_post(char inexp[], char postexp[])
{
    int k = 0, i = 0;
    char tkn;

    top = -1;

    tkn = inexp[i];

    while (tkn != '\0')
    {
        /* Operand */
        if ((tkn >= 'a' && tkn <= 'z') ||
            (tkn >= 'A' && tkn <= 'Z') ||
            (tkn >= '0' && tkn <= '9'))
        {
            postexp[k++] = tkn;
        }

        /* Opening bracket */
        else if (tkn == '(')
        {
            push(tkn);
        }

        /* Closing bracket */
        else if (tkn == ')')
        {
            while (!isEmpty() && stack[top] != '(')
            {
                postexp[k++] = pop();
            }

            if (!isEmpty() && stack[top] == '(')
            {
                pop();
            }
        }

        /* Operator */
        else
        {
            while (!isEmpty() &&
                   stack[top] != '(' &&
                   isp(stack[top]) >= icp(tkn))
            {
                postexp[k++] = pop();
            }

            push(tkn);
        }

        i++;
        tkn = inexp[i];
    }

    /* Pop remaining operators */
    while (!isEmpty())
    {
        postexp[k++] = pop();
    }

    postexp[k] = '\0';
}

/* Infix to Prefix */
void in_prefix(char inexp[], char prefix[])
{
    char temp[MAX];
    char postexp[MAX];

    /* Copy original expression */
    strcpy(temp, inexp);

    /* Step 1: Reverse infix */
    reverse(temp);

    /* Step 2: Swap brackets */
    swapBrackets(temp);

    /* Step 3: Convert to postfix */
    in_post(temp, postexp);

    /* Step 4: Reverse postfix */
    reverse(postexp);

    /* Step 5: Store prefix */
    strcpy(prefix, postexp);
}

/* Main function */
int main()
{
    int choice;
    char item, deleted;
    char inexp[MAX];
    char postexp[MAX];
    char prefix[MAX];

    while (1)
    {
        printf("\n===== STACK & INFIX CONVERSION MENU =====\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Infix to Postfix\n");
        printf("5. Infix to Prefix\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter character to push: ");
                scanf(" %c", &item);

                push(item);
                break;

            case 2:
                deleted = pop();

                if (deleted != '\0')
                {
                    printf("Popped: %c\n", deleted);
                }

                break;

            case 3:
                display();
                break;

            case 4:
                printf("Enter infix expression: ");
                scanf("%s", inexp);

                in_post(inexp, postexp);

                printf("Postfix Expression: %s\n", postexp);
                break;

            case 5:
                printf("Enter infix expression: ");
                scanf("%s", inexp);

                in_prefix(inexp, prefix);

                printf("Prefix Expression: %s\n", prefix);
                break;

            case 6:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
