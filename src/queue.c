#include <stdlib.h>
#include "queue.h"

struct cds_queue
{
    int* data;
    size_t capacity;
    size_t size;
    size_t front;
    size_t rear;
};

cds_queue* queue_create(size_t capacity)
{
    if (capacity == 0) return NULL;

    cds_queue* q = (cds_queue*)malloc(sizeof(cds_queue));
    if (!q) return NULL;

    q->data = (int*)malloc(sizeof(int)*capacity);
    if (!q->data)
    {
        free(q);
        return NULL;
    }
    q->capacity = capacity;
    q->size = 0;
    q->front = 0;
    q->rear = 0;
    return q;
}

int queue_is_empty(const cds_queue* queue)
{
    if (!queue) return 1;
    return queue->size == 0;
}

int queue_is_full(const cds_queue* queue)
{
    if (!queue) return 0;
    return queue->size == queue->capacity;
}

size_t queue_size(const cds_queue* queue)
{
    if (!queue) return 0;
    return queue->size;
}

cds_status queue_enqueue(cds_queue* queue, int value)
{
    if (!queue) return CDS_NULL_PTR;
    if (queue_is_full(queue)) return CDS_FULL;

    queue->data[queue->rear] = value;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->size++;

    return CDS_SUCCESS;
}

cds_status queue_dequeue(cds_queue* queue, int* out)
{
    if (!queue || !out) return CDS_NULL_PTR;
    if (queue_is_empty(queue)) return CDS_EMPTY;

    *out = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;

    return CDS_SUCCESS;
}

void queue_destroy(cds_queue* queue)
{
    if (!queue) return;

    free(queue->data);
    free(queue);
}
