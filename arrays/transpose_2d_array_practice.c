#include <stdio.h>

/**
 * main - processes 2d array and prints transpose elements in tabular form
 * run time initialization of arrays
 * Return: sum
 * variable r is used for rows and c for cols
 */

int main(void)
{
	int a[2][4];
	int r, c, sum = 0;

	for (r = 0; r < 2; r++)
	{
		for (c = 0; c < 4; c++)
		{
			printf("enter an element of array a[%d][%d]\n", r, c);
			scanf("%d", &a[r][c]);
		}
	}

	printf("processing the elements\n");
	printf("matrix is\n");
	for (r = 0; r < 2; r++)
	{
		for (c = 0; c < 4; c++)
		{
			sum = sum + a[r][c];
			printf("%d\t", a[r][c]);
		}
		printf("\n");
	}
	printf("sum = %d\n", sum);

	printf("transposed matrix is\n");
	sum = 0;
	for (r = 0; r < 4; r++)
	{
		for (c = 0; c < 2; c++)
		{
			sum = sum + a[c][r];
			printf("%d\t", a[c][r]);
		}
		printf("\n");
	}
	printf("sum = %d\n", sum);
}
