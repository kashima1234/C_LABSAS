#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>


#define ERRO_INCOR_INPT_NUMB 1
#define ERRO_INCOR_INPT_MAT 2
#define NUM_OF_ARG 1
#define ERRO_NO_PRIME 3

#define N 10
#define M 10
int set_inpt_param(size_t *a)
{
    int rc = scanf("%zu", a);
    if ((rc != NUM_OF_ARG) || (*a <= 0) || (*a > 10))
    {
        printf("Error: incorect input\n");
        return ERRO_INCOR_INPT_NUMB;
    }

    return EXIT_SUCCESS;
}

int set_inpt_matrix(int matrix[][M], size_t n, size_t m)
{
    printf("Enter elements:\n");
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
        {
            if (scanf("%d", &matrix[i][j]) != NUM_OF_ARG)
            {
                printf("Error: incorrect inpput matrix\n");
                return ERRO_INCOR_INPT_MAT;
            }
        }

    return EXIT_SUCCESS;        
}


int set_input(int matrix[][N], size_t *n, size_t *m)
{
    printf("Enter n: ");
    int error = set_inpt_param(n);
    if (error != EXIT_SUCCESS)
        return error;

    printf("Enter m: ");
    error = set_inpt_param(m);
    if (error != EXIT_SUCCESS)
        return error;

    error = set_inpt_matrix(matrix, *n, *m);
    if (error != EXIT_SUCCESS)
        return error;

    return EXIT_SUCCESS;
}


int set_if_prime(int element)
{
    if (element <= 1)
        return ERRO_NO_PRIME;
    for (int i = 2; i * i <= element; i++)
        if (element % i == 0)
            return ERRO_NO_PRIME;
    return EXIT_SUCCESS;
}


int set_collec_prim(int matrix[][M], size_t n, size_t m, int arr_prim[], size_t *size_arr)
{
    size_t count = 0;

    for (size_t i = 0; i < n * m; i++)
    {
        if (set_if_prime(matrix[i / m][i % m]) == EXIT_SUCCESS)
        {
            arr_prim[count++] = matrix[i / m][i % m];
        }
    }
    if (count == 0)
    {
        printf("Error: no prime elements\n");
        return ERRO_NO_PRIME;
    }

    *size_arr = count;
    return EXIT_SUCCESS;
}


void set_revers_arr(int array[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        int temp = array[i];
        array[i] = array[n - 1 - i];
        array[n - 1 - i] = temp;
    }
}



void set_fill_prime(int matrix[][M], size_t n, size_t m, int array_pri[], size_t siz_arr)
{
    size_t index = 0;
    for (size_t i = 0; i < n * m; i++)
    {
        if (set_if_prime(matrix[i / m][i % m]) == EXIT_SUCCESS)
        {
            matrix[i / m][i % m] = array_pri[index++];
        }
    }
}

void set_prin_arr(int array[], size_t m)
{
    for (size_t i = 0; i < m; i++)
        printf("%d ", array[i]);
}

void set_print_matrix(int matrix[][M], size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
    {
        set_prin_arr(matrix[i], m);
        printf("\n");
    }
}
int main()
{
    int matrix[N][M];
    size_t n; 
    size_t m;

    int error = set_input(matrix, &n, &m);
    if (error != EXIT_SUCCESS)
        return error;

    int array_prim[N * M];
    size_t size_arr = 0;

    error = set_collec_prim(matrix, n, m, array_prim, &size_arr);

    if (error != EXIT_SUCCESS)
        return error;

    set_revers_arr(array_prim, size_arr);

    set_fill_prime(matrix, n, m, array_prim, size_arr);
 
    set_print_matrix(matrix, n, m);

    return EXIT_SUCCESS; 
}