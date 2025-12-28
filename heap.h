#ifndef HEAP_H
#define HEAP_H

#include <stddef.h>
#include "common.h"

typedef struct cds_heap cds_heap;

// creation and destruction
cds_heap* heap_create(size_t capacity);
void heap_destroy(cds_heap* heap);

// core operations
cds_status heap_insert(cds_heap* heap, int value);
cds_status heap_extract_max(cds_heap* heap,int* out);

// utility
int heap_is_empty(const cds_heap* heap);
int heap_is_full(const cds_heap* heap);
size_t heap_size(const cds_heap* heap);

#endif