#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define ERROR_INCO_PARAM 1
#define NUMBER_OF_ARGR 1


#define N 10
#define M 10


int set_input_param(size_t *a)
{
    int rc = scanf("%zu", a);
    if ((rc != NUMBER_OF_ARGR) || (*a <= 0) || (*a > 10))
    {
        printf("Error: incorrect input\n");
        return ERROR_INCO_PARAM;
    }

    return EXIT_SUCCESS;
}


// void set_calculate_index(size_t n, size_t m, size_t i, size_t j, size_t* index_i, size_t* index_j)
// {
//     size_t row = n -1 - i;
//     size_t col = (j % 2 == 0) ? m -1 - j : j;

//     *index_i = row;
//     *index_j = m - 1 -col;
// }
// void set_fill_matrix(int matrix[][M], size_t n, size_t m)
// {
//     printf("Enter elements\n");
//     int number = 1;
//     for (size_t j = 0; j < m; j++)
//     {
//         for (size_t i = 0; i < n; i++)
//         {
//             size_t index_i, index_j;
//             set_calculate_index(n, m, i, j, &index_i, &index_j);
//             matrix[index_i][index_j] = number++;
//         }
//     }

// }

// void set_fill_matrix(int matrix[][M], size_t n, size_t m)
// {
//     int elem = 1;
//     for (size_t j = 0; j < m; j++)
//     {
//         size_t j = k - 1;
//         for (size_t i = 0; i < n; i++)
//         {
//             // size_t i = l - 1;
//             matrix[i][j] = elem;
//             elem++;
//         }
//         j--;

//         if (j == -1)
//             break;

//         for (size_t i = 0; i < n; i++)
//         {
//             matrix[i][j] = elem;
//             elem++;
//         }
//     }
// }


void set_fill_matrix(int matrix[][M], int n, int m)
{
    int elem = 1;
    for (int j = m - 1; j >= 0; j--)
    {
        // size_t j = k - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            // size_t i = l - 1;
            matrix[i][j] = elem;
            elem++;
        }
        j--;

        if (j == -1)
            break;

        for (size_t i = 0; i < n; i++)
        {
            matrix[i][j] = elem;
            elem++;
        }
    }
}


void set_print_array(int array[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%d ", array[i]);
}

void set_print_matrix(int matrix[][M], size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
    {
        set_print_array(matrix[i], m);
        printf("\n");
    }
}

int main()
{
    int matrix[N][M];
    size_t n; 
    size_t m;

    printf("Enter n: ");
    int error = set_input_param(&n);
    if (error != EXIT_SUCCESS)
        return error;

    printf("Enter m: ");

    error = set_input_param(&m);
    if (error != EXIT_SUCCESS)
        return error;

    set_fill_matrix(matrix, n, m);
    set_print_matrix(matrix, n, m);

    return EXIT_SUCCESS;
}