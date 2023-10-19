#include "monty.h"

/**
 * rotr – function rotates the stack to the bottom
 * @stack: pointer to the head of the stack
 * @line_number: bytecode line number
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last, *second_to_last;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	last = *stack;
	while (last->next != NULL)
		last = last->next;

	second_to_last = last->prev;

	second_to_last->next = NULL;
	last->prev = NULL;

	last->next = *stack;
	(*stack)->prev = last;

	*stack = last;
}
