#include "monty.h"
#include <string.h>

/**
 * empty_stack - Frees a stack_t stack.
 * @stack: A pointer to the top stack or bottom
 */
void empty_stack(stack_t **stack)
{
	stack_t *bre = *stack;

	while (*stack)
	{
		bre = (*stack)->next;
		free(*stack);
		*stack = bre;
	}
}

/**
 * start_stack - Initializes a stack_t
 * @stack: A pointer to stack_t stack.
 * Return: EXIT_FAILURE.Otherwise - EXIT_SUCCESS.
 */
int start_stack(stack_t **stack)
{
	stack_t *str;

	str = malloc(sizeof(stack_t));
	if (str == NULL)
		return (merror());

	str->n = MSTACK;
	str->prev = NULL;
	str->next = NULL;

	*stack = str;

	return (EXIT_SUCCESS);
}

/**
 * check_stack - Checks if a stack_t linked list is in stack or queue mode.
 * @stack: A pointer to the top (stack) or bottom of a stack_t
 *
 * Return: 0, 1, or - 2.
 */
int check_stack(stack_t *stack)
{
	if (stack->n == MSTACK)
		return (MSTACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
