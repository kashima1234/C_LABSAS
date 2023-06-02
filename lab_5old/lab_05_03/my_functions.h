#ifndef _MY_FUNCTIONS_H_
#define _MY_FUNCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#define ERROR -1

int create_bin_file(FILE *file);
int print_bin_file(FILE *file);
int sort_bin_file(FILE *file);
int sizef(FILE *file, size_t *size);
int get_number_by_pos(FILE *file, int position, int *num);
int put_number_by_pos(FILE *file, int position, int num);

#endif