#include <stdio.h>

/**
 * add - operates addition
 * @a: first number
 * @b: second number
 * Return: void
 */

float add(float a, float b)
{
	printf("%f + %f = %f\n", a, b, a + b);
}

/**
 * sub - operates subtraction
 * @a: first number
 * @b: second number
 * Return: void
 */

float sub(float a, float b)
{
	printf("%f - %f = %f\n", a, b, a - b);
}

/**
 * mult - operates multiplication
 * @a: first number
 * @b: second number
 * Return: void
 */

float mult(float a, float b)
{
	printf("%f * %f = %f\n", a, b, a * b);
}

/**
 * div - operates divition
 * @a: first number
 * @b: second number
 * Return: void
 */

float div(float a, float b)
{
	printf("%f / %f = %f\n", a, b, a / b);
}

/**
 * main - determines which function to call
 * Return: always 0
 */

int main(void)
{
	int ch;
	float a, b;
	float (*fp[5])(float, float) = {add, sub, mult, div};
	printf("enter first number: ");
	scanf("%f", &a);
	printf("enter operand; 0 for add, 1 for sub, 2 for mult, 3 for div: ");
	scanf("%d", &ch);
	printf("enter second number: ");
	scanf("%f", &b);
	(*fp[ch])(a, b);
}
