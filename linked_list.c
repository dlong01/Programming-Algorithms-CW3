#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

/* create a new node */
/* returns a pointer to the newly created node */
/* print an error message and return NULL if an error occurs */
Node *initialise_node(void)
{
        struct Node *new_node;
        new_node = (Node *)malloc(sizeof(Node));
        
        new_node->prev = NULL;
        new_node->next = NULL;
        new_node->data = NULL;
        
        if (new_node == NULL)  {
                fprintf(stderr, "Unable to create new node\n");
                return NULL;
        }
        
        return new_node;
}

/* free memory for node *node */
/* print an error message and return if node is NULL */
void free_node(Node *node)
{
        if (node == NULL)  {
                fprintf(stderr, "Unable to free node\n");
        }
        
        node->prev->next = node->next;
        node->next->prev = node->prev;

        free(node);
        
}

/* create a new linked list */
/* returns a pointer to the newly created list */
/* print an error message and return NULL if an error occurs */
LinkedList *initialise_linked_list(void)
{
        struct LinkedList *list;
        list = (LinkedList *)malloc(sizeof(LinkedList));
        
        list->head = NULL;
        list->tail = NULL;
        
        if (list == NULL)  {
                fprintf(stderr, "Unable to initialise linked list\n");
                return NULL;
        }
        
        return list;
}

/* free memory for linked list *list */
/* frees memory for all nodes in linked list and list itself */
/* print an error message and return if list is NULL */
void free_linked_list(LinkedList *list)
{
        if (list == NULL)  {
                fprintf(stderr, "Unable to free list\n");
        }

        while (list->head != NULL)  {
                remove_tail_linked_list(list);
        }
        free(list);
}

/* create and add node to the tail of linked list *list */
/* and set data stored at node to *data */
/* should return a pointer to the new node */
/* should return NULL if an error occurs */
Node *append_linked_list(LinkedList *list, void *data)
{
        Node *new_node = initialise_node();
        
        if (new_node == NULL)  {
                return NULL;
        }
        
        new_node->prev = list->tail;
        list->tail = new_node;
        list->tail->data = data;
        
        return list->tail;
}

/* create and add node to the head of linked list *list */
/* and set data stored at node to *data */
/* should return a pointer to the new node */
/* should return NULL if an error occurs */
Node *prepend_linked_list(LinkedList *list, void *data)
{
        Node *new_node = initialise_node();
        
        if (new_node == NULL)  {
                return NULL;
        }
        
        new_node->next = list->head;
        list->head = new_node;
        list->head->data = data;
        
        return list->tail;
}

/* remove head from linked list *list */
/* print an error message and return if list is NULL or empty */
void remove_head_linked_list(LinkedList *list)
{
        if (list == NULL)  {
                fprintf(stderr, "Unable to remove head from empty linked list\n");
                return;
        }
        
        free_node(list->head);
}

/* remove tail from linked list *list */
/* print an error message and return if list is NULL or empty */
void remove_tail_linked_list(LinkedList *list)
{       
        if (list == NULL)  {
                fprintf(stderr, "Unable to remove tail from empty linked list\n");
                return;
        }
        
        free_node(list->tail);
}

/* print data stored in linked list *list to stdout */
/* prints data from head to tail */
/* prints each node data on a newline */
/* user gives pointer to function *print_func which is called to print data */
/* print an error message and return if list or print function is NULL */
/* don't print anything if the list is empty */
void print_linked_list(LinkedList *list, void (*print_func)(void *))
{
}

/* print char pointed to by *ptr to stdout */
void print_char(void *ptr)
{
}

/* print int pointed to by *ptr to stdout */
void print_int(void *ptr)
{
}

/* print double pointed to by *ptr to stdout */
void print_double(void *ptr)
{
}

/* print a string pointed to by *ptr to stdout */
void print_string(void *ptr)
{
}
