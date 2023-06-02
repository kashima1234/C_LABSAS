#include "set_define.h"
#include "set_put_number.h"

int put_by_pos(FILE *f, int pos, const int *const number)
{
    if (pos % SIZE_INT != 0)
    {
        printf("Error: no write by this position!\n");
        return ERROR_NO_WRITE_POS;
    }

    fseek(f, pos, SEEK_SET);
    if (fwrite(number, SIZE_INT, 1, f) != 1)
        return END_OF_FILE;

    return EXIT_SUCCESS;
}


int pull_by_pos(FILE *f, int pos, int *const number)
{
    if (pos % SIZE_INT != 0)
    {
        printf("Error: no read by this position!\n");
        return ERROR_NO_READ_POS;    
    }
    fseek(f, pos, SEEK_SET);
    if (fread(number, SIZE_INT, 1, f) != 1)
        return END_OF_FILE;

    return EXIT_SUCCESS;
}

int pull_lastpos_number(FILE *f, int *const pos_number)
{
    fseek(f, 0, SEEK_SET);
    int pos = 0;
    int number = 0;
    while (pull_by_pos(f, pos, &number) == 0)
    {
        *pos_number = pos;
        pos += SIZE_INT;
    }
    return EXIT_SUCCESS;
}