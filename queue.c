#include "queue.h"

/* create a new queue */
/* returns a pointer to the newly created queue */
/* print an error message and return NULL if an error occurs */
Queue *initialise_queue(void)
{
}

/* free memory for queue *queue */
/* frees memory for all entries in queue and queue itself */
/* print an error message and return if queue is NULL */
void free_queue(Queue *queue)
{
}

/* remove entry from queue *queue */
/* return data stored in entry */
/* user responsible for freeing returned data */
/* print an error message and return if queue is NULL or empty */
void *pop_queue(Queue *queue)
{
}

/* add entry to end of queue *queue */
/* allocate storage of data_size bytes in new entry */
/* copy data referenced by *data to entry */
/* allow data to be NULL */
/* return pointer to newly created entry */
/* print an error message and return if queue is NULL */
Node *push_queue(Queue *queue, void *data, size_t data_size)
{
}

/* return pointer to data at start of queue *queue */
/* print an error message and return if queue is NULL or empty */
void *peek_queue(Queue *queue)
{
}

/* print data stored in queue *queue to stdout */
/* prints data from queue top to bottom */
/* prints each entry data on a newline */
/* user gives pointer to function *print_func which is called to print data */
/* print an error message and return if queue or print function is NULL */
/* don't print anything if the queue is empty */
void print_queue(Queue *queue, void (*print_func)(void *))
{
}
