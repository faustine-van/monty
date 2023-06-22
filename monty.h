#ifndef _MONTY_H
#define _MONTY_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

#include <stdbool.h>
#include <string.h>

#define DELIMITERS "\n \r\t"
#define LINE_CAPACITY  128
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
int check_file_extension(const char *file);
void push(stack_t **top, unsigned int line_number);
void pop(stack_t **top, unsigned int line_number);
void pall(stack_t **top, unsigned int line_number);
void nop(stack_t **top, unsigned int line_number);
void pint(stack_t **top, unsigned int line_number);
void add(stack_t **top, unsigned int line_number);
void sub(stack_t **top, unsigned int line_number);
void swap(stack_t **top, unsigned int line_number);
void mod(stack_t **top, unsigned int line_number);
void mul(stack_t **top, unsigned int line_number);
void print_error(unsigned int line_number, const char *format, ...);
void print_malloc_message(const char *format, ...);
void execute_instruction(stack_t **stack, char *opco, unsigned int line_number);
void _execute_instruct(FILE *file, stack_t **stack);
#endif
