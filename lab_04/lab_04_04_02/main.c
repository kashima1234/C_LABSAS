#include "input_string.h"
#include "set_cons.h"
#include "set_lib.h"
#include "code_error.h"
#include "set_operation.h"



int main(void)
{
    char string[MAX_LEN_STRING + 1] = "";
    char array_words[MAX_LEN_STRING][MAX_LEN_STRING + 1] = { "" };

    int n = 0;
    int rc;
    if ((rc = input_string(string)) != EXIT_SUCCESS)
        return rc;

    rc = split_string(array_words, &n, string);
    if (n != COUNT_WORDS)
    {
        printf("NO\n");
        return EXIT_SUCCESS;
    }

    if ((rc += check_date(array_words[0], array_words[1], array_words[2])) == EXIT_SUCCESS)
    {
        printf("YES\n");
        return EXIT_SUCCESS;
    }
    printf("NO\n");
    return EXIT_SUCCESS;
}
