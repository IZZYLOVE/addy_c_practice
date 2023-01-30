#include <stdio.h>
#include <stdlib.h>

/**
 * mystrlen - counts the lenght of a string
 * @s: tartget string
 * Return: len
 */

int mystrlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}


/**
 * d_str_cat - concatenates string without memory overflow
 * @d: destination base adress
 * @s: source base adress
 * Return: base adress of d
 */
char *d_str_cat(char *d, char *s)
{
	int ld, ls, i;

	ld = mystrlen(d);
	ls = mystrlen(s);

	d = (char *)realloc(d, (ls * sizeof(char)));
	if (d != NULL)
	{
		for (i = 0; i <= ls; i++)
		{
			d[ld + i] = s[i];
		}
	}
	return (d);
}


/**
 * myscan_char - dynamically scans a string and allocates rquired memory to it
 * Return: pointer to resized memory base adress
 */
char *myscan_char(void)
{
	int ld;
	char *sp = malloc(2);

	if (sp == NULL)
	{
		printf("memory allocation:failed!\n");
		printf("insufficient heap space!\n");
		exit(98);
	}
	scanf("%s", sp);
	ld = mystrlen(sp);
	sp = realloc(sp, (ld * sizeof(char)));
	if (sp == NULL)
	{
		printf("memory allocation:failed!\n");
		printf("insufficient heap space!\n");
		exit(98);
	}
	return (sp);
}

/**
 * myscan_int - dynamically scans int and allocates rquired memory to it
 * Return: pointer to int
 */
int *myscan_int(void)
{
	int *sp = malloc(sizeof(int));

	if (sp == NULL)
	{
		printf("memory allocation:failed!\n");
		printf("insufficient heap space!\n");
		exit(98);
	}
	scanf("%d", sp);
	return (sp);
}


/**
 * myscan_float - dynamically scans float and allocates rquired memory to it
 * Return: pointer to float
 */
float *myscan_float(void)
{
	float *sp = malloc(sizeof(float));

	if (sp == NULL)
	{
		printf("memory allocation:failed!");
		printf("insufficient heap space!");
		exit(98);
	}
	scanf("%f", sp);
	return (sp);
}

/**
 * myscan_double - dynamically scans float and allocates rquired memory to it
 * Return: pointer to float
 */
double *myscan_double(void)
{
	double *sp = malloc(sizeof(double));

	if (sp == NULL)
	{
		printf("memory allocation:failed!");
		printf("insufficient heap space!");
		exit(98);
	}
	scanf("%lf", sp);
	return (sp);
}


/**
 * myarray - dinamically allocates memory to any specified array
 * @size: size of array
 * @datatype: data type of array
 * Return: pointer to allocated  memory base adress
 */
void *myarray(unsigned int size, char datatype)
{
	void *dm;

	if (size <= 0)
		return (NULL);
	if (sizeof(datatype) <= 0)
		return (NULL);
	dm = malloc(size * sizeof(datatype));
	return (dm);
}
