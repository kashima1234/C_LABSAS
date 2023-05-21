#include "input_string.h"
#include "set_lib.h"
#include "set_cons.h"
#include "output_string.h"
#include "set_operation.h"

int main(void) 
{
    size_t n1 = 0;
    size_t n2 = 0;

    char array_words1[MAX_LEN_STRING][MAX_LEN_STRING + 1] = { "" };
    char array_words2[MAX_LEN_STRING][MAX_LEN_STRING + 1] = { "" };
    char string1[MAX_LEN_STRING + 1] = "";
    char string2[MAX_LEN_STRING + 1] = "";

    int rc;

    if ((rc = input_string(string1)) != EXIT_SUCCESS)
        return rc;

    if ((rc = input_string(string2)) != EXIT_SUCCESS)
        return rc;

    if ((rc = split_string(array_words1, &n1, string1)) != EXIT_SUCCESS)
        return rc;

    if ((rc = split_string(array_words2, &n2, string2)) != EXIT_SUCCESS)
        return rc;

    if ((rc = delete_recurring_elem(array_words1, &n1)) != EXIT_SUCCESS)
        return rc;

    if ((rc = print_result(array_words1, n1, array_words2, n2)) != EXIT_SUCCESS)
        return rc;

    return EXIT_SUCCESS;
}
