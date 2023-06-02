#include "set_print_written_number.h"

int print_num(char const *argv)
{
    FILE *f = fopen(argv, "rb");
    int check = 0;
    if (f != NULL)
    {
        int num;
        int pos = 0;
        int rc = 0;
        while (pull_by_pos(f, pos, &num) == 0)
        {
            rc += printf("%d ", num);
            pos += SIZE_INT;
        }
        if (rc == 0)
            check = ERROR_NO_NUMBER_INFIELE;
        fclose(f);
    }
    else
        check = ERROR_OPEN_FILE;

    return check;
}
int write_random_to_file(char const *argv[])
{

    FILE *f = fopen(argv[3], "wb");
    int check = 0;
    if (f != NULL)
    {
        int numbers;
        if ((numbers = atoi(argv[2])) != 0)
        {
            srand(time(NULL));
            for (int i = 0; i < numbers; i++)
            {
                int elem = rand() % 1000; // числа меньше 1000
                fwrite(&elem, SIZE_INT, 1, f);
            }
        }
        else
            check = ERROR_NO_NUM;
        fclose(f);
    }
    else 
        check = ERROR_OPEN_FILE;

    return check;
}