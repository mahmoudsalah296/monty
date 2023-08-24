#include "monty.h"
/**
 * check_opcode - function to check if the opcode is valid
 * Return: the function pointer matching the opcode
 * @opcode: the string holding the opcode
*/

void (*check_opcode(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t arr[] = {
			{"pall", pall},
			{"push", push},
			{"pint", pint},
			{"pop", pop},
			{"swap", swap},
			{"add", add},
			{"nop", nop},
			{"sub", sub},
			{"div", _div},
			{"mul", mul},
			{"mod", mod},
			{"pchar", pchar},
			{"pstr", pstr},
			{"rotl", rotl},
			{"rotr", rotr},
			{NULL, NULL}};

	for (; arr[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, arr[i].opcode) == 0)
		{
			return (arr[i].f);
		}
	}
	return (NULL);
}
