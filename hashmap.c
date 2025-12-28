#include <stdlib.h>
#include "hashmap.h"

typedef struct entry
{
    int key;
    int value;
    struct entry* next;
} entry;

struct cds_hashmap
{
    entry** buckets; // array of bucket heads
    size_t capacity; // number of buckets
    size_t size; // number of key-value pairs
};

// entry** buckets because each bucket
// is a linked list and buckets[i] points to the head of that list
// size tracks actual elements not buckets
// collisions are handled cleanly

static size_t hash_key(int key, size_t capacity)
{
    if (key < 0) key = -key;
    return (size_t)key % capacity;
}

cds_hashmap* hashmap_create(size_t capacity)
{
    if (capacity == 0) return NULL;

    cds_hashmap* map = (cds_hashmap*)malloc(sizeof(cds_hashmap));
    if (!map) return NULL;

    map->buckets = (entry**)calloc(capacity, sizeof(entry*));
    // calloc initialized all bucket heads to NULL and prevents garbage pointers
    if (!map->buckets)
    {
        free(map);
        return NULL;
    }

    map->capacity = capacity;
    map->size = 0;

    return map;
}

size_t hashmap_size(const cds_hashmap* map)
{
    if (!map) return 0;
    return map->size;
}


cds_status hashmap_put(cds_hashmap* map, int key, int value)
{
    if (!map) return CDS_NULL_PTR;

    size_t index = hash_key(key, map->capacity);
    entry* current = map->buckets[index];

    // check if key already exists
    while (current)
    {
        if (current->key == key)
        {
            current->value = value; // update
            return CDS_SUCCESS;
        }
        current = current->next;
    }

    // insert new entry at head
    entry* new_entry = (entry*)malloc(sizeof(entry));
    if (!new_entry) return CDS_OUT_OF_MEMORY;

    new_entry->key = key;
    new_entry->value = value;
    new_entry->next = map->buckets[index];

    map->buckets[index] = new_entry;
    map->size++;

    return CDS_SUCCESS;
}
// insert at head because O(1) and Order inside bucket does not matter

cds_status hashmap_get(const cds_hashmap* map, int key, int* out)
{
    if (!map || !out) return CDS_NULL_PTR;

    size_t index = hash_key(key, map->capacity);
    entry* current = map->buckets[index];

    while (current)
    {
        if (current->key == key)
        {
            *out = current->value;
            return CDS_SUCCESS;
        }
        current = current->next;
    }

    return CDS_FAILURE; //key not found
}

cds_status hashmap_remove(cds_hashmap* map, int key)
{
    if (!map) return CDS_NULL_PTR;

    size_t index = hash_key(key, map->capacity);
    entry* current = map->buckets[index];
    entry* prev = NULL;

    while (current)
    {
        if (current->key == key)
        {
            if (prev)
                prev->next = current->next;
            else
                map->buckets[index] = current->next;

            free(current);
            map->size--;
            return CDS_SUCCESS;
        }
        prev = current;
        current = current->next;
    }
    return CDS_FAILURE; //key not found
}

void hashmap_destroy(cds_hashmap* map)
{
    if (!map) return;

    for (size_t i = 0; i < map->capacity; i++)
    {
        entry* current = map->buckets[i];
        while (current)
        {
            entry* next = current->next;
            free(current);
            current = next;
        }
    }
    free(map->buckets);
    free(map);
}


