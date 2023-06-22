#include "monty.h"

/**
 * dive - opcode div: divide the top two elements of the stack.
 * @top: double pointer to the top of the stack
 * @line_number: the number of a line of the file
 * Return: NOTHING
 */
void dive(stack_t **top, unsigned int line_number)
{
	int div;
	stack_t *tmp_div;

	if (!(*top) || !top || !(*top)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	tmp_div = *top;
	if (tmp_div->n == 0)
	{
		fprintf(stderr, "L%u: division by zero", line_number);
		exit(EXIT_FAILURE);
	}
	div = tmp_div->n / tmp_div->next->n;
	tmp_div->next->n = div;

	*top = tmp_div->next;

	free(tmp_div);
}
/**
 * mul - opcode mul: multiply the top two elements of the stack.
 * @top: double pointer to the top of the stack
 * @line_number: the number of a line of the file
 * Return: NOTHING
 */
void mul(stack_t **top, unsigned int line_number)
{
	int mul;
	stack_t *tmp_mul;

	if (!(*top) || !top || !(*top)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	tmp_mul = *top;

	mul = tmp_mul->next->n * tmp_mul->n;
	tmp_mul->next->n = mul;

	*top = tmp_mul->next;

	free(tmp_mul);
}
/**
 * mod - opcode mod: moduls the top two elements of the stack.
 * @top: double pointer to the top of the stack
 * @line_number: the number of a line of the file
 * Return: NOTHING
 */
void mod(stack_t **top, unsigned int line_number)
{
	int mod;
	stack_t *tmp_mod;

	if (!(*top) || !top || !(*top)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	tmp_mod = *top;
	if (tmp_mod->n == 0)
	{
		fprintf(stderr, "L%u: division by zero", line_number);
		exit(EXIT_FAILURE);
	}
	mod = tmp_mod->n / tmp_mod->next->n;
	tmp_mod->next->n = mod;

	*top = tmp_mod->next;

	free(tmp_mod);
}
