#include "monty.h"


/**
 * check_num - function to check if the string is valid to be converted
 * Return: the number converted
 * @num: the string to be checked
*/
int check_num(char *num)
{
	int i = 0;
	int length;

	if (num == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push\n", my_data.i);
		free_all(&my_data);
		exit(EXIT_FAILURE);
	}
	length = strlen(num);

	if (num[0] == '-')
		i++;

	for (; i < length; i++)
	{
		if ((num[i] < '0') || (num[i] > '9'))
		{
			dprintf(STDERR_FILENO, "L%u: usage: push\n", my_data.i);
			free_all(&my_data);
			exit(EXIT_FAILURE);
		}
	}
	return (atoi(num));
}



/**
 * push - function to push elemnts in stack
 * Return: void
 * @stack: the stack header
 * @line_number: current line number of file stream
*/
void push(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *new;
	int number = check_num(my_data.container[1]);

	new = (stack_t *) malloc(sizeof(stack_t));

	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_all(&my_data);
		exit(EXIT_FAILURE);
	}
	new->n = number;
	if (*stack != NULL)
	{
		(*stack)->prev = new;
	}
	new->next = *stack;
	new->prev = NULL;
	*stack = new;
}



/**
 * pall - function to print elemnts in stack
 * Return: void
 * @stack: the stack header
 * @line_number: current line number of file stream
*/
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}


/**
 * pint - function to print the stack top
 * Return: void
 * @stack: the stack header
 * @line_number: current line number of file stream
*/
void pint(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{	
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n",
				my_data.i);
		free_all(&my_data);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}



/**
 * pop - function to pop the stack top
 * Return: void
 * @stack: the stack header
 * @line_number: current line number of file stream
*/
void pop(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
        {
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n",
				my_data.i);
		free_all(&my_data);
		exit(EXIT_FAILURE);
        }

	temp = *stack;
	*stack = (*stack)->next;

	free(temp);
}
