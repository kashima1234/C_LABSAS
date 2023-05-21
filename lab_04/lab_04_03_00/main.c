#include "set_operation.h"
#include "input_string.h"
#include "code_error.h"
#include "set_lib.h"
#include "set_cons.h"


int main(void)
{
    char array_words[MAX_LEN_STRING + 1][MAX_LEN_STRING + 1] = { "" };

    char string[MAX_LEN_STRING + 1] = "";
    char new_string[MAX_LEN_STRING + 1] = "";

    int n = 0;

    int rc;
    if ((rc = input_string(string)) != EXIT_SUCCESS)
        return rc;

    if ((rc = split_string(array_words, &n, string)) != EXIT_SUCCESS)
        return rc;

    if ((rc = create_new_string(array_words, n, new_string)) != EXIT_SUCCESS)
        return rc;

    if (strlen(new_string) == 0)
        return ERR_EMPTY_STRING;

    printf("Result: %s\n", new_string);
    return EXIT_SUCCESS;
}
