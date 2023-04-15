#include <stdio.h>
#include <stdlib.h>

#define ERROR_INCORRECT_INPUT_PARAM 1
#define ERROR_INCORRECT_INPUT_MATRIX 2
#define NUMBER_OF_ARGUMENTS 1
#define SUCCESS 0
#define N 10
#define M 10
#define NO_ODD_SUM 3
#define NO_STRING_MATRIX 3


int input_matrix_param(size_t *x)
{
    int rc = scanf("%zu", x);
    if ((rc != NUMBER_OF_ARGUMENTS) || (*x <= 0) || (*x > 10))
    {
        printf("Error: incorrect input\n");
        return ERROR_INCORRECT_INPUT_PARAM;
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
            if (scanf("%d", &matrix[i][j]) != NUMBER_OF_ARGUMENTS)
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

    error = input_matrix(matrix, *n, *m);
    if (error != EXIT_SUCCESS)
        return error;

    return error;
}

void print_matrix(int matrix[][M], size_t n, size_t m)
{
    printf("Print matrix:\n");
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}

int if_sum_digit_od(int number)
{
    if (number < 0)
        number *= -1;

    int sum = 0;
    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }

    if (sum % 2 != 0)
        return NO_ODD_SUM;

    return SUCCESS;
}

int is_string_matrix(int array[], size_t n)
{
    int count = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (if_sum_digit_od(array[i]) != SUCCESS)
            count++;
    }
    if (count >= 2)
        return NO_STRING_MATRIX;
    
    return SUCCESS; 
}

void set_string(int matrix[][M], size_t *n, size_t m, size_t l)
{
    for (size_t i = *n; i > l; i--)
        for (size_t j = 0; j < m; j++)
            matrix[i][j] = matrix[i - 1][j];
    (*n)++;

    for (size_t j = 0; j < m; j++)
        matrix[l][j] = -1;
}

void insert_if_successful(int matrix[][M], size_t *n, size_t m)
{
    for (size_t i = 0; i < *n; i++)
        if (is_string_matrix(matrix[i], m))
        {
            set_string(matrix, n, m, i);
            i++;
        }
}


// void insert_row_if_successful(int matrix[][M], size_t *n, size_t m)
// {
//     for (size_t i = 0; i < *n; i++)
//     {
//         int rc = is_string_matrix(matrix[i], m);
//         if (rc == SUCCESS)
//         {
//             size_t end = *n;
//             while (end > i)
//             {
//                 set_row(matrix[end], matrix[end - 1], m);
//                 end--;
//             }
//             set_row(matrix[i], m);
//             (*n)++;
//             i++;            
//         }
//     }
// }


int main()
{
    int matrix[N][M];
    size_t n;
    size_t m;

    int error = input(matrix, &n, &m);
    if (error != EXIT_SUCCESS)
        return error;

    insert_if_successful(matrix, &n, m);
    print_matrix(matrix, n, m);
}