#include "monty.h"
/**
 *free_stack - Funtion that frees a list.
 * @h: Head of the list.
 * Return: Void.
 */
void free_stack(stack_t *h)
{
	stack_t *head;

	while (h != NULL)
	{
		head = h->next;
		free(h);
		h = head;
	}
	fclose(sup.file);
	free(sup.buffer);
}
