#include "queue.h"
#include <string.h>

void queue_init(queue_t *q)
{
        q->first = 0;
        q->last = QUEUESIZE-1;
        q->count = 0;
}

int queue_enqueue(queue_t *q, const char* element)
{
        if (q->count >= QUEUESIZE)
		return -1;
        else {
                q->last = (q->last+1) % QUEUESIZE;
                strcpy( q->q[ q->last ], element);    
                q->count = q->count + 1;
		return 0;
	}
}

char* queue_dequeue(queue_t *q)
{
        if (q->count <= 0) 
		return NULL;
	else {
               char* x = q->q[ q->first ];
                q->first = (q->first+1) % QUEUESIZE;
                q->count = q->count - 1;
		return x;
	}
}

int queue_is_empty(queue_t *q)
{
        if (q->count <= 0) 
		return 1;
        else 
		return 0;
}
