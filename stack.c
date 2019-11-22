#include "stack.h"
#include "linked_list.h"
#include <stdio.h>

/* create a new stack */
/* returns a pointer to the newly created stack */
/* print an error message and return NULL if an error occurs */
Stack *initialise_stack(void)
{
        struct LinkedList *stack;
        stack = initialise_linked_list();
        
        return stack;
}

/* free memory for stack *stack */
/* frees memory for all entries in stack and stack itself */
/* print an error message and return if queue is NULL */
void free_stack(Stack *stack)
{
        if (stack == NULL)  {
                fprintf(stderr, "Unable to free stack\n");
                return;
        }
        free_linked_list(stack);
}

/* remove entry from stack *stack */
/* return data stored in entry */
/* user responsible for freeing returned data */
/* print an error message and return if stack is NULL or empty */
void *pop_stack(Stack *stack)
{
        void *stored_data;
        if (stack == NULL)  {
                fprintf(stderr, "Unable to pop from empty stack\n");
                return NULL;
        }
        stored_data = stack->head->data;
 
        remove_head_linked_list(stack);
        
        
        return stored_data;
}

/* add entry to end of stack *stack */
/* allocate storage of data_size bytes in new entry */
/* copy data referenced by *data to entry */
/* return pointer to newly created entry */
/* print an error message and return if stack is NULL */
/* or if data is NULL */
Node *push_stack(Stack *stack, void *data, size_t data_size)
{
        struct Node *head;
 
        if (data == NULL)  {
                fprintf(stderr, "Unable to add entry with empty data\n");
                return NULL;
        }
        
        if (stack == NULL) {
                fprintf(stderr, "Unable to add entry\n");
                return NULL;
        }
        
        head = append_linked_list(stack, data);
        
        head->data = (Node *)malloc(data_size);
        
        if (head->data == NULL) {
                fprintf(stderr, "Unable to add entry\n");
                return NULL;
        }
        return head;
        
        
}

/* return pointer to data at start of stack *stack */
/* print an error message and return if stack is NULL or empty */
void *peek_stack(Stack *stack)
{
        void *data;
        if (stack == NULL) {
                fprintf(stderr, "Unable to peek empty queue\n");
                return NULL;
        }
        
        data = stack->head->data;
        return data;
}

/* print data stored in stack *stack to stdout */
/* prints data from stack top to bottom */
/* prints each entry data on a newline */
/* user gives pointer to function *print_func which is called to print data */
/* print an error message and return if stack or print function is NULL */
/* don't print anything if the stack is empty */
void print_stack(Stack *stack, void (*print_func)(void *))
{
        print_linked_list(stack, (*print_func));
}
