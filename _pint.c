#include "monty.h"

/**
 * pint -  prints the value at the top of the stack
 * @h: head of list
 * @line_number: bytecode line number
 */

void pint(stack_t **h, unsigned int line_number)
{
	int top_val;

	if (!h || !*h)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_list(h);
		exit(EXIT_FAILURE);
	}

	top_val = (*h)->n;
	printf("%d\n", top_val);
}
