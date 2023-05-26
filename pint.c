#include "monty.h"

/**
 * monty_pint - Prints the top value of a stack_t linked list.
 * @stack: A pointer to the top node
 * @line_number: a Monty bytecodes file.
 */
void mpint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_error(print_error(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}
/**
 * print_error - Prints pint error messages for empty stacks.
 * @line_number: Line number in Monty bytecodes
 * Return: (EXIT_FAILURE)
 */
int print_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}
