#include "monty.h"

/**
 * sub - subtracts the top elementof the stack from the second top element
 * @stack: double pointer to head of stack
 * @line_number: line number of op
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int n;

	if (var.stack_len < 2)
	{
		dprintf(STDOUT_FILENO,
			"L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n -= n;
}
