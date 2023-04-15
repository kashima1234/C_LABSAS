#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_ARGM 1
#define ERROR_INP_ARRAY 2
#define ERROR_NO_NEGTIVE 3
#define N 10
int input_ar(int *a, int n)
{
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &a[i]) != NUMBER_OF_ARGM)
        {
            printf("Error: incorrect input array\n");
            return ERROR_INP_ARRAY;
        }
    }
    return EXIT_SUCCESS;
}

int average_of_neg(int *a, int n)
{
    double averg_neg = 0;
    int cont_neg = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            averg_neg += a[i];
            cont_neg++;
        }
    }

    if (cont_neg == 0)
    {
        printf("Error : there are no negative number\n");
        return ERROR_NO_NEGTIVE;
    }

    averg_neg /= cont_neg;
    printf("%lf", averg_neg);

    return EXIT_SUCCESS;
}

int main()
{
    int a[N];
    int n;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != NUMBER_OF_ARGM)
    {
        printf("Error: incorrect input n\n");
        return ERROR_INP_ARRAY;        
    }
    if ((n <= 0) || (n > 10))
    {
        printf("Error: incorrect number of elements");
        return ERROR_INP_ARRAY;
    }

    int error = input_ar(a, n);

    if (error != EXIT_SUCCESS)
    {
        return error;
    }

    error = average_of_neg(a, n);
    
    if (error != EXIT_SUCCESS)  
        return error; 
    
    return EXIT_SUCCESS;
}