#include "monty.h"

memstate_t mem = {0, NULL, NULL, NULL};

/**
 * main - The monty interpreter
 * @ac: number of arguments pass into the monty interpreter
 * @av: the arguments passed into the monty interpreter
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int ac, char **av)
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	mem.fs = fopen(av[1], "r");
	if (!mem.fs)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	parse_commands();
	return (EXIT_SUCCESS);
}
