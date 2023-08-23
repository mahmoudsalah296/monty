#include "monty.h"


/**
 * swap - funtion to swap first 2 elements of stack
 * Return: void
 * @stack: stack header
 * @line_number: the current number read from the file
*/
void swap(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n"
				, my_data.i);
		free_all(&my_data);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}



/**
 * add - funtion to add first 2 elements of stack
 * Return: void
 * @stack: stack header
 * @line_number: the current number read from the file
*/
void add(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp;
	int temp1;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n"
				, my_data.i);
		free_all(&my_data);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	temp1 = (*stack)->n;
	(*stack)->next->n += temp1;
	*stack = (*stack)->next;
	free(temp);
}




/**
 * nop - funtion to do nothing
 * Return: void
 * @stack: stack header
 * @line_number: the current number read from the file
*/
void nop(__attribute__((unused))stack_t **stack,
		__attribute__((unused))unsigned int line_number)
{}



/**
 * sub - funtion to substract first 2 elements of stack
 * Return: void
 * @stack: stack header
 * @line_number: the current number read from the file
*/
void sub(stack_t **stack, __attribute((unused))unsigned int line_number)
{
	stack_t *temp;
	int temp1;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n"
				, my_data.i);
		free_all(&my_data);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	temp1 = (*stack)->n;
	(*stack)->next->n -= temp1;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * _div - funtion to div first 2 elements of stack
 * Return: void
 * @stack: stack header
 * @line_number: the current number read from the file
*/
void _div(stack_t **stack, __attribute((unused))unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n"
				, my_data.i);
		free_all(&my_data);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero"
				, my_data.i);
		free_all(&my_data);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n /= (*stack)->n;
	*stack = (*stack)->next;
	free(temp);
}
