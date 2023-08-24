#include "monty.h"
/**
 * rotr - rotates the stack to the bottom.
 * @stack: head of the stack
 * @line_number: the current number read from the file
 * Return: nothing
*/
void rotr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
		return;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = *stack;
	if (tmp->prev)
	{
		tmp->prev->next = NULL;
		tmp->prev = NULL;
	}
	*stack = tmp;
}
