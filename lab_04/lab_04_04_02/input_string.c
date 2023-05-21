#include "input_string.h"

int input_string(char *const s)
{
    if (s == NULL)
        return ERR_NULL_POINTER;

    char *rc = fgets(s, MAX_LEN_STRING + 2, stdin);
    if (rc == NULL || strlen(s) > MAX_LEN_STRING)
        return ERR_INPUT_STR;
    return EXIT_SUCCESS;
}
