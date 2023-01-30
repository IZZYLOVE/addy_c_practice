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
 * myscanf - dynamically scans a string and allocates rquired memory to it
 * Return: pointer to resized memory base adress
 */
char *myscanf(void)
{
	int ld;
	char *sp = (char *)malloc(2);

	scanf("%s", sp);
	ld = mystrlen(sp);
	sp = (char *)realloc(sp, (ld * sizeof(char)));
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
