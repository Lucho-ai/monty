#ifndef _MONTY_H_
#define _MONTY_H_
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global - struc for file, buffer and inter of opcodes.
 * @num: Integers to be used with atoi
 * @buffer: Char pointer to be used as a buffer.
 * @file: Pointer to files with the fopen funtion.
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct global
{
	char *num;
	char *buffer;
	FILE *file;
} ss;

extern ss sup;

void pharser(char *buffer, stack_t **h, unsigned int count);
void get_op_func(stack_t **h, unsigned int count, char *command);
void _push(stack_t **head, unsigned int count);
void free_stack(stack_t *h);
void _add(stack_t **h, unsigned int count);
void _pall(stack_t **h, unsigned int count);
void _pint(stack_t **h, unsigned int count);
void _pop(stack_t **h, unsigned int count);
void _nop(stack_t **h, unsigned int count);
void _swap(stack_t **h, unsigned int count);
void _sub(stack_t **h, unsigned int count);
void _div(stack_t **h, unsigned int count);
void _mul(stack_t **h, unsigned int count);
void _mod(stack_t **h, unsigned int count);

#endif /* _MONTY_H_ */
