#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define INCORRECT_INPT_PAPAM 1
#define INCORRECT_INPT_MAT 2
#define NUM_OF_ARG 1
#define N 10
#define M 10

int input_matrix_param(size_t *x)
{
    int rc = scanf("%zu", x);
    if ((rc != INCORRECT_INPT_PAPAM) || (*x <= 0) ||(*x > 10))
    {
        printf("Error: incorrect input\n");
        return INCORRECT_INPT_PAPAM;
    }
    return EXIT_SUCCESS;
}

int input_matrix(int matrix[][M], size_t n, size_t m)
{
    printf("Enter elements:\n");
    for (size_t i = 0; i < n; i++)
    {
      for (size_t j = 0; j < m; j++)
        {
            if (scanf("%d", &matrix[i][j]) != NUM_OF_ARG)
            {
                printf("Error: incorrect input matrix\n");
                return INCORRECT_INPT_MAT;
            }
        }
    }
    return EXIT_SUCCESS;
}


int set_input(int matrix[][M], size_t *n, size_t *m)
{
    printf("Enter n: ");
    int error = input_matrix_param(n);
    if (error != EXIT_SUCCESS)
        return error;

    printf("Enter m: ");
    error = input_matrix_param(m);
    if (error != EXIT_SUCCESS)
        return  error;

    error = input_matrix(matrix, *n, *m);
    if (error != EXIT_SUCCESS)
        return error;

    return EXIT_SUCCESS;
}

int set_product(int array[], size_t n)
{
    int product = 1;
    for (size_t i = 0; i < n; i++)
        product *= array[i];

    return product;
}

void set_swap(int matrix[][M], size_t a, size_t b, size_t c)
{
    for (size_t i = 0; i < a; i++)
    {
        int temp = matrix[b][i];
        matrix[b][i] = matrix[c][i];
        matrix[c][i] = temp;
    }
}


int set_sort(int matrix[][M], size_t a, size_t b)
{
    for (size_t i = 0; i < a - 1; i++)
    {
        size_t min = i;
        for (size_t j = i + 1; j < a; j++)
        {
            if (set_product(matrix[j], b) < set_product(matrix[min], b))
                min = j;
        }
        if (min != i)
            set_swap(matrix, b, i, min);
    }
    return EXIT_SUCCESS;

}

void set_printable(int matrix[][M], size_t n, size_t m)
{
    printf("input matrix:\n");
    for (size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < m; j++)
            printf("%d " , matrix[i][j]);
        printf("\n");
    }
    printf("\n");
   
}


int main()
{
    int matrix[N][M];
    size_t n;
    size_t m;

    int error = set_input(matrix, &n, &m);
    if (error != EXIT_SUCCESS)
        return error;

    set_sort(matrix, n, m);
    set_printable(matrix, n, m);

}