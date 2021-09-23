#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: double pointer to head of stack
 * @line_number: line to run op
 *
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack)
		*stack = (*stack)-> prev;
}
