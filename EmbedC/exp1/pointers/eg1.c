#include <stdio.h>
#include <stdlib.h>

/* Function prototype for matrix addition using dynamic allocation */
void addMatrices(int **a, int **b, int **result, int rows, int cols);

int main(void)
{
    int i, j;
    int rows, cols;

    /* Function pointer to a function that takes
       (int **, int **, int **, int, int) and returns void */
    void (*fpAdd)(int **, int **, int **, int, int);

    /* Assign the function's address to the function pointer */
    fpAdd = addMatrices;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    /* Allocate memory for matrices A, B, and C */
    int **A = (int **)malloc(rows * sizeof(int *));
    int **B = (int **)malloc(rows * sizeof(int *));
    int **C = (int **)malloc(rows * sizeof(int *));
    if (A == NULL || B == NULL || C == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < rows; i++)
    {
        A[i] = (int *)malloc(cols * sizeof(int));
        B[i] = (int *)malloc(cols * sizeof(int));
        C[i] = (int *)malloc(cols * sizeof(int));
        if (A[i] == NULL || B[i] == NULL || C[i] == NULL)
        {
            printf("Memory allocation failed.\n");
            return 1;
        }
    }

    /* Input matrices */
    printf("\nEnter elements of matrix A (%d x %d):\n", rows, cols);
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nEnter elements of matrix B (%d x %d):\n", rows, cols);
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("B[%d][%d] = ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    /* Call the addMatrices function using the function pointer */
    fpAdd(A, B, C, rows, cols);

    printf("\nResultant matrix C = A + B:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%4d ", C[i][j]);
        }
        printf("\n");
    }

    /* Free allocated memory */
    for (i = 0; i < rows; i++)
    {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}

/* Definition of matrix addition function for dynamically allocated matrices */
void addMatrices(int **a, int **b, int **result, int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}