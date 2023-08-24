#include "monty.h"

data_t my_data = {NULL, NULL, NULL, NULL, 0};

/**
 * main - program start point
 * Return: 0 on success , 1 otherwise
 * @argc: number of arguments passed to the program
 * @argv: arguments passed to the program
*/
int main(int argc, char **argv)
{
	void (*op_func)(stack_t**, unsigned int);

	if (argc < 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	set_data(&my_data);
	while (_getcmd(argv, &(my_data.fd), &(my_data.line)))
	{
		my_data.i++;

		if (is_spaces(my_data.line))
		{
			free(my_data.line);
			continue;
		}
		if (!_parsing(&(my_data.line), &(my_data.container)))
		{
		free_all(&my_data);
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
		}
		op_func = check_opcode(my_data.container[0]);

		if (op_func == NULL)
		{
			dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", my_data.i
					, my_data.container[0]);
			free_all(&my_data);
			exit(EXIT_FAILURE);
		}
		op_func(&(my_data.head), my_data.i);
		free_itr(&my_data);
	}
	return (0);
}
