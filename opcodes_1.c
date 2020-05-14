#include "monty.h"

/**
 * push - adds a new value into the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;

	if (!is_number(mem.arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
	new->n = atoi(mem.arg);
	new->prev = NULL;
	new->next = NULL;
	if (mem.mode)
		add_q(stack, new);
	else
		add_s(stack, new);
}

/**
 * pall - prints the entire stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *walk = *stack;

	(void)line_number;
	for (; walk; walk = walk->next)
		printf("%d\n", walk->n);
}

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	free(ptr);
	if (*stack)
		(*stack)->prev = NULL;
}

/**
 * swap - swaps the top two elements
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int tmp = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			line_number);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}
