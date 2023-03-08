#include<stdio.h>
#include<stdlib.h>

int main()
{
    double v;
    double a;
    double t;
    double s;

    printf("Ente value for initial speed:\n");
    scanf("%lf", &v);
    printf("Enter value for acceleration:\n");
    scanf("%lf", &a);
    printf("Enter value for time:\n");
    scanf("%lf", &t);
    s = v * t + (a * (t * t)) / 2;
    printf("S = %.6lf", s);
    return EXIT_SUCCESS;
}
