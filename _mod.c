#include "monty.h"

/**
 * _mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @h: top of list
 * @line_number: line of command
 */

void _mod(stack_t **h, unsigned int line_number)
{
	if (h == NULL || *h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_list(h);
		exit(EXIT_FAILURE);
	}
	if ((*h)->n == 0 || (*h)->next->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_list(h);
		exit(EXIT_FAILURE);
	}
	(*h)->next->n %= (*h)->n;
	(*h) = (*h)->next;
	free((*h)->prev);
	(*h)->prev = NULL;
}
