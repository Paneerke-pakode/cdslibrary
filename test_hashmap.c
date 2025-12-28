#include <assert.h>
#include "hashmap.h"

int main() {
    cds_hashmap* map = hashmap_create(5);
    assert(map != NULL);
    assert(hashmap_size(map) == 0);

    int value;

    /* Insert elements */
    assert(hashmap_put(map, 1, 100) == CDS_SUCCESS);
    assert(hashmap_put(map, 2, 200) == CDS_SUCCESS);
    assert(hashmap_put(map, 3, 300) == CDS_SUCCESS);
    assert(hashmap_size(map) == 3);

    /* Get existing keys */
    assert(hashmap_get(map, 1, &value) == CDS_SUCCESS);
    assert(value == 100);

    assert(hashmap_get(map, 2, &value) == CDS_SUCCESS);
    assert(value == 200);

    assert(hashmap_get(map, 3, &value) == CDS_SUCCESS);
    assert(value == 300);

    /* Get non-existing key */
    assert(hashmap_get(map, 99, &value) == CDS_FAILURE);

    /* Update existing key */
    assert(hashmap_put(map, 2, 250) == CDS_SUCCESS);
    assert(hashmap_get(map, 2, &value) == CDS_SUCCESS);
    assert(value == 250);
    assert(hashmap_size(map) == 3);

    /* Force collisions */
    assert(hashmap_put(map, 6, 600) == CDS_SUCCESS);
    assert(hashmap_put(map, 11, 1100) == CDS_SUCCESS);
    assert(hashmap_size(map) == 5);

    assert(hashmap_get(map, 6, &value) == CDS_SUCCESS);
    assert(value == 600);

    assert(hashmap_get(map, 11, &value) == CDS_SUCCESS);
    assert(value == 1100);

    /* Remove a key */
    assert(hashmap_remove(map, 6) == CDS_SUCCESS);
    assert(hashmap_get(map, 6, &value) == CDS_FAILURE);
    assert(hashmap_size(map) == 4);

    /* Remove remaining keys */
    assert(hashmap_remove(map, 1) == CDS_SUCCESS);
    assert(hashmap_remove(map, 2) == CDS_SUCCESS);
    assert(hashmap_remove(map, 3) == CDS_SUCCESS);
    assert(hashmap_remove(map, 11) == CDS_SUCCESS);

    assert(hashmap_size(map) == 0);

    hashmap_destroy(map);
    return 0;
}
