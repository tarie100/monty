#include"monty.h"
/**
 * add - adds two elements from the top of the stack
 * @@stack: the stack
 */
void add(stack_t **stack, unsigned int line_no)
{
        int sum, len = 0;
        stack_t *p;

        p = *stack;
        while(p)
        {
                p = p->next;
                len++;
        }
        if (len < 2)
        {
                fprintf(stderr, "L%d: can't add, stack too short\n", line_no);
                free(*stack);
                exit(EXIT_FAILURE);
        }
        p = *stack;
        sum = p->n + p->next->n;
        p->next->n = sum;
        *stack = p->next;
        free(p);
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
 * swap - swaps elements
 * @stack: the stack
 * @line_no: int
 */
void swap(stack_t **stack, unsigned int line_no)
{
	int len = 0;
	int result;
	stack_t *p;

	p = *stack;
	while(p)
	{
		p = p->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_no);
		free(stack);
		exit(EXIT_FAILURE);
	}
	p = *stack;
	result = p->n;
	p->n = p->next->n;
	p->next->n = result;
}
