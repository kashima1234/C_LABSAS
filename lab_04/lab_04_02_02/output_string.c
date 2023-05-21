#include "output_string.h"

int print_result(char (*const array_words1)[MAX_LEN_STRING + 1], const size_t n1, char (*const array_words2)[MAX_LEN_STRING + 1], const size_t n2)
{
    if (array_words1 == NULL || array_words2 == NULL)
        return ERR_NULL_POINTER;

    printf("Result:\n");

    for (size_t i = 0; i < n1; i++)
    {
        int equal = 0;

        for (size_t j = 0; j < n2; j++)
        {
            if (strcmp(array_words1[i], array_words2[j]) == 0)
            {
                printf("%s yes\n", array_words1[i]);
                equal = 1;
                break;
            }
        }

        if (equal == 0)
            printf("%s no\n", array_words1[i]);
    }

    return EXIT_SUCCESS;
}
