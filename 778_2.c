#include<stdio.h>
#include<stdlib.h>

void accept(int A[20][20], int r, int c)
{
    int i, j;
    printf("Enter elements of matrix:\n");

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
}

void display(int A[20][20], int r, int c)
{
    int i, j;

    printf("\nThe Sparse Matrix is:\n");

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            printf("%5d", A[i][j]);
        }
        printf("\n");
    }
}

void compact(int A[20][20], int B[100][3], int r, int c)
{
    int i, j, k = 1;

    B[0][0] = r;
    B[0][1] = c;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            if(A[i][j] != 0)
            {
                B[k][0] = i;
                B[k][1] = j;
                B[k][2] = A[i][j];
                k++;
            }
        }
    }

    B[0][2] = k - 1;
}

void comdisplay(int B[100][3])
{
    int i;

    printf("\nCompact Form:\n");
    printf("Row\tColumn\tValue\n");

    for(i = 0; i <= B[0][2]; i++)
    {
        printf("%d\t%d\t%d\n", B[i][0], B[i][1], B[i][2]);
    }
}

void transpose(int B[100][3], int T[100][3])
{
    int m, n, t;
    int col, p, q;

    m = B[0][0];
    n = B[0][1];
    t = B[0][2];

    T[0][0] = n;
    T[0][1] = m;
    T[0][2] = t;

    q = 1;

    for(col = 0; col < n; col++)
    {
        for(p = 1; p <= t; p++)
        {
            if(B[p][1] == col)
            {
                T[q][0] = B[p][1];
                T[q][1] = B[p][0];
                T[q][2] = B[p][2];
                q++;
            }
        }
    }
}

void transdisplay(int T[100][3])
{
    int i;

    printf("\nSimple Transpose Form:\n");
    printf("Row\tColumn\tValue\n");

    for(i = 0; i <= T[0][2]; i++)
    {
        printf("%d\t%d\t%d\n", T[i][0], T[i][1], T[i][2]);
    }
}

void fasttranspose(int B[100][3], int FT[100][3])
{
    int S[20], T[20];
    int m, n, t;
    int i, j;

    m = B[0][0];
    n = B[0][1];
    t = B[0][2];

    FT[0][0] = n;
    FT[0][1] = m;
    FT[0][2] = t;

    if(t <= 0)
        return;

    for(i = 0; i < n; i++)
        S[i] = 0;

    for(i = 1; i <= t; i++)
        S[B[i][1]]++;

    T[0] = 1;

    for(i = 1; i < n; i++)
        T[i] = T[i-1] + S[i-1];

    for(i = 1; i <= t; i++)
    {
        j = B[i][1];

        FT[T[j]][0] = B[i][1];
        FT[T[j]][1] = B[i][0];
        FT[T[j]][2] = B[i][2];

        T[j]++;
    }
}

void fastdisplay(int FT[100][3])
{
    int i;

    printf("\nFast Transpose Form:\n");
    printf("Row\tColumn\tValue\n");

    for(i = 0; i <= FT[0][2]; i++)
    {
        printf("%d\t%d\t%d\n", FT[i][0], FT[i][1], FT[i][2]);
    }
}

int main()
{
    int A[20][20], B[100][3], T[100][3], FT[100][3];
    int r, c, choice;

    printf("Enter number of rows and columns: ");
    scanf("%d%d", &r, &c);

    accept(A, r, c);
    display(A, r, c);

    compact(A, B, r, c);
    comdisplay(B);

    printf("\nChoose Transpose Method:");
    printf("\n1. Simple Transpose");
    printf("\n2. Fast Transpose");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            transpose(B, T);
            transdisplay(T);
            break;

        case 2:
            fasttranspose(B, FT);
            fastdisplay(FT);
            break;

        default:
            printf("\nInvalid Choice!");
    }

    return 0;
}

