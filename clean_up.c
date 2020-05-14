#include "monty.h"

/**
 * cleanup - Frees malloc objects and closes the file
 * @stack: Pointer to the stack
 * Return: Nothing
 */
void cleanup(stack_t **stack)
{
	stack_t *ptr = *stack;

	for (; ptr; ptr = *stack)
	{
		*stack = (*stack)->next;
		free(ptr);
	}
	fclose(mem.fs);
	free(mem.line);
}
