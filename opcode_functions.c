#include "monty.h"

/**
 * push - pushes new node
 * @top: double pointer to the top of the stack
 * @line_number: the number of a line of the file
 * Return: NOTHING
 */
void push(stack_t **top, unsigned int line_number)
{
	stack_t *newNode;
	char *arg;

	arg = strtok(NULL, DELIMITERS);
	if (arg == NULL)
	{
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = atoi(arg);
	newNode->prev = NULL;
	newNode->next = *top;

	if (*top != NULL)
		(*top)->prev = newNode;

	*top = newNode;
}

/**
 * pop - remove top element from stack
 * @top: double pointer to the top of the stack
 * @line_number: the number of a line of the file
 * Return: NOTHING
 */
void pop(stack_t **top, unsigned int line_number)
{
	stack_t *temp;

	if (*top == NULL)
		print_error(line_number, "can't pop an empty stack");
	temp = *top;
	*top = (*top)->next;
	free(temp);
}
/**
 * pall - prints all the values on the stack, starting from the top
 * @top: double pointer to the top of the stack
 * @line_number: the number of a line of the file
 * Return: NOTHING
 */
void pall(stack_t **top, unsigned int line_number)
{
	stack_t *temp = *top;
	(void)line_number;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - prints the value at the top of the stack, followed by a new line
 * @top: double pointer to the top of the stack
 * @line_number: the number of a line of the file
 * Return: NOTHING
 */
void pint(stack_t **top, unsigned int line_number)
{
	if (*top == NULL)
		print_error(line_number, "can't pint, stack empty");
	else
		printf("%d\n", (*top)->n);
}
