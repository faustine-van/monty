#include "monty.h"

/**
 * main - monty interpreter read bytecode
 * @ac: number of argument
 * @av: argument passed like file
 * Return: 0 on success
 */
int main(int ac, char *av[])
{
	char *filename = av[1];
	FILE  *file_open;
	stack_t *stack;

	if (ac < 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	check_file_extension(filename);
	file_open = fopen(filename, "r");
	if (!file_open)
	{
		print_malloc_message("Error: Can't open file %s", filename);
	}
	stack = NULL;
	_execute_instruct(file_open, &stack);

	fclose(file_open);
	return (EXIT_SUCCESS);
}
