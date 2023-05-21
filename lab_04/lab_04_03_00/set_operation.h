#ifndef OPERA
#define OPERA

#include "set_lib.h"
#include "set_cons.h"
#include "code_error.h"



int split_string(char (*const array_words)[MAX_LEN_STRING + 1],
int *const n, char *const string);
int shift(char *const word, size_t *const i, size_t *const n);
int del_next_occur_first_letter(char *const word, size_t n);
int add_space(char *const string);
int create_new_string(char (*const array_words)[MAX_LEN_STRING + 1], int n, char *const new_string);

#endif
