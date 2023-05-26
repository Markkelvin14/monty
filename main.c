#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **toks = NULL;

/**
 * main - main command
 * @argc: argu count
 * @argv: argu vector
 * Return: (EXIT_SUCCESS) on succes
 */
int main(int argc, char **argv)
{
	FILE *filed = NULL;
	int cmd = EXIT_SUCCESS;

	if (argc != 2)
		return (usage_error_msg());

	filed = fopen(argv[1], "r");

	if (filed == NULL)
		return (open_error_msg(argv[1]));

	cmd = execute_monty(filed);
	fclose(filed);
	return (cmd);
}
