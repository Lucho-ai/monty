#include "monty.h"
/**
 * up_func - Funtion.
 * @command: command.
 * @h: h.
 * @count: count.
 */
void up_func(stack_t **h, unsigned int count, char *command)
{
	int i = 0;

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div},
		{"mul", mul},
		{"mod", mod},
		{NULL, NULL}
	};

	while (op[i].opcode)
	{
		if ((strcmp(op[i].opcode, command)) == 0)
		{
			op[i].f(h, count);
			break;
		}
		i++;
	}
	if (op[i].f == NULL)
	{dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", count, command);
		free_stack((*h));
		exit(EXIT_FAILURE);
	}

}
