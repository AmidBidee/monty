#include "monty.h"

/**
 * _push - push a new_node(elem) to stack
 * @new_node: node to push
 * @line_number: line_number
 */

void _push(stack_t **new_node, unsigned int line_number)
{
	(void) line_number;

	(*new_node)->next = head;
	(*new_node)->prev = NULL;

	if (head != NULL)
		head->prev = (*new_node);
	head = (*new_node);
}

/**
 * _pall - prints the all values in stack
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
	{
		fprintf(stderr, "L%i: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
