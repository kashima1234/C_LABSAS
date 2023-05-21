#ifndef OPERA
#define OPERA


#include "code_error.h"
#include "set_lib.h"
#include "set_cons.h"


int check_day(const char *const word, int *const day);
int check_month(const char *const word, int *const month);
int check_year(const char *const word, int *const year);
int check_valid_data(const int day, const int month, const int year);
int check_date(const char *const str_day, const char *const str_month, const char *const str_year);
int split_string(char (*const array_words)[MAX_LEN_STRING + 1],
int *const n, char *const string);


#endif
