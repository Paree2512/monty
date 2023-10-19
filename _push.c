#include "monty.h"

/**
 * push – function pushes an element to the stack
 * @h: head of linked list
 * @line_number: bytecode line number
 * @n: integer
 */

void push(stack_t **h, unsigned int line_number, const char *n)
{
	if (!h)
		return;
	if (check_int(n) == -1)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_list(h);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (add_node(h, atoi(n)) == -1)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free_list(h);
			exit(EXIT_FAILURE);
		}
	}
}
