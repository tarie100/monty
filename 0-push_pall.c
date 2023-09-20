#include"monty.h"
#define STACK_SIZE 1024
/**
 * push - inserts a value into the stack
 * @val: the value
 */
void push(int val)
{
	int stack[STACK_SIZE];
	int stack_ptr = 0;

	if (stack_ptr == STACK_SIZE)
	{
		printf("Stack overflow\n");
		exit(EXIT_FAILURE);
	}
	else if (val == NULL)
	{
		fprintf(stderr, "L<line_number>: usage: push integer\n");
	}
	stack[stack_ptr++] = val;
}
/**
 * pall - retriever
 */
void pall(void)
{
	if (stack_ptr == 0)
	{
		return;
	}
	for (i = stack_ptr - 1; i >= 0; i--)
	{
		printf("%d\n", stack[i]);
	}
}
/**
 *
 */
void pint(void)
{
	if (stack_pointer == 0)
	{
		fprintf(stderr, "L<line_number>: can't pint, stack empty\n");
		exit(EXIT_FAILURE);
	}
	printf("%d\n", stack[stack_ptr - 1]);
}
/**
 * main - launcher
 * Return: 0
 */
int main(void)
{
	push(5);
	push(10);
	push(15);
	pall();
	pint();
	return (0);
}
