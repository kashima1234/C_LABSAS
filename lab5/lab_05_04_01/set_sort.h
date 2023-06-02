#ifndef SORT
#define SORT

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "set_define.h"

int last_name_c(const void *a, const void *b);
void swap(student_t *const student1, student_t *const student2);
void sort_students(student_t *arr_students, int count_students);

#endif

