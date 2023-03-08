#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num;
    int result;

    printf("Enter thre-digit number:\n");
    scanf("%d", &num);
    result = (num / 100) * ((num / 10) % 10) * (num % 10);
    printf("Result = %d", abs(result));
    return EXIT_SUCCESS;
}

// anotherway if we have a,b,c to ect 
// a = num / 100 получ сотни
// b = (num /10) % 10 полчаем десятк
// c = num % 10 получаем единцы
