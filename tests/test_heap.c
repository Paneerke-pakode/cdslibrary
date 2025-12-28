#include <assert.h>
#include "heap.h"

int main() {
    cds_heap* heap = heap_create(5);
    assert(heap != NULL);

    /* Initially empty */
    assert(heap_is_empty(heap));
    assert(heap_size(heap) == 0);

    /* Insert elements */
    assert(heap_insert(heap, 10) == CDS_SUCCESS);
    assert(heap_insert(heap, 40) == CDS_SUCCESS);
    assert(heap_insert(heap, 30) == CDS_SUCCESS);
    assert(heap_insert(heap, 20) == CDS_SUCCESS);
    assert(heap_insert(heap, 50) == CDS_SUCCESS);

    /* Heap should be full */
    assert(heap_is_full(heap));
    assert(heap_size(heap) == 5);

    /* Insert into full heap */
    assert(heap_insert(heap, 60) == CDS_FULL);

    int x;

    /* Extract max (should be 50) */
    assert(heap_extract_max(heap, &x) == CDS_SUCCESS);
    assert(x == 50);
    assert(heap_size(heap) == 4);

    /* Extract next max (should be 40) */
    assert(heap_extract_max(heap, &x) == CDS_SUCCESS);
    assert(x == 40);

    /* Insert again (tests heapify-up after extract) */
    assert(heap_insert(heap, 45) == CDS_SUCCESS);
    assert(heap_size(heap) == 4);

    /* Extract remaining elements in descending order */
    assert(heap_extract_max(heap, &x) == CDS_SUCCESS);
    assert(x == 45);

    assert(heap_extract_max(heap, &x) == CDS_SUCCESS);
    assert(x == 30);

    assert(heap_extract_max(heap, &x) == CDS_SUCCESS);
    assert(x == 20);

    assert(heap_extract_max(heap, &x) == CDS_SUCCESS);
    assert(x == 10);

    /* Now empty */
    assert(heap_is_empty(heap));
    assert(heap_size(heap) == 0);

    /* Extract from empty heap */
    assert(heap_extract_max(heap, &x) == CDS_EMPTY);

    heap_destroy(heap);
    return 0;
}
