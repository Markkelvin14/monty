#include "monty.h"

/**
 * monty_swap - Swaps the top two value elements of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void mswap(stack_t **stack, unsigned int line_number)
{
	stack_t *bre;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_error(swap_error(line_number, "swap"));
		return;
	}

	bre = (*stack)->next->next;
	(*stack)->next->next = bre->next;
	(*stack)->next->prev = bre;

	if (bre->next)
		bre->next->prev = (*stack)->next;
	bre->next = (*stack)->next;
	bre->prev = *stack;
	(*stack)->next = bre;
}

/**
 * swap_error - Prints swap error message
 * @line_number: Line number in Monty bytecodes
 * @code: where the error occurred
 * Return: (EXIT_FAILURE)
 */
int swap_error(unsigned int line_number, char *code)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, code);
	return (EXIT_FAILURE);
}
