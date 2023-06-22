#include "monty.h"

/**
 * print_error - print error message
 * @format: any format
 * @line_number: each line number of file
 * Return: NOTHING
 */
void print_error(unsigned int line_number, const char *format, ...)
{
	va_list args;

	fprintf(stderr, "L%u: ", line_number);

	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);

	fprintf(stderr, "\n");
	exit(EXIT_FAILURE);
}

/**
 * print_malloc_message - print error message for malloc failed
 * @format: any format
 * Return: NOTHING
 */
void print_malloc_message(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);

	fprintf(stderr, "\n");
	exit(EXIT_FAILURE);
}
