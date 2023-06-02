#include <time.h>
#include "my_functions.h"
#define N 50
#define N_M 1000

int create_bin_file(FILE *file)
{
    if (file == NULL)
        return ERROR;
    
    srand(time(NULL));
    int n = rand() % N + 1;
    int r, i = 0;
    for (i = 0; i < n; i++)
    {
        r = rand() % N_M;
        fwrite(&r, 1, sizeof(int), file);
    }
    return EXIT_SUCCESS;
}

int sizef(FILE *file, size_t *size)
{
    if (file == NULL || size == NULL)
        return ERROR;
    
    long sz;
    if (fseek(file, 0L, SEEK_END))
        return ERROR;
    sz = ftell(file);
    if (sz <= 0)
        return ERROR;
    if (fseek(file, 0L, SEEK_SET))
        return ERROR;
    if (sz % sizeof(int) != 0)
        return ERROR;
    *size = sz / sizeof(int);
    return EXIT_SUCCESS;
}

int print_bin_file(FILE *file)
{
    if (file == NULL)
        return ERROR;

    int num, rc = EXIT_SUCCESS, read;
    size_t k = 0;
    if (fseek(file, 0L, SEEK_SET) == 0)
    {
        rc = sizef(file, &k);
        if (rc == EXIT_SUCCESS)
            for (size_t i = 0; !rc && i < k; i++)
            {
                read = fread(&num, sizeof(num), 1, file);
                if (read == 1)
                    printf("%d ", num);
                else
                    rc = 1;
            }
    }
    return rc;
}

int get_number_by_pos(FILE *file, int position, int *num)
{
    if (file == NULL)
        return ERROR;
    int rc = EXIT_SUCCESS;
    if (fseek(file, position * sizeof(int), SEEK_SET) == 0)
    {
        if (fread(num, sizeof(int), 1, file) != 1)
            rc = ERROR;
    }
    return rc;
}

int put_number_by_pos(FILE *file, int position, int num)
{
    if (file == NULL)
        return ERROR;
    int rc = EXIT_SUCCESS;
    if (fseek(file, position * sizeof(int), SEEK_SET) == 0)
    {
        if (fwrite(&num, sizeof(int), 1, file) != 1)
            rc = ERROR;
    }
    return rc;
}

int sort_bin_file(FILE *file)
{
    if (file == NULL)
        return ERROR;
    
    size_t k = 0;
    int first_num, second_num, rc = EXIT_SUCCESS;
    rc = sizef(file, &k);
    if (rc == EXIT_SUCCESS)
    {
        for (size_t i = 0; i < k - 1; i++)
            for (size_t j = i + 1; j < k; j++)
            {
                if (get_number_by_pos(file, i, &first_num) != EXIT_SUCCESS)
                    return ERROR;
                if (get_number_by_pos(file, j, &second_num) != EXIT_SUCCESS)
                    return ERROR;
                if (first_num > second_num)
                {
                    if (put_number_by_pos(file, i, second_num) != EXIT_SUCCESS)
                        return ERROR;
                    if (put_number_by_pos(file, j, first_num) != EXIT_SUCCESS)
                        return ERROR;
                }
            }
    }
    return rc;
}
