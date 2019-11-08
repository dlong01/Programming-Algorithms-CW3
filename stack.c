#include "stack.h"

/* create a new stack */
/* returns a pointer to the newly created stack */
/* print an error message and return NULL if an error occurs */
Stack *initialise_stack(void)
{
}

/* free memory for stack *stack */
/* frees memory for all entries in stack and stack itself */
/* print an error message and return if queue is NULL */
void free_stack(Stack *stack)
{
}

/* remove entry from stack *stack */
/* return data stored in entry */
/* user responsible for freeing returned data */
/* print an error message and return if stack is NULL or empty */
void *pop_stack(Stack *stack)
{
}

/* add entry to end of stack *stack */
/* allocate storage of data_size bytes in new entry */
/* copy data referenced by *data to entry */
/* return pointer to newly created entry */
/* print an error message and return if stack is NULL */
/* or if data is NULL */
Node *push_stack(Stack *stack, void *data, size_t data_size)
{
}

/* return pointer to data at start of stack *stack */
/* print an error message and return if stack is NULL or empty */
void *peek_stack(Stack *stack)
{
}

/* print data stored in stack *stack to stdout */
/* prints data from stack top to bottom */
/* prints each entry data on a newline */
/* user gives pointer to function *print_func which is called to print data */
/* print an error message and return if stack or print function is NULL */
/* don't print anything if the stack is empty */
void print_stack(Stack *stack, void (*print_func)(void *))
{
}
