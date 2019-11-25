#include "queue.h"
#include "linked_list.h"
#include <stdio.h>

/* create a new queue */
/* returns a pointer to the newly created queue */
/* print an error message and return NULL if an error occurs */
Queue *initialise_queue(void)
{
        struct LinkedList *queue;
        queue = initialise_linked_list();
        
        return queue;
}

/* free memory for queue *queue */
/* frees memory for all entries in queue and queue itself */
/* print an error message and return if queue is NULL */
void free_queue(Queue *queue)
{
        if (queue == NULL)  {
                fprintf(stderr, "Unable to free queue\n");
                return;
        }
        while (queue->head != NULL) {
                if (queue->head->data != NULL) {
                        free(queue->head->data);
                }
                pop_queue(queue);
        }
        
        free(queue);
}

/* remove entry from queue *queue */
/* return data stored in entry */
/* user responsible for freeing returned data */
/* print an error message and return if queue is NULL or empty */
void *pop_queue(Queue *queue)
{
        void *stored_data;
        
        if (queue == NULL || queue->head == NULL)  {
                fprintf(stderr, "Unable to pop from empty queue\n");
                return NULL;
        }
        stored_data = queue->head->data;
 
        remove_head_linked_list(queue);
        
        
        return stored_data;
}

/* add entry to end of queue *queue */
/* allocate storage of data_size bytes in new entry */
/* copy data referenced by *data to entry */
/* allow data to be NULL */
/* return pointer to newly created entry */
/* print an error message and return if queue is NULL */
Node *push_queue(Queue *queue, void *data, size_t data_size)
{
        struct Node *tail;
 
        if (data == NULL)  {
                fprintf(stderr, "Unable to add entry with empty data\n");
                return NULL;
        }
        
        if (queue == NULL) {
                fprintf(stderr, "Unable to add entry\n");
                return NULL;
        }

        tail = append_linked_list(queue, data);
        
        tail->data = (Node *)malloc(data_size);
        
        return tail;
}

/* return pointer to data at start of queue *queue */
/* print an error message and return if queue is NULL or empty */
void *peek_queue(Queue *queue)
{
        void *data;
        if (queue == NULL) {
                fprintf(stderr, "Unable to peek empty queue\n");
                return NULL;
        }
        
        data = queue->head->data;
        return data;
}

/* print data stored in queue *queue to stdout */
/* prints data from queue top to bottom */
/* prints each entry data on a newline */
/* user gives pointer to function *print_func which is called to print data */
/* print an error message and return if queue or print function is NULL */
/* don't print anything if the queue is empty */
void print_queue(Queue *queue, void (*print_func)(void *))
{
        Node *node;
        
        if (queue == NULL || print_func == NULL)  {
                fprintf(stderr, "Unable to print linked list\n");
                return;
        }
        
        node = queue->head;
        
        while (node != NULL)  {
                if (node->data != NULL) {                
                        print_func(node->data);
                        node = node->next;
                }
        }
}
