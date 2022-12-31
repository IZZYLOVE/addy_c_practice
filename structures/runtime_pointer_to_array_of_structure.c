#include <stdio.h>
#include <stdlib.h>/* for screen clear etc */
#include "struct.h"

/**
 * main - processes structure in c
 * run time initialization practice of structures in c
 * this program initializes the variable for structure at run time
 * struct student: structure data type
 * Return: void
 */

void main(void)
{
	system("clear");
	int i, x, n;
	char end = 'y';
	struct student s[1000];
	struct student *p;

	p = s;
	while (end != 'n')
	{
		(*p).s_n = n;
		printf("iteration for n=%d\n", n);
		printf("enter name of student:");
		scanf("%s", (*p).name);
		printf("enter score of student:");
		scanf("%f", &(*p).score);
		printf("enter another record? y/n:");
		scanf("%s", &end);
		printf("%d %s %f\n", (*p).s_n, (*p).name, (*p).score);
		printf("address of *p %p\n", p);
		printf("size of struct student %ld\n", sizeof(struct student));
		p++;
/* P++ breaks the iteration of i++, i dnt know why but found a way around it */
		i++;
		n++;
	}
	printf("\n");
	printf("\n");
	printf("starting from  x=0\n");
	p = &s[0];
	for (; x < n;)
	{
		printf("address of *p %p\n", p);
		printf("%d %s %f\n", (*p).s_n, (*p).name, (*p).score);
		x++;
		p++;
	}
/*
 * betty more than 40 lines warning from line 55
 * but left it anyways for lessons sake
 */
	printf("\n");
	printf("\n");
	printf("starting from  x=%d\n", x);
	for (; x >= 0;)
	{
		x--;
		p--;
		printf("address of *p %p\n", p);
		printf("%d %s %f\n", (*p).s_n, (*p).name, (*p).score);
	}

}
