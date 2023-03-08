#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <limits.h>


void printbitsorig(uint32_t num)
{
    for(int i = 31; i >= 0; i--)
    {
        	uint32_t mask = 1u << i;
            printf("%u", (num & mask) ? 1 : 0);
    }
    printf("\n");
}
void printbits(uint32_t num)
{
    uint32_t temp;
    uint32_t res;
    uint32_t rev;

    rev = 0;
    res = num;
    for (int i = 0; i < 32; i++)
    {
        temp = res % 2;
        res = res / 2;
        if (temp == 1)
        {
            rev = rev + 1;
        }
        if (i < 31)
        {
            rev = rev * 2;
        }
    }
    res = rev;
    for (int i = 0; i < 32; i++)
    {
        temp = res % 2;
        res = res / 2;
        printf("%u", temp);
    }
}

uint32_t encryption(uint32_t num)
{          
    uint32_t odd, even, res;                    

    odd = num & 0xAAAAAAAA ; //10101010101010101010101010101010 (четные биты)                                
    odd = odd << 1; // сдвигаем четные биты на одну позицию вправо                                 
    even = num & 0x55555555;  //01010101010101010101010101010101 (нечетные биты                                                                   
    even = even >> 1;  // сдвигаем четные биты на одну позицию влев
    res = even | odd;                                 
    return res;
}

int main()
{
    uint32_t res;
    uint32_t num;

    printf("Enter value:\n");
    if (!(scanf("%u", &num)) || num > UINT_MAX)
    {
        printf("Error: first value is not a number.\n");
        return EXIT_FAILURE;
    }
    printbitsorig(num);
    res = encryption((uint32_t) num);
    printf("Result: ");
    printbits(res);
    return EXIT_SUCCESS;
} 
