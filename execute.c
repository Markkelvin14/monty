#include "monty.h"

int execute_monty(FILE *filed);

/**
 * execute_monty - function to execute a Monty bytecodes
 * @filed: File descriptor
 * Return: EXIT_SUCCESS on success
 */
int execute_monty(FILE *filed)
{
	stack_t *stack = NULL;
	char *bre = NULL;
	size_t length = 0, exit_info = EXIT_SUCCESS;
	unsigned int number = 0, k = 0;
	void (*fun)(stack_t**, unsigned int);
	int read;

	if (start_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while ((read = getline(&bre, &length, filed)) != -1)
	{
		number++;
		toks = strsep(bre, DELIMS);
		if (toks == NULL)
		{
			if (check_line(bre, DELIMS))
				continue;

			empty_stack(&stack);
			return (merror());
		}
		else if (toks[0][0] == '#')
		{
			empty_toks();
			continue;
		}
		fun = match_func(toks[0]);
		if (fun == NULL)
		{
			empty_stack(&stack);
			exit_info = unknown_error_msg(toks[0], number);
			empty_toks();
			break;
		}
		k = curr_len();
		fun(&stack, number);

		if (curr_len() != k)
		{
			if (toks && toks[k])
				exit_info = atoi(toks[k]);
			else
				exit_info = EXIT_FAILURE;
			empty_toks();
			break;
		}
		empty_toks();
	}
	empty_stack(&stack);

	if (bre && *bre == 0)
	{
		free(bre);
		return (merror());
	}

	free(bre);
	return (exit_info);
}
