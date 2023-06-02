#include "set_operation.h"
#include "set_check.h"

int main(int argc, char const *argv[])
{
    FILE *f;
    double avar;
    int begin_id = 0, end_id = 0;
    int rc;

    if ((rc = check_arg(argc)) != 0)
        return rc;

    f = fopen(argv[1], "r");
    if (f != NULL)
    {
        find_min_max_f_file(f, &begin_id, &end_id);
        define_begin_end(&begin_id, &end_id);
        rc = find_avar_min_max(f, &avar, begin_id, end_id);
        fclose(f);
        
        if (rc != 0)
            return rc;
    }
    else
        return ERROR_OPEN_FILE;

    printf("%lf\n", avar);

    return EXIT_SUCCESS;
}
