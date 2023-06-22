#include "monty.h"

/**
 * nop - do nothing
 * @top: double pointer to the top of the stack
 * @line_number: the number of a line of the file
 * Return: NOTHING
 */
void nop(stack_t **top, unsigned int line_number)
{
	(void)top;
	(void)(line_number);
}

/**
 * swap - opcode swap: swaps the top two elements of the stack.
 * @top: double pointer to the top of the stack
 * @line_number: the number of a line of the file
 * Return: NOTHING
 */
void swap(stack_t **top, unsigned int line_number)
{
	stack_t *temp;

	if (!(*top) || !(*top)->next)
		print_error(line_number, "can't swap, stack too short");

	temp = (*top)->next;

	(*top)->prev = temp;
	(*top)->next = temp->next;

	temp->prev = NULL;

	if (temp->next)
		temp->next->prev = *top;
	temp->next = *top;
	*top = temp;
}
/**
 * add - opcode add: add the top two elements of the stack.
 * @top: double pointer to the top of the stack
 * @line_number: the number of a line of the file
 * Return: NOTHING
 */
void add(stack_t **top, unsigned int line_number)
{
	int sum = 0;
	stack_t *tmp_add;

	if (!(*top) && !(*top)->next)
		print_error(line_number, "can't add, stack too short");
	tmp_add = *top;

	sum = tmp_add->n + tmp_add->next->n;
	tmp_add->next->n = sum;

	*top = tmp_add->next;

	free(tmp_add);
}
