#ifndef NETWORKS_LAB03_QUEUE_H_
#define NETWORKS_LAB03_QUEUE_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct queue *queue_t;

queue_t queue_create();
void    queue_delete(queue_t *queue);

void queue_push(queue_t queue, void *data);
void *queue_pop(queue_t queue);
 
#ifdef __cplusplus
}
#endif

#endif // NETWORKS_LAB03_QUEUE_H_
