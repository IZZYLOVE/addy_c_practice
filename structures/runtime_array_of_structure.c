#include <stdio.h>
#include "struct.h"

/**
 * main - processes structure in c
 * compile time initialization practice of structures in c
 * struct student: structure data type
 * Return: void
 */


void main(void)
{
	int n, i;
	char end = 'y';
	struct student s[1000];

	while (end != 'n')
	{
		s[n].s_n = n;

		printf("enter name of student:");
		scanf("%s", s[n].name);
		printf("enter score of student:");
		scanf("%f", &s[n].score);
		i++;
		n++;
		printf("enter another record? y/n:");
		scanf("%s", &end);
		printf("info for s%d\n", n);
		printf("%d %s %f\n", s[n].s_n, s[n].name, s[n].score);
	}
}

