#include "monty.h"
/**
 * _execute_instruct - execute line
 * @stack: pointer to the top stack
 * @file: file to be used
 */
void _execute_instruct(FILE *file, stack_t **stack)
{
	char *opco, *line = NULL;
	unsigned int line_number = 0;
	int len, a, found;

	instruction_t set_op[] = { {"push", push}, {"pall", pall}, {"pop", pop},
		{"pint", pint},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{NULL, NULL}
	};

	line = malloc(LINE_CAPACITY * sizeof(char));
	if (!line)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	while (fgets(line, LINE_CAPACITY, file))
	{
		line_number++;
		len = strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		opco = strtok(line, DELIMITERS);
		while (opco)
		{
			found = 0;
			for (a = 0; set_op[a].opcode; a++)
			{
				if (strcmp(set_op[a].opcode, opco) == 0)
				{
					set_op[a].f(stack, line_number);
					found = 1;
					break;
				}
			}
		if (!found && strlen(opco) != 0 && opco[0] != '#')
			print_error(line_number, "unknown instruction %s", opco);
		opco = strtok(NULL, DELIMITERS);
		}
	}
	free(line); /* Free the allocated memory for line*/
}
