#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "myfunctions.h"

/**
 * main - processes structure in c
 * compile time initialization practice of structures in c
 * struct student: structure data type
 * Return: void
 */


void main(void)
{
	int n, i, j;
	char end = 'y';

	printf("enter total number of students:");
	scanf("%d", &i);
	j = i;
	struct student *s = (struct student *)malloc(i * sizeof(struct student));

	for (n = 0; end != 'n' && n < j; n++)
	{
		s[n].s_n = n;

		printf("enter name of student:");
		s[n].name = myscanf();
		printf("enter score of student:");
		scanf("%f", &s[n].score);
		i++;
		printf("enter another record? y/n:");
		scanf("%s", &end);
		printf("info for s%d\n", n);
		printf("%d %s %f\n", s[n].s_n, s[n].name, s[n].score);
	}
}

