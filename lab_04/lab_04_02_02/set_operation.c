#include "set_operation.h"


int write_symbol(char *const elem, const char symbol, int *const check_record, int *const count)
{
    if (check_record == NULL || count == NULL || elem == NULL)
        return ERR_NULL_POINTER;

    if (symbol != '\n')
    {
        *elem = symbol;
        *check_record = 1;
        (*count)++;
    }

    return EXIT_SUCCESS;
}


int split_string(char (*const array_words)[MAX_LEN_STRING + 1], size_t *n, const char *const string)
{
    if (string == NULL || n == NULL || array_words == NULL)
        return ERR_NULL_POINTER;

    int j = 0;
    int check_record = 0;

    for (const char *ptr_string = string; *ptr_string != '\0'; ptr_string++)
    {
        if (ispunct(*ptr_string) || isspace(*ptr_string))
        {
            array_words[*n][j] = '\0';

            if (strlen(array_words[*n]) > MAX_LEN_WORD)
                return ERR_LEN_WORD;

            if (check_record == 1)
                (*n)++;

            check_record = 0;
            j = 0;
            continue;
        }

        if (write_symbol(&array_words[*n][j], *ptr_string, &check_record, &j) == ERR_NULL_POINTER)
            return ERR_NULL_POINTER;
    }

    if (check_record)
        (*n)++;

    return EXIT_SUCCESS;
}


int delete_recurring_elem(char (*const array_words)[MAX_LEN_STRING + 1], size_t *n)
{
    if (array_words == NULL || n == NULL)
        return ERR_NULL_POINTER;

    size_t destination = 0;

    for (size_t i = 0; i < *n; i++)
    {
        int flag = 0;

        for (size_t j = 0; j < i; j++)
        {
            if (strcmp(array_words[i], array_words[j]) == 0)
            {
                flag = 1;
                break;
            }
        }

        if (flag)
            destination++;
        else
        {
            if (destination)
            {
                strncpy(array_words[i - destination], array_words[i], MAX_LEN_STRING);
                array_words[i - destination][MAX_LEN_STRING] = '\0';
            }
        }
    }

    *n -= destination;

    return EXIT_SUCCESS;
}

