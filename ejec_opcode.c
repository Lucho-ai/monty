#include "monty.h"

/**
 * eject_opcode - Runs the given opcode
 * @opc: opcode to run
 * @stack: pointer to stack
 * @line_num: line number of the opcode
 * Return: nothing
 */
void ej_opcode(char *opc, stack_t **stack, unsigned int line_num)
{
	int i = 0;
	instruction_t ins[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divm},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stackm},
		{"queue", queue},
		{NULL, NULL}
	};
	for (i = 0; ins[i].opcode; i++)
		if (!strcmp(opc, ins[i].opcode))
		{
			free(opc);
			ins[i].f(stack, line_num);
			break;
		}
	if (!ins[i].opcode)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_num, opc);
		free(opc);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
}
