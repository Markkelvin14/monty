#include "monty.h"

/**
 * push - Pushes a value to a stack
 * @stack: A pointer to the top node
 * @line_number: The current working line number of a Monty bytecodes file.
 */

void mpush(stack_t **stack, unsigned int line_number)
{
	stack_t *bre, *newnode;
	int m;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		set_error(merror());
		return;
	}
	for (m = 0; toks[1][m]; m++)
	{
		if (toks[1][m] == '-' && m == 0)
			continue;
		if (toks[1][m] < '0' || toks[1][m] > '9')
		{
			set_error(invalid_error_msg(line_number));
			return;
		}
	}
	newnode->n = atoi(toks[1]);
	if (check_stack(*stack) == MSTACK)
	{
		bre = (*stack)->next;
		newnode->prev = *stack;
		newnode->next = bre;
		if (bre)
			bre->prev = newnode;
		(*stack)->next = newnode;
	}
	else
	{
		bre = *stack;
		while (bre->next)
			bre = bre->next;
		newnode->prev = bre;
		bre->next = NULL;
		bre->next = newnode;
	}
}
/**
 * pall - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void mpall(stack_t **stack, unsigned int line_number)
{
	stack_t *bre = (*stack)->next;

	while (bre != NULL)
	{
		printf("%d\n", bre->n);
		bre = bre->next;
	}
	(void)line_number;
}

/**
 * unknown_error_msg - Prints unknown instruction error messages.
 * @opcode: error occurred.
 * @line_number: Line number in Monty bytecodes file
 * Return: (EXIT_FAILURE)
 */
int unknown_error_msg(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
			line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * invalid_error_msg - Prints invalid error messages.
 * @line_number: Line number in Monty bytecodes file
 * Return: (EXIT_FAILURE)
 */
int invalid_error_msg(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
