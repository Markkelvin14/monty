#include "monty.h"
#include <string.h>

/**
 * curr_len - Gets the length of current toks.
 * Return: Length of current toks
 */
unsigned int curr_len(void)
{
	unsigned int tlen = 0;

	while (toks[tlen])
		tlen++;
	return (tlen);
}
/**
 * empty_toks - Frees the global op_toks array of strings.
 */
void empty_toks(void)
{
	size_t m = 0;

	if (toks == NULL)
		return;
	for (m = 0; toks[m]; m++)
		free(toks[m]);
	free(toks);
}

/**
 * check_line - Checks if a line read from getline only contains delimiters.
 * @dre: A pointer to the line.
 * @del: A string of delim char
 * Return: 0
 */
int check_line(char *dre, char *del)
{
	int m;
	int k;

	for (m = 0; dre[m]; m++)
	{
		for (k = 0; del[k]; k++)
		{
			if (dre[m] == del[k])
				break;
		}
		if (del[k] == '\0')
			return (0);
	}
	return (1);
}

/**
 * match_func - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 * Return: A pointer
 */
void (*match_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t func[] = {
		{"push", mpush},
		{"pall", mpall},
		{"pint", mpint},
		{"pop", mpop},
		{"swap", mswap},
		{"add", madd},
		{"nop", mnop},
		{"sub", msub},
		{NULL, NULL}
	};
	int m;

	for (m = 0; func[m].opcode; m++)
	{
		if (strcmp(opcode, func[m].opcode) == 0)
			return (func[m].f);
	}
	return (NULL);
}
