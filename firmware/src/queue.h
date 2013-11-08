#ifndef  QUEUE_H
#define QUEUE_H

#define QUEUESIZE       16
#define CMD_SIZE 64

typedef struct {
        int q[QUEUESIZE+1][CMD_SIZE];		/* body of queue */
        int first;                      /* position of first element */
        int last;                       /* position of last element */
        int count;                      /* number of queue elements */
} queue_t;

void queue_init(queue_t *q);
int queue_enqueue(queue_t *q, const char* element);
char* queue_dequeue(queue_t *q);
int queue_is_empty(queue_t *q);


#endif