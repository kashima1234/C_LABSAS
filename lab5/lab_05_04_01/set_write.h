#ifndef WRITE
#define WRITE

#include <stdio.h>
#include <stdlib.h>
#include "set_define.h"

void write_one_student(FILE *const f, student_t *student);
int write_students_file(FILE *F, student_t *arr_students, int count_students, char const *argv);

#endif