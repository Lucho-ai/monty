#include "monty.h"

/**
 * check_num - Verify if a given string is a number
 * @str: input string to check
 * Return: 1 if number, 0 otherwise
 */
int is_number(char *str)
{
	if (!str || !*str)
		return (0);
	if (*str == '-')
	{
		str++;
		if (!*str)
			return (0);
	}
	for (; *str; str++)
		if (*str < '0' || *str > '9')
			return (0);
	return (1);
}
