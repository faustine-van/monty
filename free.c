#include "monty.h"

/**
 * free_t - free stack
 * @top: double pointer to the top of the stack
 * Return: NOTHING
 */
void free_t(stack_t *top)
{
	stack_t *temp;

	while (temp != NULL)
	{
		temp = top;
		top = top->next;
		free(temp);
		top = temp;
	}
}
