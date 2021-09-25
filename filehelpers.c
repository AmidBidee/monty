#include "monty.h"

/**
 * ord_bytecode - open and read bytecode
 * @file_name: bytcode file
 * Return: void
 */

void ord_bytecode(char *file_name)
{
	FILE *bytecode_s;
	char *line = NULL;
	size_t len = 0;
	int line_num, format;

	bytecode_s = fopen(file_name, "r");
	if (bytecode_s == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	for (line_num = 1; getline(&line, &len, bytecode_s) != -1; line_num++)
	{
		format = parse_line(line, line_num);
	}

	(void) format;
	free(line);
	fclose(bytecode_s);
}

/**
 * parse_line - parses file line
 * @line: line pointer
 * @line_num: line number
 * Return: 0 or 1
 */

int parse_line(char *line, int line_num)
{
	int format = 0;
	char *delim = "\n ";
	char *keyword, *value;

	if (line == NULL)
	{
		fprintf(stderr, "Error: Can't read line %i\n", line_num);
		exit(EXIT_FAILURE);
	}

	keyword = strtok(line, delim);
	if (keyword == NULL)
		return (format);
	value = strtok(NULL, delim);

	check_opcode_func(keyword, value, line_num);

	return (format);
}

/**
 * check_opcode_func - checks the keyword opcode and gets its func
 * @keyword: pointer to keyword
 * @value: string value
 * @line_num: line_number
 */
void check_opcode_func(char *keyword, char *value, int line_num)
{
	int i = 0, stat_code = 1;
	stack_t *elem;

	instruction_t opcodes_func[] = {
		{"push", &_push},
		{"pall", &_pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		/*{"nop", _nop},*/
		{NULL, NULL}
	};

	while (opcodes_func[i].opcode != NULL)
	{
		if (strcmp(opcodes_func[i].opcode, keyword) == 0)
		{
			if (strcmp(opcodes_func[i].opcode, "push") == 0)
			{
				elem = create_element(value, line_num);
				opcodes_func[i].f(&elem, line_num);
			}
			else
				opcodes_func[i].f(&head, line_num);
			stat_code = 0;
		}
		i++;
	}

	if (stat_code == 1)
	{
		fprintf(stderr, "L%i: unknown instruction %s\n", line_num, keyword);
		exit(EXIT_FAILURE);
	}
}

