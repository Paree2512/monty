#include "monty.h"

/**
 * pstr – function prints top nodes in stack as asci and
 * stops if at end of stack
 * @h: pointer to the head of the stack
 * @line_number: bytecode line number
 */

void pstr(stack_t **h, unsigned int line_number)
{
	stack_t *current = *h;

	if (!h || !*h)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_list(h);
		exit(EXIT_FAILURE);
	}

	while ((current != NULL) && (current->n != 0) &&
			(current->n >= 0) && (current->n <= 127))
	{
		putchar((current)->n);
		current = current->next;
	}
	printf("\n");
}
