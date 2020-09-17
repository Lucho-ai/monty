#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"
/**
 * _push - Funtionces of the opcode push.
 * @h: Stack.
 * @count: count of the line where the opcode is taken.
 * Return: Void
 */
void _push(stack_t **h, unsigned int count)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{dprintf(STDERR_FILENO, "USAGE: monty file\n");
		free_stack(new);
		exit(EXIT_FAILURE); }

	if (!sup.num && sup.num != 0)
	{dprintf(STDERR_FILENO, "L%u: usage: push integer\n", count);
		free_stack((*h));
		free(new);
		exit(EXIT_FAILURE);
	}

	if (sup.num)
	{
		new->n = atoi(sup.num);
		new->next = *h;
		new->prev = NULL;
		if (*h)
			(*h)->prev = new;
		*h = new;
	}
	else
	{dprintf(STDERR_FILENO, "L%u: usage: push integer\n", count);
		free_stack((*h));
		free(new);
		exit(EXIT_FAILURE); }
}
