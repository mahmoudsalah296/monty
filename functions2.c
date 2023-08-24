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

/**
 * pchar - print ascii representation of first number of stack
 * @stack: head of the stack
 * @line_number: the current number read from the file
 * Return: nothing
*/
void pchar(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n",
				my_data.i);
		free_all(&my_data);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n"
				, my_data.i);
		free_all(&my_data);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: head of the stack
 * @line_number: the current number read from the file
 * Return: nothing
*/
void pstr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *tmp = *stack;

	while (tmp)
	{
		if (tmp->n == 0 || tmp->n < 0 || tmp->n > 127)
			break;
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl - otates the stack to the top.
 * @stack: head of the stack
 * @line_number: the current number read from the file
 * Return: nothing
*/
void rotl(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *tmp, *tmp2;

	if (*stack == NULL)
	{
		free_all(&my_data);
		return;
	}
	tmp = *stack;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp2 = (*stack)->next;
	tmp->next = *stack;
	(*stack)->next->prev = NULL;
	(*stack)->next = NULL;
	(*stack)->prev = tmp;
	if (tmp2 != NULL)
		*stack = tmp2;
}
