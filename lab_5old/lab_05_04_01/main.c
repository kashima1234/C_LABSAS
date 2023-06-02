#include "my_function.h"

#define ARG_ERROR  53

int main(int argc, char **argv)
{
    if (argc < 3 || argc > 5 || argv == NULL)
        return ARG_ERROR;
        
    FILE *file_in;
    st arr[SIZE_ARR];
    int n = 0, rc = EXIT_SUCCESS;
    
    if (strcmp(argv[1], "st") == 0)
    {
        if (argc != 3)
            return ARG_ERROR;

        file_in = fopen(argv[2], "r");
        if (file_in == NULL)
        {
            fclose(file_in);
            return ERROR;
        }
        rc = read_students(file_in, arr, &n);
        if (rc == EXIT_SUCCESS)
        {
            sort_students(arr, n);
            printf_st(stdout, arr, n);
        }
        fclose(file_in);
    }
    else if (strcmp(argv[1], "ft") == 0)
    {
        if (argc != 5)
            return ARG_ERROR;

        file_in = fopen(argv[2], "r");
        if (file_in == NULL)
        {
            fclose(file_in);
            return ERROR;
        }
        rc = read_students(file_in, arr, &n);
        if (rc == EXIT_SUCCESS)
        {
            FILE *file_out;
            file_out = fopen(argv[3], "w");
            if (surname_fstr(file_out, arr, n, argv[4]) == 0)
                rc = ERROR;
            fclose(file_out);
        }
        fclose(file_in);
    }
    else if (strcmp(argv[1], "dt") == 0)
    {
        if (argc != 3)
            return ARG_ERROR;
        file_in = fopen(argv[2], "r");
        if (file_in == NULL)
        {
            fclose(file_in);
            return ERROR;
        }
        rc = read_students(file_in, arr, &n);
        fclose(file_in);
        if (rc == EXIT_SUCCESS)
        {
            float mas_avr[SIZE_ARR];
            float avr;
            avr = average_calc(arr, n, mas_avr);
            del_student(arr, mas_avr, &n, avr);
            if (n < 1)
                rc = ERROR;
            else
            {
                file_in = fopen(argv[2], "w");
                printf_st(file_in, arr, n);
                fclose(file_in);
            }
        }
    }
    else
        return ARG_ERROR;
        
    return rc;
}
