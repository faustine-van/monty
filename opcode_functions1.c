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
	{
		fprintf(stderr, "L%u: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

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
	int sum;
	stack_t *tmp_add;

	if (!(*top) || !(*top)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	tmp_add = *top;

	sum = tmp_add->n + tmp_add->next->n;
	tmp_add->next->n = sum;

	*top = tmp_add->next;

	free(tmp_add);
}
/**
 * sub - opcode sub: substract the top two elements of the stack.
 * @top: double pointer to the top of the stack
 * @line_number: the number of a line of the file
 * Return: NOTHING
 */
void sub(stack_t **top, unsigned int line_number)
{
	int sub;
	stack_t *tmp_sub;

	if (!(*top) || !top || !(*top)->next)
		print_error(line_number, "can't sub, stack too short");
	tmp_sub = *top;

	sub = tmp_sub->next->n - tmp_sub->n;
	tmp_sub->next->n = sub;

	*top = tmp_sub->next;

	free(tmp_sub);
}
