#include"monty.h"
#define STACK_SIZE 1024
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
/**
 * void pop(stack_t **stack, unsigned int line_no)
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
}*/
/**
 * main - launcher
 */
int main(void)
{
	stack_t *temp, *stack = NULL;
	unsigned int line_no = 1;
	
	push(&stack, 10);
	push(&stack, 5);
	add(&stack, line_no++);
	printf("Result: %d\n", stack->n);
	swap(&stack, line_no++);
	printf("Swapped elements: %d and %d\n", stack->n, stack->next->n);
	div_me(&stack, line_no++);
	printf("Division result: %d\n", stack->n);
	mod(&stack, line_no++);
	printf("Final result: %d\n", stack->n);
	nop(&stack, line_no++);
	rotl(&stack, line_no++);
	printf("Rotated stack: ");
	temp = stack;
	while (temp != NULL)
	{
		printf("%d ", temp->n);
		temp = temp->next;
	}
	printf("\n");
	mul(&stack, line_no++);
	printf("Multiplication result: %d\n", stack->n);
	sub(&stack, line_no++);
	printf("Subtraction result: %d\n", stack->n);
	while (stack != NULL)
	{
		pop(&stack, line_no++);
	}
	return (0);
}
