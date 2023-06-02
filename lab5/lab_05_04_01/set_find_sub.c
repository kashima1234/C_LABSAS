#include "set_find_sub.h"


int find_student_by_substr(student_t *arr_students, int count_students, 
char *substr, student_t *students, int *number_substr_std)
{
    size_t lenght = strlen(substr);
    int j = 0;
    for (int i = 0; j < count_students; i++)
    {
        if (strncmp(arr_students[i].last_name, substr, lenght) == 0)
        {
            students[j] = arr_students[i];
            (*number_substr_std)++;
            j++;
        }
    }
    if (*number_substr_std == 0)
        return ERROR_NO_DATA;
    return EXIT_SUCCESS;
}