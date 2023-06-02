#ifndef SET_SORT
#define SET_SORT


#include <stdio.h>
#include "set_put_number.h"
#include "set_define.h"

void swap(FILE *f, int number1, int number2, int f_pos, int s_pos);
int sort_num_in_file(FILE *f);
int sort(char const *argv);

#endif
