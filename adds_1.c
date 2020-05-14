#include "monty.h"

/**
 * add_s - Adds to the data struct as a stack
 * @stack: ptr to the stack
 * @new: ptr to the new node
 * Return: nothing
 */
void add_s(stack_t **stack, stack_t *new)
{
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * add_q - Adds to the data struct as a queue
 * @stack: ptr to the stack
 * @new: ptr to the new node
 * Return: nothing
 */
void add_q(stack_t **stack, stack_t *new)
{
	stack_t *ptr = *stack;

	new->prev = NULL;
	new->next = NULL;
	if (!*stack)
		*stack = new;
	else
	{
		for (; ptr->next; ptr = ptr->next)
			;
		new->prev = ptr;
		ptr->next = new;
	}
}
