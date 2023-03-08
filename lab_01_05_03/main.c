#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int nod(int a, int b);	
int main()
{
    int a, b;
    int result;
    int error = EXIT_SUCCESS;
    printf("Enter first natural number:\n");
    if (!(scanf("%d", &a)) || (a <= 0))
    {
        printf("Error!You enterd not natural number.\n");
        error = EXIT_FAILURE;
    }
    if (error == EXIT_SUCCESS)
    {
        printf("Enter second natural number:\n");
        if (!(scanf("%d", &b)) || (b <= 0))
        {
            printf("Error!You entered not natural number.\n");
            error = EXIT_FAILURE;
        }
    }
    if (error == EXIT_SUCCESS)
    {   
        result = nod(a, b);
        printf("The greatest common factor = %d\n", result);
    }
    return EXIT_SUCCESS;
}

int nod(int a, int b)
{
    int i = a;
    int flag = false;
    while (i > 0 && !flag)
    {
        if (a % i == 0 && b % i == 0)
        {
            flag = true;
        }
        else
        {
            i--;
        }
    }
    return i;
}


