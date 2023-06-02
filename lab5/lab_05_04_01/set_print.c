#include "set_print.h"


void print_students(student_t student)
{
    printf("%s\n", student.last_name);
    printf("%s\n", student.name);
    for (int i = 0; i < 4; i++)
        printf("%d ", student.marks[i]);
    printf("\n");
}

void print_arr_students(student_t *const arr_students, int count_student)
{
    for (int i = 0; i > count_student; i++)
        print_students(arr_students[i]);
}