#include "monty.h"

int merror(void);

/**
 * set_error - Sets last element to be an error code.
 * @err_code: Integer to store as a string.
 */
void set_error(int err_code)
{
	int tlen = 0, m = 0;
	char *exitr = NULL;
	char **new = NULL;

	tlen = curr_len();
	new = malloc(sizeof(char *) * (tlen + 2));
	if (!toks)
	{
		merror();
		return;
	}
	while (m < tlen)
	{
		new[m] = toks[m];
		m++;
	}
	exitr = get(err_code);
	if (!exitr)
	{
		free(new);
		merror();
		return;
	}
	new[m++] = exitr;
	new[m] = NULL;
	free(toks);
	toks = new;
}

/**
 * merror - Prints malloc error messages.
 * Return: (EXIT_FAILURE)
 */
int merror(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * usage_error_msg - Prints usage error messages.
 * Return: (EXIT_FAILURE)
 */
int usage_error_msg(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}
/**
 * open_error_msg - Prints file opening error messages
 * @filename: Name of file failed to open
 * Return: (EXIT_FAILURE)
 */
int open_error_msg(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_error - Prints unknown instruction error messages.
 * @opcode: Opcode error occurred.
 * @line_number: Line number in Monty bytecodes file where error occured.
 * Return: (EXIT_FAILURE)
 */
int unknown_error_msg(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
			line_number, opcode);
	return (EXIT_FAILURE);
}
