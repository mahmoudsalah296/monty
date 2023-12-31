#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct data_s - all the program data saved here
 * @fd: file pointer
 * @line: the line to be read from the file
 * @container: where the parsed line is saved
 * @head: head of the stack
 * @i: number of line read from the file
*/
typedef struct data_s
{
	FILE *fd;
	char *line;
	char **container;
	stack_t *head;
	unsigned int i;
} data_t;


extern data_t my_data;


/*data.c*/
void set_data(data_t *my_data);
void free_all(data_t *my_data);
void free_itr(data_t *my_data);

/*parsing.c*/
int _parsing(char **line, char ***container);
int is_spaces(char *line);
int is_comment(char c);

/*_cmd_handlers.c*/
int _getcmd(char **argv, FILE **fd, char **line);

/*check_opcode.c*/
void (*check_opcode(char *opcode))(stack_t **stack, unsigned int line_number);

/*functions.c*/
void push(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
int check_num(char *num);
void pall(stack_t **stack, unsigned int line_number);

/*functions1.c*/
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);


/*functions2.c*/
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);

/*functions3.c*/
void rotr(stack_t **stack, unsigned int line_number);

#endif /* monty_H */
