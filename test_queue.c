#include <assert.h>
#include "queue.h"

int main() {
    cds_queue* q = queue_create(3);
    assert(q != NULL);

    /* Initially empty */
    assert(queue_is_empty(q));
    assert(queue_size(q) == 0);

    /* Enqueue elements */
    assert(queue_enqueue(q, 10) == CDS_SUCCESS);
    assert(queue_enqueue(q, 20) == CDS_SUCCESS);
    assert(queue_enqueue(q, 30) == CDS_SUCCESS);

    /* Queue should be full */
    assert(queue_is_full(q));
    assert(queue_size(q) == 3);

    /* Enqueue on full queue */
    assert(queue_enqueue(q, 40) == CDS_FULL);

    int x;

    /* Dequeue one element */
    assert(queue_dequeue(q, &x) == CDS_SUCCESS);
    assert(x == 10);
    assert(queue_size(q) == 2);

    /* Enqueue again (tests circular wrap-around) */
    assert(queue_enqueue(q, 40) == CDS_SUCCESS);
    assert(queue_is_full(q));

    /* Dequeue remaining elements in FIFO order */
    assert(queue_dequeue(q, &x) == CDS_SUCCESS);
    assert(x == 20);

    assert(queue_dequeue(q, &x) == CDS_SUCCESS);
    assert(x == 30);

    assert(queue_dequeue(q, &x) == CDS_SUCCESS);
    assert(x == 40);

    /* Now empty again */
    assert(queue_is_empty(q));
    assert(queue_size(q) == 0);

    /* Dequeue on empty queue */
    assert(queue_dequeue(q, &x) == CDS_EMPTY);

    queue_destroy(q);
    return 0;
}
