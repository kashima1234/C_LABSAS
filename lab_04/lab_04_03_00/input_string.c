#include "input_string.h"



int check_string(const char *const string)
{
    if (string == NULL)
        return ERR_NULL_POINTER;

    size_t count = 0;
    for (const char *ptr_string = string; *ptr_string != '\0'; ptr_string++)
        if (ispunct(*ptr_string) || isspace(*ptr_string))
            count++;
    if (strlen(string) == count)
        return ERR_ALL_STR_ISSPACE;
    return EXIT_SUCCESS;
}

int input_string(char *const string)
{
    if (string == NULL)
        return ERR_NULL_POINTER;

    char *rc = fgets(string, MAX_LEN_STRING + 2, stdin);
    if (rc == NULL || strlen(string) > MAX_LEN_STRING
        || check_string(string) == ERR_ALL_STR_ISSPACE)
        return ERR_INPUT_STR;
    return EXIT_SUCCESS;
}
