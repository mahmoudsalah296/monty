#include "monty.h"


/**
 * mul - funtion to mul first 2 elements of stack
 * Return: void
 * @stack: stack header
 * @line_number: the current number read from the file
*/

void mul(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n"
				, line_number);
		free_all(&my_data);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n *= (*stack)->n;
	*stack = (*stack)->next;
	free(temp);
}


/**
 * mod - funtion to mod first 2 elements of stack
 * Return: void
 * @stack: stack header
 * @line_number: the current number read from the file
*/

void mod(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n"
				, line_number);
		free_all(&my_data);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n"
				, line_number);
		free_all(&my_data);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n %= (*stack)->n;
	*stack = (*stack)->next;
	free(temp);

}
