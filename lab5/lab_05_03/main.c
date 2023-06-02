#include "set_print_written_number.h"
#include "set_put_number.h"
#include "set_sort.h"
#include "set_define.h"
#include "set_check.h"

int main(int argc, char const *argv[])
{
    int mark = check_argc(argc, argv);
    int rc;
    switch (mark)
    {
        case 1:
            rc = write_random_to_file(argv);
            break;
        case 2:
            rc = print_num(argv[2]);
            break;
        case 3:
            rc = sort(argv[2]);
            break;
        default:
            return ERROR_NO_VALID_PARA;
    }
    if (rc != 0)
        return rc;
     
    return EXIT_SUCCESS;
}
