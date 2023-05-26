#include "monty.h"

/**
 * monty_nop - Does absolutely nothing for the Monty opcode
 * @stack: A pointer to the top node
 * @line_number: The line number of a Monty bytecodes file.
 */
void mnop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
