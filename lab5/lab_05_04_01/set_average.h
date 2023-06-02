#ifndef AVERAGE
#define AVERAGE

#include <stdio.h>
#include <stdlib.h>
#include "set_define.h"

void calc_sum_marks(const int *const marks, double *const sum);
int calc_average(student_t *arr_students, int count_students, double *average);
void delete_student(student_t *arr_students, int *count_students, double average);


#endif