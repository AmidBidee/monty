#include "monty.h"

/**
 * pall - prints all the values on stack starting form top
 * @stack: double pointer to head of stack
 * @line_number: line number executed
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	(void)(line_number);

	head = *stack;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
		if (head == *stack)
		{
			return;
		}
	}
}
