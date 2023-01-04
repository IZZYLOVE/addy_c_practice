#include <stdio.h>
#include <stdlib.h>

#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

int mystrlen(char *s);
char *d_str_cat(char *d, char *s);
char *dmc_to_str_size(char *sp);



#endif /* MYFUNCTIONS_H */

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
 * dmc_to_str_size - resize a dynamic memory to the size of its string
 * @sp: pointer to string base adress
 * Return: pointer to resized memory base adress
 */
char *dmc_to_str_size(char *sp)
{
	int ld;

	ld = mystrlen(sp);
	sp = (char *)realloc(sp, (ld * sizeof(char)));
	return (sp);
}
