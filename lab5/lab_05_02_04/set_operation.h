#ifndef OPERA
#define OPERA

#include <stdio.h>
#include <stdlib.h>
#include "set_def.h"


int find_avar_min_max(FILE *const f, double *const avar, const int at_begin, const int at_end);
int find_min_max_f_file(FILE *const f, int *const i_max, int *const i_min);
void define_begin_end(int *const i_1_d, int *const i_2_d);

#endif
