#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define MM 10
#define ERROR_INCO_INP_NUM 1
#define ERROR_INCORRECT_INP_AR 2
#define ERROR_NO_ITEMS 3
#define N 10
int input_array(int *ar, size_t n)
{
    printf("Enter elements: ");
    for (size_t i = 0; i < n; i++)
    {
        if (scanf("%d", &ar[i]) != 1)
        {
            printf("Error: incorrect input array\n");
            return ERROR_INCORRECT_INP_AR;
        }
    }
    return EXIT_SUCCESS;
}


void out_arr(int *arr, size_t n)
{
    printf("Result: ");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}



int check_number(int number)
{
    number = abs(number);
    int y;
    y = number % 10;

    while (number > MM)
    {
        number /= MM;
    }
    int fbegi;
    fbegi = number;

    return fbegi == y;
}

int if_sa_new_arr(int *arr_new, int *array, size_t numbers, size_t *new_arr_count)
{
    for (size_t i = 0; i < numbers; i++)
    {
        if (check_number(array[i]))
        {
            arr_new[*new_arr_count] = array[i];
            (*new_arr_count)++;
        }
    }
    if (*new_arr_count == 0)
        return ERROR_NO_ITEMS;
    return EXIT_SUCCESS;
}

int main()
{
    size_t number;
    printf("Enter number of elements: ");
    if (scanf("%zu", &number) != 1)
    {
        printf("Error: incorrect input n\n");
        return ERROR_INCO_INP_NUM;
    }

    if ((number <= 0) || (number > 10))
    {
        printf("Error: incorrect number of elements");
        return ERROR_INCO_INP_NUM;
    }

    int array[N];
    int error = input_array(array, number);

    if (error != EXIT_SUCCESS)
    {
        return error;
    }
    
    int arr_new[N];
    size_t new_arr_count = 0;

    error = if_sa_new_arr(arr_new, array, number, &new_arr_count);

    if (error != EXIT_SUCCESS)
        return error;

    out_arr(arr_new, new_arr_count);

    return EXIT_SUCCESS;
}