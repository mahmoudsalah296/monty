#include "monty.h"
/**
 * _getcmd - function to obtain a line from the file
 * Return: number of read chars or 0 if failed
 * @argv: the arguments passes to the program
 * @fd: file pointer
 * @line: the line read from the file
*/
int _getcmd(char **argv, FILE **fd, char **line)
{
	int nread;
	size_t n = 0;

	if (*fd == NULL)
	{
		*fd = fopen(argv[1], "r");

		if (*fd == NULL)
		{
			dprintf(STDERR_FILENO,
			"Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
	}
	*line = NULL;
	nread = getline(line, &n, *fd);
	if (nread == -1)
	{
		free_all(&my_data);
		return (0);
	}
	return (nread);
}
