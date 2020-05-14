#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
 * struct memstate_s - input command
 * @mode: queue or stack mode
 * @arg: argument for the opcode
 * @fs: file stream pointer
 * @line: buffer used by getline
 *
 * Description: temp struct used to hold global vars. These vars need to be
 * accessible in other functions due to restrictions placed on function
 * prototypes.
 */
typedef struct memstate_s
{
	int mode;
	char *arg;
	FILE *fs;
	char *line;
} memstate_t;

extern memstate_t mem;

/* monty.c */
void p_command(void);
void ej_opcode(char *opc, stack_t **stack, unsigned int line_num);


void cleanup(stack_t **stack);
int checknum(char *str);
void add_s(stack_t **stack, stack_t *new);
void add_q(stack_t **stack, stack_t *new);


void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

#endif /* _MONTY_H_ */
