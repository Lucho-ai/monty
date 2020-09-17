#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"
/**
 * _nop - The opcode that doesn’t do anything.
 * @h: The stack pointer..
 * @count: counter of the line
 * Return: Void.
 */
void _nop(stack_t **h, unsigned int count)
{
	(void) h;
	(void) count;
}
