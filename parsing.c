#include "monty.h"

/**
 * is_spaces - checks if a line is empty
 * Return: 1 if the line is empty and 0 otherwise
 * @line: the string line to check
*/

int is_spaces(char *line)
{
	int i = 0;

	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
		{
			return (0);
		}
		i++;
	}

	return (1);
}

/**
 * _parsing - function to parse a line into chunks
 * Return: 1 on success or 0 otherwise
 * @line: the line to be parsed
 * @container: where chunks are saved
*/
int _parsing(char **line, char ***container)
{
	char *temp;

	*container = (char **) malloc(sizeof(char *) * 2);

	if (*container == NULL)
		return (0);

	temp = strtok(*line, " \t\n");

	if (temp != NULL)
		(*container)[0] = strdup(temp);

	if ((*container)[0] == NULL)
		return (0);

	temp = strtok(NULL, " \t\n");
	if (temp != NULL)
		(*container)[1] = strdup(temp);
	else
		(*container)[1] = NULL;

	return (1);
}
