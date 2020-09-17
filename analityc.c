#include "monty.h"
/**
 * pharser - pharser to the buffer the comes from opcode-file.
 * @buffer: The buffer with the imformation.
 * @h: The stack
 * @count: Count of the line where the opcode is taken.
 * Return: Void.
 */

void pharser(char *buffer, stack_t **h, unsigned int count)
{
	char *str, *token;

	str = strtok(buffer, " \n\t");
	token = strtok(NULL, " \n\t");
	sup.num = token;
	if (str && str[0] != '#')
		get_op_func(h, count, str);
}
