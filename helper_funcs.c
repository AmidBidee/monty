#include "monty.h"
/**
 * list_len - return length of list
 * @h: pointer to list
 * Return: list lenght
 */
size_t list_len(stack_t *h)
{
	int len = 0;

	for (; h != NULL; h = h->next)
		len++;
	return (len);
}
