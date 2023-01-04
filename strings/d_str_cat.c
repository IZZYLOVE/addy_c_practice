#include <stdio.h>
#include <stdlib.h>
#include "myfunctions.h"

/**
 * main - calls d_str_cat function
 * Return: Always 0
 */

int main(void)
{
	char *d = (char *)malloc(2);
	char *s = (char *)malloc(2);

	printf("enter first string: ");
	scanf("%s", d);
	d = dmc_to_str_size(d);
	printf("enter second string: ");
	scanf("%s", s);
	s = dmc_to_str_size(s);

	d = d_str_cat(d, s);
	printf("%s", d);
	return (0);
}
