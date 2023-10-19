#include "monty.h"

/**
 * execute - select correct operation function
 * @token1: first bytecode input
 * Return: pointer to correct operation function
 */

void (*execute(char *token1))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruction_s[] = {
		{"pall", pall},		{"pint", pint},
		{"pop", pop},		{"swap", swap},
		{"add", _add},		{"sub", _sub},
		{"mul", _mul},		{"div", _div},
		{"mod", _mod},		{"pchar", pchar},
		{"pstr", pstr},		{"rotl", rotl},
		{"rotr", rotr},		{"nop", nop},
		{NULL, NULL}};
	int i = 0;

	while (instruction_s[i].f != NULL)
	{
		if (strcmp(token1, instruction_s[i].opcode) == 0)
			return (instruction_s[i].f);
		i++;
	}
	return (NULL);
}

/**
 * check_int - checks if a string represents an integer
 * @n: string to check
 * Return: 0 if a number, -1 if not
 */

int check_int(const char *n)
{
	int i = 0;

	if (n == NULL || *n == '\0')
		return (-1);

	if (n[i] == '-' || n[i] == '+')
		i++;

	for (; n[i] != '\0'; i++)
	{
		if (!isdigit(n[i]))
			return (-1);
	}

	return (0);
}
