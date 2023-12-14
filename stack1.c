#include "mo.h"

/**
 * add_to_stack - adds node to the stack
 * @new_node: pointer
 * @ln: int 
*/

void add_to_stack(stack_t **new_node, __atribute__((unused))unsigned int ln)
{
	satck_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}

/**
 * print_stack - adds node to the stack
 * @stack: pointer
 * @line_number: kine number
*/

void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop_top - adds node
 * @stack: pointer
 * @line_number: int show the number of the line
*/

void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack ==NULL || *stack == NULL)
		more_err(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}


/**
 * print_top - print the pop
 * @stack: pointer
 * @line_number: int show the line number
*/

void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}
