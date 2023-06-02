#ifndef SET_PUT
#define SET_PUT

#include <stdio.h>
#include <stdlib.h>
#include "set_define.h"


int put_by_pos(FILE *f, int pos, const int *const number);
int pull_by_pos(FILE *f, int pos, int *const number);
int pull_lastpos_number(FILE *f, int *const pos_number);

#endif
