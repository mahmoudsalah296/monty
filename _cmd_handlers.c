#include "monty.h"

int _getcmd(char **argv, FILE **fd, __attribute__((unused))char **line)
{
	int nread;
	size_t n = 0;

	if (*fd == NULL)
	{
		printf("fd is NULL\n");
		*fd = fopen(argv[1], "r");

		if (*fd == NULL)
		{
			printf("fopne failed\n");
			dprintf(STDERR_FILENO, 
			"Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		else
			printf("fopen success\n");
	}
	*line = NULL;
	nread = getline(line, &n, *fd);
	if (nread == -1)
	{
		fclose(*fd);
		free(*line);
		*line = NULL;
		*fd = NULL;
		return (0);
	}
	return (nread);
}
