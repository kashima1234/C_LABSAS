#include "set_operation.h"

int find_avar_min_max(FILE *const f, double *const avar, const int at_begin, const int at_end)
{
    fseek(f, 0, SEEK_SET);

    int cu_index = 0;
    int count_number = 0;
    double number;
    double sum = 0;

    while (fscanf(f, "%lf", &number) == 1)
    {
        if (cu_index > at_begin && cu_index < at_end)
        {
            sum += number;
            count_number++;
        }
        cu_index++;
    }
    if (count_number == 0)
        return ERROR_NO_AVARG;

    *avar = sum / count_number;

    return EXIT_SUCCESS;
}

int find_min_max_f_file(FILE *const f, int *const i_max, int *const i_min)
{
    double max;
    
    if (fscanf(f, "%lf", &max) != 1)
        return ERROR_FIRST_ELENO_NUM;
    double min = max;

    int cur_index = 0;
    double number;
    while (fscanf(f, "%lf", &number) == 1)
    {
        cur_index++;
        if (number > max)
        {
            max = number;
            *i_max = cur_index;
        }
        if (number < min)
        {
            min = number;
            *i_min = cur_index;
        }
    }
    return EXIT_SUCCESS;
}
void define_begin_end(int *const i_1_d, int *const i_2_d)
{
    if (*i_1_d > *i_2_d)
    {
        int tmp = *i_1_d;
        *i_1_d = *i_2_d;
        *i_2_d = tmp;
    } 
}
