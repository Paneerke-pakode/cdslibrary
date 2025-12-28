#ifndef HASHMAP_H
#define HASHMAP_H

#include <stddef.h>
#include "common.h"

typedef struct cds_hashmap cds_hashmap;

// creation and destruction
cds_hashmap* hashmap_create(size_t capacity);
void hashmap_destroy(cds_hashmap* map);

// core operations
cds_status hashmap_put(cds_hashmap* map, int key, int value);
cds_status hashmap_get(const cds_hashmap* map, int key, int* out);
cds_status hashmap_remove(cds_hashmap* map, int key);

// Utility
size_t hashmap_size(const cds_hashmap* map);

#endif
