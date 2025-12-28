#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>
#include "common.h"

typedef struct cds_queue cds_queue;

/* creation and destruction */
cds_queue* queue_create(size_t capacity);
void queue_destroy(cds_queue* queue);

/* Core Operations */
cds_status queue_enqueue(cds_queue* queue, int value);
cds_status queue_dequeue(cds_queue* queue, int* out);

/* utility */
int queue_is_empty(const cds_queue* queue);
int queue_is_full(const cds_queue* queue);
size_t queue_size(const cds_queue* queue);

#endif