#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void result(double xq, double yq, double xr, double yr, double xp, double yp, int first_return, int second_return, int thirth_return)
{
    double first_point, second_point, x, y, resul;

    first_point = xr - xq;
    second_point = yr - yq;
    x = xp - xq;
    y = yp - yq;
    resul = first_point * y - x * second_point;
    if (resul > 0)
    {
        printf("%d", first_return);
    }
    else if (resul < 0)
    {
        printf("%d", thirth_return);
    }
    else
    {
        printf("%d", second_return);
    }
}

int main(void)
{
    double xq, yq, xr, yr;
    double xp, yp;
    int first_return, second_return, thirth_return;
    int error = EXIT_SUCCESS;

    printf("Enter the cordinates of the first point on the line:\n");
    if (!(scanf("%lf", &xq)) || !(scanf("%lf", &yq)) || (xq > 4294967295) || (yq > 4294967295))
    {
        printf("Error!You entered not number or you entered too big number.\n");
        error = EXIT_FAILURE;
    }
    if (error == EXIT_SUCCESS && fabs(xq - yq) < 1e-8)
    {
        printf("Error!\n");
        error = EXIT_FAILURE;
    }
    printf("Enter the coordinates of the second point on the line:\n");
    if (error == EXIT_SUCCESS && !(scanf("%lf", &xr)) || !(scanf("%lf", &yr)) || (xr > 4294967295) || (yr > 4294967295))
    {
        printf("Error!You entered not number or you entered too big number.\n");
        error = EXIT_FAILURE;
    }
    if (error == EXIT_SUCCESS && fabs(xr - yr) < 1e-8)
    {
        printf("Error!\n");
        error = EXIT_FAILURE;
    }
    printf("Enter the coordinates of an arbitrary point:\n");
    if (!(scanf("%lf", &xp)) || !(scanf("%lf", &yp)) || (xp > 4294967295) || (yp > 4294967295))
    {
        printf("Error!You entered not number or you entered too big number.\n");
        error = EXIT_FAILURE;
    }
    if (error == EXIT_SUCCESS && fabs(xp - yp) < 1e-8)
    {
        printf("Error!\n");
        error = EXIT_FAILURE;
    }
    if (error == EXIT_SUCCESS)
    {
        first_return = 0;
        second_return = 1;
        thirth_return = 2;
        result(xq, yq, xr, yr, xp, yp, first_return, second_return, thirth_return);
    }
    return EXIT_SUCCESS;
}
