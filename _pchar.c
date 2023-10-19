#include "monty.h"

/**
 * pchar - prints the char at the top of the stack as ASCII
 * @h: pointer to the head of the stack
 * @line_number: bytecode line number
 */

void pchar(stack_t **h, unsigned int line_number)
{
	int value;

	if (!h || !*h)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_list(h);
		exit(EXIT_FAILURE);
	}
	value = (*h)->n;

	if (value >= 0 && value <= 127)
		printf("%c\n", value);
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}
