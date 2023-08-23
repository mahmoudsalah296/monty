#include "monty.h"

void set_data(data_t *my_data)
{
	my_data->line = NULL;
	my_data->fd = NULL;
	my_data->container = NULL;
}

void free_all(data_t *my_data)
{
	free(my_data->line);
	fclose(my_data->fd);
	free(my_data->container[0]);
	free(my_data->container[1]);
	free(my_data->container);
}
