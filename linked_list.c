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
        
        if (new_node == NULL)  {
                fprintf(stderr, "Unable to create new node\n");
                return NULL;
        }
 
        new_node->prev = NULL;
        new_node->next = NULL;
        new_node->data = NULL;
        
        return new_node;
}

/* free memory for node *node */
/* print an error message and return if node is NULL */
void free_node(Node *node)
{
        if (node == NULL)  {
                fprintf(stderr, "Unable to free node\n");
                return;
        }
        

        if (node->prev != NULL) 
                node->prev->next = node->next;
        if (node->next != NULL)        
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
        
        if (list == NULL)  {
                fprintf(stderr, "Unable to initialise linked list\n");
                return NULL;
        }
        
        list->head = NULL;
        list->tail = NULL;
        
        return list;
}

/* free memory for linked list *list */
/* frees memory for all nodes in linked list and list itself */
/* print an error message and return if list is NULL */
void free_linked_list(LinkedList *list)
{
        if (list == NULL)  {
                fprintf(stderr, "Unable to free list\n");
                return;
        }

        while (list->tail != NULL)  {
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
        Node *prev_tail;
        Node *new_node = initialise_node();
        
        if (new_node == NULL || list == NULL)  {
                fprintf(stderr, "Unable to append node to linked list\n");
                return NULL;
        }
        
        prev_tail = list->tail;
        
        if (list->tail == NULL)  {
                list->tail = new_node;
                list->head = new_node;
        }
        else  {
                new_node->prev = prev_tail;
                prev_tail->next = new_node;
                list->tail = new_node;
                list->tail->data = data;
        }
        
        return list->tail;
}

/* create and add node to the head of linked list *list */
/* and set data stored at node to *data */
/* should return a pointer to the new node */
/* should return NULL if an error occurs */
Node *prepend_linked_list(LinkedList *list, void *data)
{
        Node *prev_head;
        Node *new_node = initialise_node();
        
        if (new_node == NULL || list == NULL)  {
                fprintf(stderr, "Unable to append node to linked list\n");
                return NULL;
        }
        
        prev_head = list->head;
        
        if (list->head == NULL)  {
                list->tail = new_node;
                list->head = new_node;
        }
        else  {
                new_node->prev = prev_head;
                prev_head->next = new_node;
                list->head = new_node;
                list->head->data = data;
        }
        
        return list->head;
}

/* remove head from linked list *list */
/* print an error message and return if list is NULL or empty */
void remove_head_linked_list(LinkedList *list)
{
        Node *node; 
        
        if (list == NULL || list->head == NULL)  {
                fprintf(stderr, "Unable to remove head from empty linked list\n");
                return;
        }
        if (list->head->next == NULL)  {
                free_node(list->head);
                list->tail = NULL;
                list->head = NULL;
        }
        else  {
                node = list->head->next; 
                free_node(list->head);
                list->head = node;
                node->prev = NULL;
        }

}

/* remove tail from linked list *list */
/* print an error message and return if list is NULL or empty */
void remove_tail_linked_list(LinkedList *list)
{       
        Node *node; 
        
        if (list == NULL || list->tail == NULL)  {
                fprintf(stderr, "Unable to remove head from empty linked list\n");
                return;
        }
        if (list->tail->prev == NULL)  {
                free_node(list->tail);
                list->tail = NULL;
                list->head = NULL;
        }
        else  {
                node = list->tail->prev; 
                free_node(list->tail);
                list->tail = node;
                node->next = NULL;
        }
}

/* print data stored in linked list *list to stdout */
/* prints data from head to tail */
/* prints each node data on a newline */
/* user gives pointer to function *print_func which is called to print data */
/* print an error message and return if list or print function is NULL */
/* don't print anything if the list is empty */
void print_linked_list(LinkedList *list, void (*print_func)(void *))
{
        Node *node;
        
        if (list == NULL)  {
                fprintf(stderr, "Unable to print linked list\n");
                return;
        }
        
        node = list->head;
        
        while (node != NULL)  {
                print_func(node->data);
                node = node->next;
        }
}

/* print char pointed to by *ptr to stdout */
void print_char(void *ptr)
{
        char *char_ptr;
        char_ptr = (char *)ptr;
        printf("%c\n", (char)*char_ptr);
}

/* print int pointed to by *ptr to stdout */
void print_int(void *ptr)
{
        int *int_ptr;
        int_ptr = (int *)ptr;
        printf("%d\n", (int)*int_ptr);
}

/* print double pointed to by *ptr to stdout */
void print_double(void *ptr)
{
        double *double_ptr;
        double_ptr = (double *)ptr;
        printf("%f\n", (double)*double_ptr);
}

/* print a string pointed to by *ptr to stdout */
void print_string(void *ptr)
{
        char *str_ptr;
        str_ptr = (char *)ptr;
        printf("%s\n", str_ptr);
}
