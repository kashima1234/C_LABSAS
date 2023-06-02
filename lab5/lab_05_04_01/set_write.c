#include "set_write.h"

void write_one_student(FILE *const f, student_t *student)
{
     fprintf(f, "%s\n", student->last_name);
    fprintf(f, "%s\n", student->name);
    fprintf(f, "%d %d %d %d\n", student->marks[0], student->marks[1], student->marks[2], student->marks[3]);
}

int write_students_file(FILE *f, student_t *arr_students, int count_students, char const *argv)
{
    f = fopen(argv, "w");
    if (f != NULL)
    {
        for (int i = 0; i < count_students; i++)
            write_one_student(f, &arr_students[i]);
        fclose(f);
    }
    else
        return ERROR_OPEN_FILE;

    return EXIT_SUCCESS;
}