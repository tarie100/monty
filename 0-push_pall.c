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
		fprintf(stderr, "L<line_number>: usage: push integer\n");
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
 * pall - retriever
 * @stack: the stack
 * @line_no: val
 */
void pall(stack_t **stack, unsigned int line_no)
{
	stack_t *current = *stack;
	(void) line_no;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * pint - checks for the top element
 * @stack: the stack
 * @line_no: val
 */
void pint(stack_t **stack, unsigned int line_no)
{
	(void) line_no;
	if (*stack == NULL)
	{
		fprintf(stderr, "L<line_number>: can't pint, stack empty\n");
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
void pop(stack_t **stack, unsigned int line_no)
{
        stack_t *temp;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_no);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = (*stack)->next;

    if (*stack != NULL)
    {
        (*stack)->prev = NULL;
    }

    free(temp);
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
		line_no++;
	}
	return 0;
}
