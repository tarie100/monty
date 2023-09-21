#include"monty.h"
/**
 * pop - deletes an elements from the stack
 * @stack: the stack
 * @line_no: value
 *
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
*}*/
**
 * add - adds an element to the stack
 * @stack: ..
 * @line_no: ..
 *
void add(stack_t **stack, unsigned int line_no)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_no);
	
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;
    pop(stack, line_no);
}
/**
 * swap - swaps two elements
 * @stack: the stack
 * @line_no: value
 */
void swap(stack_t **stack, unsigned int line_no)
{
	int temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_no);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}
/**
 * div - divides elements
 * @stack: the stack
 * @line_no: value
 */
void div_me(stack_t **stack, unsigned int line_no)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't divide, stack too short\n", line_no);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_no);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n /= (*stack)->n;
    pop(stack, line_no);
}
