#include "monty.h"


int main(int argc, char **argv)
{
	data_t my_data;

	if (argc < 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	set_data(&my_data);

	
	{
	if (_getcmd(argv, &(my_data.fd), &(my_data.line)))
	{
		if (!_parsing(&(my_data.line), &(my_data.container)))
		{
		free_all(&my_data);
		dprintf(STDERR_FILENO, "Error: malloc failed");
		exit(EXIT_FAILURE);
		}
		printf("%s\n", my_data.container[0]);

	}
	else
		printf("eof\n");
	}
	free_all(&my_data);
	return (0);
}
