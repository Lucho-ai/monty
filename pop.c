#include "monty.h"
/**
 * _pop - Funtionces of the opcode pop.
 * @h: Stack.
 * @count: count of the line where the opcode is taken.
 * Return: Void.
 */
void _pop(stack_t **h, unsigned int count)
{
	stack_t *temp;

	temp = *h;
	if (temp == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", count);
		exit(EXIT_FAILURE);
	}
	*h = temp->next;
	if (temp->next)
		temp->next->prev = NULL;
	free(temp);
}
