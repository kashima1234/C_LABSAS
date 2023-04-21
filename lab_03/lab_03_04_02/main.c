#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include <stdbool.h>

#define INCORRECT_INPT_PARAM 1
#define NUMBER_OF_ARG 1
#define INCORRCT_INUT_MAT 2
#define ERR_NO_MAX_ELEM 3
#define INCORRECT_SQUARE 4

#define N 10
#define M 10
int set_param(size_t *x)
{
    int rc = scanf("%zu", x);
    if ((rc != NUMBER_OF_ARG) || (*x <= 0) || (*x > 10))
    {
        printf("Error: inocrret input\n");
        return INCORRECT_INPT_PARAM;
    }
    return EXIT_SUCCESS;
}

int set_input_matrix(int matrix[][M], size_t *n, size_t *m)
{
    printf("Enter elements:\n");
    for (size_t i = 0; i < *n; i++)
    {
        for (size_t j = 0; j < *m; j++)
        {
            if (scanf("%d", &matrix[i][j]) != NUMBER_OF_ARG)
            {
                printf("Error: incorect input matrix\n");
                return INCORRCT_INUT_MAT;
            }
        }
    }
    return EXIT_SUCCESS;
}

int set_input(int matrix[][M], size_t *n, size_t *m)
{
    printf("Enter n: ");
    int error = set_param(n);
    if (error != EXIT_SUCCESS)
        return error;
    printf("Enter m: ");
    error = set_param(m);
    if (error != EXIT_SUCCESS)
        return error;
    if (*n != *m)
    {
        printf("Error: not square matrix\n");
        return INCORRECT_SQUARE;
    }
    error = set_input_matrix(matrix, n, m);
    if (error != EXIT_SUCCESS)
        return error;

    return EXIT_SUCCESS;
}

int find_max_elem(int matrix[][M], size_t n, size_t m)
{
    int max_elem = INT_MIN;
    // int max_ele_ect = false;
    int flag = 0;

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = n - i; j < m; j++)
        {
            // size_t j = k - 1;
            if (abs(matrix[i][j]) % 10 == 5 && max_elem < matrix[i][j])
            {
                max_elem = matrix[i][j];
                flag = 1;
            }
        }
    }
    if (flag == 0)
        return ERR_NO_MAX_ELEM;
        
    printf("%d", max_elem);

    return EXIT_SUCCESS;
}


    // printf("%d \n", max_elem);

    // return EXIT_SUCCESS;

    // if (max_ele_ect)
    // {
    //     printf("Maximum element found: %d\n", max_elem);
    // }
    // else
    // {
    //     printf("No valid maximum element found.\n");
    // }

int main(void)
{
    int matrix[N][M];
    size_t n;
    size_t m;

    int error = set_input(matrix, &n, &m);
    if (error != EXIT_SUCCESS)
        return error;
    error = find_max_elem(matrix, n, m);
    if (error == ERR_NO_MAX_ELEM)
        return error;
        
    return EXIT_SUCCESS;
}