#include "monty.h"
/**
 * push - pushes an element to a stack
 * @head: pointer to top element of the stack
 * @n: element to be added
*/
void push(stack_t **head, int n)
{
	stack_t *node = malloc(sizeof(stack_t));

	if (node == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	if (*head == NULL)
	{
		*head = node;
	}
	else
	{
		node->next = *head;
		(*head)->prev = node;
		*head = node;
	}
}
/**
 * pall - prints all the values on the stack
 * @head: pointer to top element of the stack
*/
void pall(stack_t *head)
{
	stack_t *current = (stack_t *)head;

	if (head == NULL)
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
