#include"monty.h"
/**
 * mod - modulus
 * @stack: the stack
 * @line_no: int
 */
void mod(stack_t **stack, unsigned int line_no)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
		fprintf(stderr, "L%d: Error\n", line_no);;
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
