#ifndef _MY_FUNCTIONS_H_
#define _MY_FUNCTION_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define L_N 25
#define F_N 10
#define N 4
#define SIZE_ARR 10

#define ERROR -1

typedef struct
{
    char lastname[L_N + 1];
    char firstname[F_N + 1];
    uint32_t marks[N];
} st;

int read_student_info(FILE *file, st *student);
int read_students(FILE *file, st *arr, int *n);
void print_st_info_file(FILE *file, st *student);
void printf_st(FILE *file, st *arr, int n);
int surname_fstr(FILE *file, st *arr, int n, char *str);
void sort_students(st *arr, int n);
float average_calc(st *arr, int n, float *mas_avr);
void del_student(st *arr, float *mas_avr, int *n, float s_sr);

#endif