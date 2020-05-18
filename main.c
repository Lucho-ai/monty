#include "monty.h"
ss sup = {NULL, NULL, NULL};
/**
 * main - Main funtion.
 * @argc: Argc.
 * @argv: Argv.
 * Return: 0.
 */
int main(int argc, char *argv[])
{
	ssize_t chr;
	size_t bsize = 32;
	unsigned int count = 0;
	stack_t *head = NULL;

	if (argc != 2)
	{dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	sup.file = fopen(argv[1], "r");
	if (!sup.file)
	{dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((chr = getline(&sup.buffer, &bsize, sup.file)) != EOF)
	{
		count++;
		pharser(sup.buffer, &head, count);
	}
	free_stack(head);
	exit(EXIT_SUCCESS);
}
