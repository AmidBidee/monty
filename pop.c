#include "monty.h"

/**
 * pop - removes top element of stack
 * @stack: double pointer to head of stack
 * @line_number: line to execute
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *pop1 = *stack;

	if (var.stack_len == 0)
	{
		dprintf(STDOUT_FILENO,
			"L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->prev = (*stack)->prev;
	(*stack)->prev->next = (*stack)->next;
	if (var.stack_len != 1)
		*stack = (*stack)->next;
	else
		*stack = NULL;
	free(pop1);
	var.stack_len--;
}
