#include "monty.h"

/**
 * p_command - Parses the open file and executes the commands
 * Return: nothing
 */
void parse_commands(void)
{
	char *opc = NULL;
	size_t size = 0, line_num = 1;
	ssize_t number_read = 0;
	stack_t *stack = NULL;

	while (1)
	{
		number_read = getline(&mem.line, &size, mem.fs);
		if (number_read == -1)
			break;
		opc = strtok(mem.line, " \n\t");
		if (!opc || opc[0] == '#')
			opc = strdup("nop");
		else
			opc = strdup(opc);
		mem.arg = strtok(NULL, " \n\t");
		run_opcode(opc, &stack, line_num);
		line_num++;
	};
	cleanup(&stack);
}
