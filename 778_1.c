#include <stdio.h>
#include <stdlib.h>

void accept(int a[10][10], int r, int c)
{
    int i, j;

    printf("Enter the matrix elements:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (scanf("%d", &a[i][j]) != 1)
            {
                printf("Error: Invalid matrix element.\n");
                exit(1);
            }
        }
    }
}

void display(int a[10][10], int r, int c)
{
    int i, j;

    printf("\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
}

void addition(int a[10][10], int b[10][10], int r, int c)
{
    int i, j, sum[10][10];

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("\nAddition Result:");
    display(sum, r, c);
}

void subtraction(int a[10][10], int b[10][10], int r, int c)
{
    int i, j, sub[10][10];

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            sub[i][j] = a[i][j] - b[i][j];
        }
    }

    printf("\nSubtraction Result:");
    display(sub, r, c);
}

void multiplication(int a[10][10], int b[10][10], int r1, int c1, int c2)
{
    int i, j, k;
    int mul[10][10];

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            mul[i][j] = 0;
            for (k = 0; k < c1; k++)
            {
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("\nMultiplication Result:");
    display(mul, r1, c2);
}

void transpose(int a[10][10], int r, int c)
{
    int i, j;
    int t[10][10];

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            t[j][i] = a[i][j];
        }
    }

    printf("\nTranspose of Matrix A:");
    display(t, c, r);
}

int main()
{
    int a[10][10], b[10][10];
    int r1, c1, r2, c2;
    int ch;

    printf("Enter rows and columns of Matrix A (1-10): ");
    if (scanf("%d%d", &r1, &c1) != 2 || r1 < 1 || r1 > 10 || c1 < 1 || c1 > 10)
    {
        printf("Error: Invalid size for Matrix A.\n");
        return 1;
    }

    printf("\nEnter Matrix A:\n");
    accept(a, r1, c1);

    printf("\nEnter rows and columns of Matrix B (1-10): ");
    if (scanf("%d%d", &r2, &c2) != 2 || r2 < 1 || r2 > 10 || c2 < 1 || c2 > 10)
    {
        printf("Error: Invalid size for Matrix B.\n");
        return 1;
    }

    printf("\nEnter Matrix B:\n");
    accept(b, r2, c2);

    while (1)
    {
        printf("\n1. Addition");
        printf("\n2. Subtraction");
        printf("\n3. Multiplication");
        printf("\n4. Transpose of Matrix A");
        printf("\n5. Display Matrices");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");

        if (scanf("%d", &ch) != 1)
        {
            printf("Invalid input!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (ch)
        {
        case 1:
            if (r1 != r2 || c1 != c2)
            {
                printf("\nError: Addition cannot be performed.");
                printf("\nReason: Matrix dimensions are different.");
                printf("\nMatrix A = %d x %d", r1, c1);
                printf("\nMatrix B = %d x %d\n", r2, c2);
            }
            else
            {
                addition(a, b, r1, c1);
            }
            break;

        case 2:
            if (r1 != r2 || c1 != c2)
            {
                printf("\nError: Subtraction cannot be performed.");
                printf("\nReason: Matrix dimensions are different.");
                printf("\nMatrix A = %d x %d", r1, c1);
                printf("\nMatrix B = %d x %d\n", r2, c2);
            }
            else
            {
                subtraction(a, b, r1, c1);
            }
            break;

        case 3:
            if (c1 != r2)
            {
                printf("\nError: Multiplication cannot be performed.");
                printf("\nReason: Columns of Matrix A must equal rows of Matrix B.");
                printf("\nMatrix A = %d x %d", r1, c1);
                printf("\nMatrix B = %d x %d\n", r2, c2);
            }
            else
            {
                multiplication(a, b, r1, c1, c2);
            }
            break;

        case 4:
            transpose(a, r1, c1);
            break;

        case 5:
            printf("\nMatrix A:");
            display(a, r1, c1);

            printf("\nMatrix B:");
            display(b, r2, c2);
            break;

        case 6:
            printf("\nProgram terminated successfully.\n");
            return 0;

        default:
            printf("\nError: Invalid choice! Please enter a number between 1 and 6.\n");
        }
    }

    return 0;
}
