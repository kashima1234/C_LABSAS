#include "set_check.h"

int check_arg(const int arg)
{
    int rc;
    switch (arg)
    {
        case 2 : rc = 0;
            break;
        default : rc = ERROR_NO_VALID_PARA;
            break;
    }
    return rc;
}

