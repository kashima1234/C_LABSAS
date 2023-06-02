/*
Для работы с целыми числами был выбран тип int, упорядочение 
файла осуществляется по возрастанию чисел и сортировка используется пузырькова
*/
#include <string.h>
#include "my_functions.h"

int main(int argc, char **argv)
{
    if (argc != 3)
        return ERROR;
    int rc = EXIT_SUCCESS;
    if (strcmp(argv[1], "c") == 0)
    {
        FILE *file;
        file = fopen(argv[2], "wb");
        rc = create_bin_file(file);
        fclose(file);
    }
    else if (strcmp(argv[1], "p") == 0)
    {
        FILE *read_file;
        read_file = fopen(argv[2], "rb");
        if (read_file == NULL)
            return ERROR;
        rc = print_bin_file(read_file);
        fclose(read_file);
    }
    else if (strcmp(argv[1], "s") == 0)
    {
        FILE *sort_file;
        sort_file = fopen(argv[2], "r+b");
        if (sort_file == NULL)
            return ERROR;
        rc = sort_bin_file(sort_file);
    
        fclose(sort_file);
    }
    else
        rc = ERROR;
    return rc;
}