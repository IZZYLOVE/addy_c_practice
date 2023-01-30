#include <stdio.h>
#include <stdlib.h>
#include "myfunctions.h"

/**
 * main - calls d_str_cat function
 * Return: Always 0
 */

int main(void)
{
	char *d, *s;
	printf("enter first string: ");
	d = myscanf();
	printf("enter second string: ");
	s = myscanf();

	d = d_str_cat(d, s);
	printf("%s", d);
	return (0);
}
