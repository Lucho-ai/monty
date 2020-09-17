#include "monty.h"
/**
 * _div - Funtionces of the opcode add.
 * @h: Stack.
 * @count: count of the line where the opcode is taken.
 * Return: Void
 */
void _div(stack_t **h, unsigned int count)
{
	stack_t *node;
	int i = 0;

	node = (*h);

	while (node)
	{
		i++;
		node = node->next;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", count);
		exit(EXIT_FAILURE);
	}
	if ((*h)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		exit(EXIT_FAILURE);
	}
	node = (*h)->next;
	(*h)->next->n /= (*h)->n;
	free(*h);
	node->prev = NULL;
	(*h) = node;
}
