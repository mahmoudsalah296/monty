#include "monty.h"
/**
 * set_data - function to initate the program data
 * Return: void
 * @my_data: all the program data
*/
void set_data(data_t *my_data)
{
	my_data->line = NULL;
	my_data->fd = NULL;
	my_data->container = NULL;
	my_data->head = NULL;
	my_data->i = 0;
}


/**
 * set_itr - setting the data for each iteration
 * Return: void
 * @my_data: all the program data
*/
void set_itr(data_t *my_data)
{
	my_data->line = NULL;
	my_data->container = NULL;
}




/**
 * free_itr - function to free some data for each iteration
 * Return: void
 * @my_data: all the program data
*/
void free_itr(data_t *my_data)
{
		free(my_data->line);
		free(my_data->container[0]);
		free(my_data->container[1]);
		free(my_data->container);
		set_itr(my_data);

}


/**
 * free_all - function to free all the program data
 * Return: void
 * @my_data: all the program data
*/
void free_all(data_t *my_data)
{
	stack_t *temp = my_data->head;

	if (my_data->line != NULL)
		free(my_data->line);

	fclose(my_data->fd);
	if (my_data->container != NULL)
	{
		free(my_data->container[0]);
		free(my_data->container[1]);
		free(my_data->container);
	}

	while (temp != NULL)
	{
		my_data->head = my_data->head->next;
		free(temp);
		temp = my_data->head;
	}
}
