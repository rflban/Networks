#include "queue.h"

#include <stdlib.h>

struct node
{
    void *data;
    struct node *next;
};

struct queue
{
    struct node *head;
    struct node *tail;
};


queue_t queue_create()
{
    struct queue *queue = malloc(sizeof(struct queue));

    if (!queue)
        return NULL;

    queue->head = NULL;
    queue->tail = NULL;

    return queue;
}

void queue_delete(queue_t *queue_ptr)
{
    if (queue_ptr && *queue_ptr)
    {
        struct node  *to_delete;
        struct queue *queue = *queue_ptr;

        while (queue->head)
        {
            to_delete   = queue->head;
            queue->head = to_delete->next;

            free(to_delete);
        }

        free(*queue_ptr);
        *queue_ptr = NULL;
    }
}

void queue_push(queue_t queue, void *data)
{
    if (queue)
    {
        struct node *new_node = malloc(sizeof(struct node));

        if (!new_node)
            return;

        new_node->data = data;
        new_node->next = NULL;

        if (!(queue->head))
            queue->head = queue->tail = new_node;
        else
        {
            queue->tail->next = new_node;
            queue->tail       = new_node;
        }
    }
}

void *queue_pop(queue_t queue)
{
    if (!queue || !(queue->head))
        return NULL;

    struct node *poped = queue->head;
    void        *data  = poped->data;

    queue->head = poped->next;
    if (!(queue->head))
        queue->tail = NULL;

    free(poped);

    return data;
}
