#ifndef DEF
#define DEF

#define ERROR_OPEN_FILE (-1)
#define ERROR_NO_DATA (-2)
#define ERROR_MT_FILE (-3)
#define ERROR_NO_MARKS (-3)
#define ERROR_NO_VALID_PARA 53
#define ERROR_END_OF_FILE 1
#define COUNT_MARKS 4

#define NMAX 100

typedef struct student
{
    char last_name[26];
    char name[11];
    int marks[4];
} student_t;

#endif

