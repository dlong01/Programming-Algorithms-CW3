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
                fprintf(stderr, "Unable to free queue\n");
                return;
        }
        while (stack->tail != NULL) {
                if (stack->tail->data != NULL) {
                        free(stack->tail->data);
                }
                pop_stack(stack);
        }
        
        free(stack);
}

/* remove entry from stack *stack */
/* return data stored in entry */
/* user responsible for freeing returned data */
/* print an error message and return if stack is NULL or empty */
void *pop_stack(Stack *stack)
{
        void *stored_data;
        
        if (stack == NULL || stack->tail == NULL)  {
                fprintf(stderr, "Unable to pop from empty queue\n");
                return NULL;
        }
        stored_data = stack->tail->data;
 
        remove_tail_linked_list(stack);
        
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
        struct Node *tail;
 
        if (data == NULL)  {
                fprintf(stderr, "Unable to add entry with empty data\n");
                return NULL;
        }
        
        if (stack == NULL) {
                fprintf(stderr, "Unable to add entry\n");
                return NULL;
        }
        
        tail = append_linked_list(stack, data);
        
        tail->data = malloc(data_size);
        memcpy(tail->data, data, data_size);
        
        return tail;
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
        
        data = stack->tail->data;
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
        Node *node;
        
        if (stack == NULL || print_func == NULL)  {
                fprintf(stderr, "Unable to print linked list\n");
                return;
        }
        
        node = stack->tail;
        
        while (node != NULL)  {
                if (node->data != NULL) {
                        print_func(node->data);
                        node = node->prev;
                }
        }
}
