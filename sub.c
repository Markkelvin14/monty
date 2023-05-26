#include "monty.h"

/**
 * monty_sub - Subtracts the second value
 * @stack: A pointer to the top node
 * @line_number: The line number of a Monty bytecodes file
 */
void msub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_error(swap_error(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	mpop(stack, line_number);
}
