#include "monty.h"

/**
 * add_node – function adds node to linked list
 * @h: pointer to head of the linked list
 * @n: node data
 * Return: 0 if success, -1 if failed
 */

int add_node(stack_t **h, int n)
{
	stack_t *new_node;

	if (!h)
		return (-1);

	new_node = malloc(sizeof(struct stack_s));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (-1);
	}
	new_node->n = n;

	if (*h == NULL)
	{
		*h = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	else
	{
		new_node->next = *h;
		(*h)->prev = new_node;
		*h = new_node;
	}
	return (0);
}

/**
 * delete_node – function deletes node of linked list
 * @h: pointer to head of the linked list
 */

void delete_node(stack_t **h)
{
	stack_t *del = NULL;

	del = *h;
	if ((*h)->next == NULL)
	{
		*h = NULL;
		free(del);
	}
	else
	{
		*h = (*h)->next;
		(*h)->prev = NULL;
		free(del);
	}
}

/**
 * free_list - frees a doubly linked list with only integer data
 * @h: pointer to head of list
 */

void free_list(stack_t **h)
{
	if (!h)
		return;

	while (*h && (*h)->next)
	{
		*h = (*h)->next;
		free((*h)->prev);
	}
	free(*h);
}
