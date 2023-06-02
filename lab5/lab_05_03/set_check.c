#include "set_check.h"



int check_argc(int argc, char const *argv[])
{
    if (argc == 4 && strcmp(argv[1], "c") == 0)
        return 1;
    else if (argc == 3 && strcmp(argv[1], "p") == 0)
        return 2;
    else if (argc == 3 && strcmp(argv[1], "s") == 0)
        return 3;
    else
        return ERROR_NO_VALID_PARA;
}