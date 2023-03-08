#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double estimate(double x, double eps)
{
    long long i = 1;
    double t = x;
    double res = t;
    while (fabs(t) > eps)
    {
        i += 2;
        t *= (2 - i) * x * x / i;
        res += t;
    }
    return res;
}

int main(void)
{
    double sum_s, f_x, eps, abs_err, rel_err;
    double x;
    int r;
    int error = EXIT_SUCCESS;

    printf("Enter value for x and eps\n");
    r = scanf("%lf%lf", &x, &eps);
    if (r == 2)
    {
        if (fabs(x) < 0 || fabs(x) > 1)
        {
            printf("Error!");
            error = EXIT_FAILURE;
        }
        else if (eps >= 1 || eps <= 0)
        {
            printf("Epsilon error");
            error = EXIT_FAILURE;
        }
        else if (fabs(x) > 1)
        {
            printf("vlaue error");
            error = EXIT_FAILURE;
        }
        else
        {
            sum_s = estimate(x, eps);
            f_x = atan(x);
            abs_err = fabs(f_x - sum_s);
            rel_err = fabs((f_x - sum_s) / f_x);
            printf("%lf %lf %lf %lf", sum_s, f_x, abs_err, rel_err);
        }
    }
    else
        printf("Input error");
        return error;

}
