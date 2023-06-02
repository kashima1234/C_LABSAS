#ifndef READ
#define READ

#include <stdio.h>
#include <stdlib.h>
#include "set_define.h"

int read_student(FILE *const f, student_t *student);
int init_array_student_array_from_file(FILE *f, student_t *arr_students, int *const count_students, char const *argv[]);

#endif
