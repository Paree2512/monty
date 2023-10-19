#include "monty.h"

/**
 * pall - prints all the values on the stack starting
 * from the top
 * @h: head of list
 * @line_number: bytecode line number
 */

void pall(stack_t **h, unsigned int line_number)
{
	stack_t *node = NULL;

	if (!h || !*h)
		return;

	(void) line_number;
	node = *h;
	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
