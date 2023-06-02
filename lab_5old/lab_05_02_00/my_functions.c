#include "my_functions.h"

#include <stdlib.h>
#include <math.h>

int find_averge(FILE *input_file, double *avg)
{
    int count;
    double temp;
    *avg = count = 0;
    while (fscanf(input_file, "%lf", &temp) == 1)
    {
        *avg += temp;
        count++;
    }
    if (feof(input_file) && count)
    {
        *avg /= count;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

double near_to_avg(FILE *input_file, double avg)
{
    double min = avg, res, temp, near_to;
    while (fscanf(input_file, "%lf", &temp) == 1)
    {
        res = fabs(avg - temp);
        if (res < min)
        {
            min = res;
            near_to = temp;
        }
    }
    return near_to;
}
