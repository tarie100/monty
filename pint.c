#include"monty.h"
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
                fprintf(stderr, "L%d: can't pint, stack empty\n", line_no);
		free(*stack);
                exit(EXIT_FAILURE);
        }
        printf("%d\n", (*stack)->n);
}
