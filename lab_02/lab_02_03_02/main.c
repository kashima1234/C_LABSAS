#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>
#include <stdbool.h>


#define ERROR_INPUT_AR 2
#define ERROR_INPT_M 1
#define ERROR_ELEM 3
#define N 10

int inpt_arr(int ar[N], size_t *m)
{
    printf("Enter elements: ");
    for (size_t i = 0; i < *m; i++)
    {
        if (scanf("%d", &ar[i]) != 1)
        {
            printf("Error: incorrect input array\n");
            return ERROR_INPUT_AR;   
        }
    }

    return EXIT_SUCCESS;
}


void outp_array(int ar[N], int m)
{
    printf("Result: ");
    for (size_t i = 0; i < m; i++)
        printf("%d ", ar[i]);
    printf("\n");    
}

int is_perfect_qr(int num)
{
    int square_root = sqrt(num);
    return (square_root * square_root == num);
}

void remov_squar(int arr[], size_t *m)
{
    for (size_t i = 0; i < *m; i++)
    {
        if (is_perfect_qr(arr[i]))
        {
            for (size_t j = i; j < *m; j++)
            {
                arr[j] = arr[j + 1];
            }
            (*m)--;
            i--;
        }
    }
}


int main(void)
{
    size_t m;
    printf("Enter number of elements: ");
    if (scanf("%zu", &m) != 1)
    {
        printf("Error: incorrect input n\n");
        return ERROR_INPT_M;
    }
    
    if ((m <= 0) || (m > 10))
    {
        printf("Error: incorrect number of elements");
        return ERROR_INPT_M;
    }

    int arr[N];
    int error = inpt_arr(arr, &m);

    if (error != EXIT_SUCCESS)
        return error;

    remov_squar(arr, &m);

    if (m == 0)
    {
        printf("Empty array\n");
        return ERROR_ELEM;  
    }

    outp_array(arr, m);

    return EXIT_SUCCESS;
}