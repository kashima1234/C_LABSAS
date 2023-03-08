#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
    double a, b;
    double phi;
    double s;
    

    scanf("%lf%lf", &a, &b);
    scanf("%lf", &phi);
    phi = phi * 2 * asin(1.0) / 180.0;
    s = ((a * b) / 2) * sin(phi);
    printf("S = %.6lf", s);
    return EXIT_SUCCESS;
}
