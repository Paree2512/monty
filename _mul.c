#include "monty.h"

/**
 * _mul – function multiplies the second top element of the stack with
 * the top element of the stack
 * @h: top of list
 * @line_number: line of command
 */

void _mul(stack_t **h, unsigned int line_number)
{
	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_list(h);
		exit(EXIT_FAILURE);
	}
	(*h)->next->n *= (*h)->n;
	(*h) = (*h)->next;
	free((*h)->prev);
	(*h)->prev = NULL;
}
