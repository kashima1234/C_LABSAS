#include <stdio.h>
#include <stdlib.h>
#define ERROR_INCORRECT_INPT_AR 2
#define NUMBER_OF_ARG 1
#define ERROR_INCORRECT_INPT_N 1
#define N 10

int inpt_ar(int *x, int *y);
int *find_neg(int *x, int *y);
int factor(int *x, int *y);
int sum(int *x, int *y);

int main(void)
{
	int n;

	printf("Enter number of elements: ");
	if (scanf("%d", &n) != NUMBER_OF_ARG)
	{
		printf("Error: incorrect input n\n");
		return ERROR_INCORRECT_INPT_N;
	}

	if ((n < 1) || (n > N))
	{
		printf("Error: incorrect number of elements");
		return ERROR_INCORRECT_INPT_N;
	}
	int arr[N];
	int *pb = arr, *pe = arr + n;
	
	int error = inpt_ar(pb, pe);

	if (error != EXIT_SUCCESS)
	{
		return error;
	}

	int *pm = find_neg(pb, pe);
	int s = sum(pb, pm);
	printf("%d", s);

	return EXIT_SUCCESS;
}


int inpt_ar(int *x, int *y)
{
	printf("Enter elements: ");
	for (int *pcur = x; pcur < y; pcur++)
	{
		if (scanf("%d", pcur) != NUMBER_OF_ARG)
		{
			printf("Error: incorrect input array\n");
			return ERROR_INCORRECT_INPT_AR;
		}
	}
	return EXIT_SUCCESS;
}


int *find_neg(int *x, int *y)
{
	for (int *pcur = x; pcur < y; pcur++)
	{
		if (*pcur < 0)
			return ++pcur;	
	}
	return y;
}

int factor(int *x, int *y)
{
	if (x == y)
	{
		return 1;
	}
	return *x * factor(x + 1, y);
}

int sum(int *x, int *y)
{
	int s = 0;

	for (int *pcur = x; pcur < y; pcur++)
	{
		s += factor(x, pcur + 1);
	}
	return s;
}






