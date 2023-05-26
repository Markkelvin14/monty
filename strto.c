#include <stdlib.h>
#include "monty.h"

/**
 * strsep - takes a string and seperates its words
 * @string: string to seperate
 * @del: delimitor
 * Return: string
 */

char **strsep(char *string, char *del)
{
	char **bre = NULL;
	int w, wlen, k = 0, m = 0;

	if (string == NULL || !*string)
		return (NULL);
	w = word_count(string, del);


	if (w == 0)
		return (NULL);
	bre = malloc((w + 1) * sizeof(char *));
	if (bre == NULL)
		return (NULL);

	while (m < w)
	{
		wlen = word_length(string, del);
		if (check_del(*string, del))
		{
			string = next_word(string, del);
		}
		bre[m] = malloc((wlen + 1) * sizeof(char));

		if (bre[m] == NULL)
		{
			while (m >= 0)
			{
				m--;
				free(bre[m]);
			}
			free(bre);
			return (NULL);
		}
		while (k < wlen)
		{
			bre[m][k] = *(string + k);
			k++;
		}
		bre[m][k] = '\0';
		string = next_word(string, del);
		m++;
	}
	bre[m] = NULL;
	return (bre);
}

/**
 * check_del - checks if stream has delimitor
 * @c: character in stream
 * @del: Pointer
 * Return: 0
 */

int check_del(char c, char *del)
{
	int m = 0;

	while (del[m])
	{
		if (del[m] == c)
			return (1);
		m++;
	}
	return (0);
}

/**
 * word_length - gets the word length
 * @string: string
 * @del: delimitors
 * Return: word
 */

int word_length(char *string, char *del)
{
	int bre = 0, k = 1, m = 0;

	while (*(string + m))
	{
		if (check_del(string[m], del))
			k = 1;
		else if (k)
		{
			bre++;
		}
		if (bre > 0 && check_del(string[m], del))
			break;
		m++;
	}
	return (bre);
}

/**
 * word_count - gets the word count of a string
 * @string: string
 * @del: delimitors
 * Return: the word count
 */

int word_count(char *string, char *del)
{
	int bre = 0, k = 1, m = 0;

	while (*(string + m))
	{
		if (check_del(string[m], del))
			k = 1;
		else if (k)
		{
			k = 0;
			bre++;
		}
		m++;
	}
	return (bre);
}

/**
 * next_word - gets the next word in a string
 * @string: string
 * @del: delimitors
 * Return: pointer
 */

char *next_word(char *string, char *del)
{
	int k = 0, m = 0;

	while (*(string + m))
	{
		if (check_del(string[m], del))
			k = 1;
		else if (k)
			break;
		m++;
	}
	return (string + m);
}
