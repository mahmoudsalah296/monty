#include "monty.h"

int _parsing(char **line, char ***container)
{
	char *temp;

	*container =(char **) malloc(sizeof(char *) * 2);

	if (*container == NULL)
		return (0);
	temp = strtok(*line, " ");
	(*container)[0] = strdup(temp);

	if ((*container)[0] == NULL)
		return (0);

	temp = strtok(NULL, " \n");
	(*container)[1] = strdup(temp);

	if ((*container)[1] == NULL)
		return (0);
	return (1);
}
