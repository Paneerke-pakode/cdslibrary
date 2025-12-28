#include <stdlib.h>
#include "heap.h"

struct cds_heap
{
    int* data;         // array storing heap elements
    size_t size;       // current number of elements
    size_t capacity;   // max capacity
};

cds_heap* heap_create(size_t capacity)
{
   if (capacity == 0) return NULL;

   cds_heap* heap = (cds_heap*)malloc(sizeof(cds_heap));
   if (!heap) return NULL;

   heap->data = (int*)malloc(capacity * sizeof(int));
   if (!heap->data)
   {
       free(heap);
       return NULL;
   }

   heap->capacity = capacity;
   heap->size = 0;

   return heap;
}

int heap_is_empty(const cds_heap* heap)
{
    if (!heap) return 1;
    return heap->size == 0;
}

int heap_is_full(const cds_heap* heap)
{
    if (!heap) return 0;
    return heap->size == heap->capacity;
}

size_t heap_size(const cds_heap* heap)
{
    if (!heap) return 0;
    return heap->size;
}

static void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

cds_status heap_insert(cds_heap* heap, int value)
{
    if (!heap) return CDS_NULL_PTR;
    if (heap_is_full(heap)) return CDS_FULL;

    //insert at the end
    size_t i = heap->size;
    heap->data[i] = value;
    heap->size++;

    //heapify up
    while (i>0)
    {
        size_t parent = (i - 1) / 2;
        if (heap->data[parent] >= heap->data[i])
            break;
        swap(&heap->data[parent], &heap->data[i]);
        i = parent;
    }
    return CDS_SUCCESS;
}

cds_status heap_extract_max(cds_heap* heap, int* out)
{
    if (!heap || !out) return CDS_NULL_PTR;
    if (heap_is_empty(heap)) return CDS_EMPTY;

    *out = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;

    size_t i = 0;

    while (1)
    {
        size_t left = 2 * i + 1;
        size_t right = 2 * i + 2;
        size_t largest = i;

        if (left < heap->size && heap->data[left] > heap->data[largest])
            largest = left;
        if (right < heap->size && heap->data[right] > heap->data[largest])
            largest = right;

        if (largest == i)
            break;

        swap(&heap->data[i], &heap->data[largest]);
        i = largest;
    }
    return CDS_SUCCESS;
}

void heap_destroy(cds_heap* heap)
{
    if (!heap) return;
    free(heap->data);
    free(heap);
}