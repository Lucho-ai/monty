#include "monty.h"
/**
 * _swap - Funtion that swap the last valeus.
 * @h: Stack.
 * @count: count of the line where the opcode is taken.
 * Return: Void
 */
void _swap(stack_t **h, unsigned int count)
{
	stack_t *two;
	int i = 0, temp;

	two = (*h);

	while (two)
	{
		i++;
		two = two->next;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		exit(EXIT_FAILURE);
	}

	temp = (*h)->n;
	(*h)->n = (*h)->next->n;
	(*h)->next->n = temp;
}
