#include "monty.h"

/**
 * madd - Adds the top two values of a stack_t linked list.
 * @stack: A pointer to the top node
 * @line_number: The line number of a Monty bytecodes
 */
void madd(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_error(swap_error(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	mpop(stack, line_number);
}
