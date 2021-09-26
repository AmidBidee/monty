
#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


extern stack_t *head; /* declaring head of linked list */

/* global variable to hold flag for queue and stack length */
/*extern var_t var;*/

/* file helpers */
void ord_bytecode(char *file_name);
int parse_line(char *line, int line_num);
void check_opcode_func(char *keyword, char *value, int line_num);
stack_t *create_element(char *val, int line_num);
void free_nodes(void);

/* monty functions */
void _push(stack_t **new_node, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_nunber);
void _add(stack_t **stack, unsigned int line_nunber);

/* more functions */
size_t list_len(stack_t *h);

#endif
