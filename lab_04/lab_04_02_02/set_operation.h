#ifndef SET_OPERA
#define SET_OPERA


#include "set_cons.h"
#include "set_lib.h"


int write_symbol(char *const elem, const char symbol, int *const check_record, int *const count);
int split_string(char (*const array_words)[MAX_LEN_STRING + 1], size_t *n, const char *const string);
int delete_recurring_elem(char (*const array_words)[MAX_LEN_STRING + 1], size_t *n);

#endif
