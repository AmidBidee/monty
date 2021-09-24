#include "monty.h"
#include <ctype.h>

/**
 * pstr - prints the string starting fromt top of stack, then new line
 * @stack: double pointer to head of stack
 * @line_number: current line of operation
 *
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int ch;

	(void)line_number;

	temp = *stack;
	while (temp != NULL)
	{
		ch = temp->n;
		if (!isascii(ch) || ch == 0)
			break;
		putchar(ch);
		temp = temp->next;
		if (temp == *stack)
			break;
	}
	putchar('\n');
}
