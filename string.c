#include <stdlib.h>
#include "monty.h"

/**
 * get - gets a character pointer to new string containing int
 * @number: number to convert to string
 * Return: character pointer
 */
char *get(int number)
{
	unsigned int bre;
	int len = 0;
	long line = 0;
	char *ans;

	bre = abs_val(number);
	len = buff_len(bre, 10);

	if (number < 0 || line < 0)
		len++;
	ans = malloc(len + 1);
	if (ans == NULL)
		return (NULL);

	full_buffer(bre, 10, ans, len);
	if (number < 0 || line < 0)
		ans[0] = '-';

	return (ans);
}

/**
 * abs_val - gets the absolute value of an integer
 * @m: integer to get absolute value of
 * Return: abs value
 */
unsigned int abs_val(int m)
{
	if (m < 0)
		return (-(unsigned int)m);
	return ((unsigned int)m);
}

/**
 * buff_len - gets length of buffer needed for an unsigned int
 * @number: number to get length needed
 * @b: base of number
 * Return: integer containing len of buf
 */
int buff_len(unsigned int number, unsigned int b)
{
	int length = 1;

	while (number > b - 1)
	{
		length++;
		number /= b;
	}
	return (length);
}

/**
 * full_buffer - fills buffer with correct numbers up to base 36
 * @number: number to convert to string given base
 * @b: base of number used
 * @buffer: buffer to fill with result
 * @size: size of buffer
 * Return: nthing.
 */
void full_buffer(unsigned int number, unsigned int b, char *buffer, int size)
{
	int bre, m = size - 1;

	buffer[size] = '\0';
	while (m >= 0)
	{
		bre = number % b;
		if (bre > 9)
			buffer[m] = bre + 87;
		else
			buffer[m] = bre + '0';
		number /= b;
		m--;
	}
}
