#include "monty.h"
/**
 * check_file_extension - check if file is monty file
 * @file: file to be checked
 * Return: o for success
 */

int check_file_extension(const char *file)
{
	const char *extension = strrchr(file, '.');

	if (!extension || strcmp(extension, ".m") != 0)
	{
		return (1);
	}
	return (0);
}
