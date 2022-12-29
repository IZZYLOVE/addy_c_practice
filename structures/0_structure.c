#include <stdio.h>
#include "struct.h"

/**
 * main - processes structure in c
 * compile time initialization practice of structures in c
 * struct students: structure data type
 * Return: void
 */


void main(void)
{
	struct student s1 = {1, "king", 90};
	struct student s2 = {2, "addy", 80};
	struct student s3 = {3, "ken", 70};

	printf("info for s1\n");
	printf("%d %s %f\n", s1.s_n, s1.name, s1.score);
	printf("info for s2\n");
	printf("%d %s %f\n", s2.s_n, s2.name, s2.score);
	printf("info for s3\n");
	printf("%d %s %f \n", s3.s_n, s3.name, s3.score);
}

