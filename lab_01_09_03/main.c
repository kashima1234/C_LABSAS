#include <stdio.h>
#include<stdlib.h>
#include <math.h>

int readnums(double *res)
{
    double x;
    int i, rc = EXIT_SUCCESS;

    *res = 1.0;
    i = 1;
    printf("Enter value for x:\n");

    while (rc == EXIT_SUCCESS)
    {
        if (scanf("%lf", &x) == 1)
        {
            if (x >= 0.0)
            {
                *res = *res * (x + i);
                i++;
                printf("Enter next value x:\n");
            }
            else
            {
                if (i == 1)
                {
                    printf("Error!");
                    rc = EXIT_FAILURE;
                }
            }
        }
        else
        {
            printf("Error!");
            rc = EXIT_FAILURE;
        }
    }
    return rc;
}

int main()
{
    double res;
    int rc = EXIT_FAILURE;

    if (readnums(&res) == EXIT_SUCCESS)
    {
        res = exp(1 / res);
        printf("Result: %lf\n", res);
        rc = EXIT_SUCCESS;
    }

    return rc;
}
