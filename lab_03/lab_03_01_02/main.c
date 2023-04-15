#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR_INCORRECT_INPUT_PARAM 1
#define ERROR_INCORRECT_INPUT_MATRIX 2
#define NUMBER_OF_ARGUMENT 1
#define N 10
#define M 10
#define SUCCESS 0
int input_matrix_param(size_t *x)
{
    int rc = scanf("%zu", x);
    if ((rc != NUMBER_OF_ARGUMENT) || (*x <= 0) || (*x > 10))
    {
        printf("Error: incorrect input\n");
        return ERROR_INCORRECT_INPUT_PARAM;
    }

    return EXIT_SUCCESS;
}

int input_matrix(int matrix[][M], size_t *n, size_t *m)
{
    printf("Enter elements:\n");
    for (size_t i = 0; i < *n; i++)
    {
        for (size_t j = 0; j < *m; j++)
        {
            if (scanf("%d", &matrix[i][j]) != NUMBER_OF_ARGUMENT)
            {
                printf("Error: incorrect input matrix\n");
                return ERROR_INCORRECT_INPUT_MATRIX;
            }
        }
    }

    return EXIT_SUCCESS;
}

int input(int matrix[][M], size_t *n, size_t *m)
{
    printf("Enter n: ");
    int error = input_matrix_param(n);
    if (error != EXIT_SUCCESS)
        return error;

    printf("Enter m: ");
    error = input_matrix_param(m);
    if (error != EXIT_SUCCESS)
        return error;

    error = input_matrix(matrix, n, m);
    if (error != EXIT_SUCCESS)
        return error;

    return EXIT_SUCCESS;
}


// void find_alternating_columns(int matrix[][M], size_t n, size_t m, int array[])
// {
//     for (size_t j = 0; j < m; j++)
//     {
//         if (n == 1)
//         {
//             array[j] = 0;
//             continue;
//         }

//         int count_positive = 0; 
//         int count_negative = 0;
//         for (size_t i = 0; i < n - 1; i++)
//         {
//             if (matrix[i][j] > 0)
//             {
//                 count_positive++;
//             }
//             else if (matrix[i][j] < 0)
//             {
//                 count_negative++;
//             }
//         }

//         if (count_positive > 0 && count_negative > 0)
//         {
//             array[j] = 1;
//         }
//         else
//         {
//             array[j] = 0;
//         }    
//     }
// }

int find_alternating_columns(int matrix[][M], size_t n, size_t m, int *array)
{
    for (size_t j = 0; j < m; j++)
    {
        int flag = 0;
        for (size_t i = 0; i < n - 1; i++)
            if (matrix[i][j] * matrix[i + 1][j] >= 0)
            {
                flag = 0;
                break;
            }
            else
                flag = 1;
        if (flag)
            array[j] = 1;
        else
            array[j] = 0;
    }
    return EXIT_SUCCESS;
}

void print_array(int array[], size_t n)
{
    printf("Print array:\n");
    for (size_t i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}


int main()
{
    int matrix[N][M];
    size_t n;
    size_t m;

    int error = input(matrix, &n, &m);
    if (error != EXIT_SUCCESS)
        return error;

    int array[M];

    find_alternating_columns(matrix, n, m, array);

    print_array(array, m);
    
    return SUCCESS;
}