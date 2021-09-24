#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: argument count
 * @argv: arguments array
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	ord_bytecode(argv[1]);
	free_nodes();
	return (0);
}

/**
 * create_element - creates a node element
 * @val: character value
 * @line_num: line_number
 * Return: the node element just created
 */
stack_t *create_element(char *val, int line_num)
{
	int i, value;
	stack_t *node = malloc(sizeof(stack_t));

	if (val == NULL)
	{
		fprintf(stderr, "L%i: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	for (i = 0; val[i] != '\0'; i++)
	{
		if (isdigit(val[i]) == 0)
		{
			fprintf(stderr, "L%i: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
	}

	value = atoi(val);

	if (node == NULL)
	{
		printf("can't malloc");
		exit(EXIT_FAILURE);
	}
	node->prev = NULL;
	node->next = NULL;
	node->n = value;

	return (node);
}

/**
 * free_nodes - Frees nodes in the stack.
 */
void free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

