#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#define MSTACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

extern char **toks;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int execute_monty(FILE *filed);
void mpush(stack_t **stack, unsigned int line_number);
void mpall(stack_t **stack, unsigned int line_number);
int unknown_error_msg(char *opcode, unsigned int line_number);
int invalid_error_msg(unsigned int line_number);
int merror(void);
void set_error(int err_code);
int usage_error_msg(void);
int open_error_msg(char *filename);
void madd(stack_t **stack, unsigned int line_number);
void mnop(stack_t **stack, unsigned int line_number);
void mpint(stack_t **stack, unsigned int line_number);
int print_error(unsigned int line_number);
void mpop(stack_t **stack, unsigned int line_number);
int pop_error_msg(unsigned int line_number);
void empty_stack(stack_t **stack);
int start_stack(stack_t **stack);
int check_stack(stack_t *stack);
char *get(int number);
unsigned int abs_val(int i);
int buff_len(unsigned int number, unsigned int b);
void full_buffer(unsigned int number, unsigned int b, char *buffer, int size);
char **strsep(char *string, char *del);
int check_del(char c, char *del);
int word_length(char *string, char *del);
int word_count(char *string, char *del);
char *next_word(char *string, char *del);
void msub(stack_t **stack, unsigned int line_number);
void mswap(stack_t **stack, unsigned int line_number);
int swap_error(unsigned int line_number, char *code);
unsigned int curr_len(void);
void empty_toks(void);
int check_line(char *dre, char *del);
void (*match_func(char *opcode))(stack_t**, unsigned int);


#endif
