#include "my_functions.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        puts("USAGE: app.exe input_file.txt");
        return EXIT_FAILURE;
    }
    
    FILE *input_file = fopen(argv[1], "r");
    if (!input_file)
    {
        puts("File doesn't exist!");
        return EXIT_FAILURE;
    }
    
    double averge;
    int rc = find_averge(input_file, &averge);
    if (rc != EXIT_SUCCESS)
    {
        puts("Mistake in input!");
        return EXIT_FAILURE;
    }
    
    fseek(input_file, 0, SEEK_SET);

    double result = near_to_avg(input_file, averge);
    printf("%0.6f\n", result);
    
    return EXIT_SUCCESS;
}