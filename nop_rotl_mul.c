#include"monty.h"
void nop(stack_t **stack, unsigned int line_no)
{
    (void)stack;
    (void)line_no;
    /* No operation. Do nothing. */
}

void rotl(stack_t **stack, unsigned int line_no)
{
	stack_t *first, *second, *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't rotate left, stack too short\n", line_no);
        exit(EXIT_FAILURE);
    }
    
    first = *stack;
    second = (*stack)->next;
    
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    
    temp = *stack;
    
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    
    temp->next = first;
    first->prev = temp;
    
    first->next = NULL;
    second->prev = NULL;
}

void mul(stack_t **stack, unsigned int line_no)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't multiply, stack too short\n", line_no);
        exit(EXIT_FAILURE);
    }
    
    (*stack)->next->n *= (*stack)->n;
    pop(stack, line_no);
}

void sub(stack_t **stack, unsigned int line_no)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't subtract, stack too short\n", line_no);
        exit(EXIT_FAILURE);
    }
    
    (*stack)->next->n -= (*stack)->n;
    pop(stack, line_no);
}
