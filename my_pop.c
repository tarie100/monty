#include"monty.h"
/**
 * pop - deletes an element from the stack
 * @stack: the stack
 * @line_no: val
 */
void pop(stack_t **stack, unsigned int line_no)
{
        stack_t **tmp = 0;

        if(*stack == NULL)
        {
                fprintf(stderr, "L%d: can't pop an empty stack\n", line_no);
                exit(EXIT_FAILURE);
        }
        *tmp = *stack;
        *stack = (*stack) -> next;
        if (*stack != NULL)
        {
                (*stack)->prev = NULL;
        }
        free(tmp);
}
