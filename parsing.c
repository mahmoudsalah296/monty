#include "monty.h"

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
