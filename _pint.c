#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"
/**
 * _pint - function that prints the last element of a list
 * @h : const - list_t
 * @count: count.
 * Return: the number of notes.
 */
void _pint(stack_t **h, unsigned int count)
{
	stack_t *temp;

	temp = *h;
	if (temp == NULL)
	{
		dprintf(STDERR_FILENO,
			"L%u: can't pint, stack empty\n", count);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", temp->n);
}
