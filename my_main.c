#include"monty.h"
#define STACK_SIZE 1024
stack_t *stack = NULL;
/**
 * push - inserts a value into the stack
 * @stack: the stack
 * @line_no: value
 */
void push(stack_t **stack, unsigned int line_no)
{
        stack_t *newnode = malloc(sizeof(stack_t));
        if (newnode == NULL)
        {
                fprintf(stderr, "L%d: usage: push integer\n", line_no);
                exit(EXIT_FAILURE);
        }
        newnode->n = line_no;
        newnode->prev = NULL;
        newnode->next = *stack;
        if (*stack != NULL)
        {
                (*stack)->prev = newnode;
        }
        *stack = newnode;
}
/**
 * div - divides the 2nd element from the top of the stack
 * @stack: the stack
 */
void div_me(stack_t **stack, unsigned int line_no)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		fprintf(stderr, "L%d: can't div, stack too short\n", line_no);

	if ((*stack)->n == 0)
		fprintf(stderr, "L%d: Error", line_no);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * nop - does nothing
 */
void nop(stack_t **stack, unsigned int line_no)
{
        (void)stack;
        (void)line_no;
}
/**
 * main - launcher
 * Return: 0
 */
int main(void)
{
	unsigned int line_no;
	int i;

	instruction_t instruction_set[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"add", add},
		{"swap", swap},
		{"div", div_me},
		{"nop", nop},
		{"mod", mod},
		{NULL, NULL}
	};
	line_no = 1;
	for (i = 0; instruction_set[i].opcode != NULL; i++)
	{
		if (strcmp(instruction_set[i].opcode, "push") == 0)
		{
			instruction_set[i].f(&stack, line_no);
		}
		else if (strcmp(instruction_set[i].opcode, "pall") == 0)
		{
			instruction_set[i].f(&stack, line_no);
		}
		else if (strcmp(instruction_set[i].opcode, "pint") == 0)
		{
			instruction_set[i].f(&stack, line_no);
		}
		else if (strcmp(instruction_set[i].opcode, "pop") == 0)
		{
                          instruction_set[i].f(&stack, line_no);
		}
		else if (strcmp(instruction_set[i].opcode, "add") == 0)
		{
                          instruction_set[i].f(&stack, line_no);
		}
		else if (strcmp(instruction_set[i].opcode, "swap") == 0)
		{
                          instruction_set[i].f(&stack, line_no);
		}
		else if (strcmp(instruction_set[i].opcode, "div") == 0)
		{
                          instruction_set[i].f(&stack, line_no);
		}
		else if (strcmp(instruction_set[i].opcode, "nop") == 0)
		{
                          instruction_set[i].f(&stack, line_no);
		}
		else if (strcmp(instruction_set[i].opcode, "mod") == 0)
		{
			instruction_set[i].f(&stack, line_no);
		}
		line_no++;
	}
	return 0;
}
