#include "monty.h"
/**
 * _add - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	result = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * _nop - nothing happens here
 * @stack: pointer to stack pointer
 * @line_number: line number of the opcode Integer
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
