#include "monty.h"

/**
 * mul - multiplies the second top element of the stack with the top
 * @stack: double pointer to head of the stack
 * @line_number: current line of op
 *
 * Return: void
 */
void mul(stack_t *stack, unsigned int line_number)
{
	int n;

	if (vat.stack_len < 2)
	{
		dprintf(STDOUT_FILENO,
			"L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n *= n;
}
