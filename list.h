#ifndef LIST_H
#define LIST_H

#include <stddef.h> /* for size_t */
#include "common.h"

typedef struct cds_list cds_list;

/* creation and destruction */
cds_list* list_create(void);
void list_destroy(cds_list* list);

/* insertion */
cds_status list_push_front(cds_list* list, int value);
cds_status list_push_back(cds_list* list, int value);

/* deletion */
cds_status list_pop_front(cds_list* list, int* out);
cds_status list_pop_back(cds_list* list, int* out);

/* Utility */
size_t list_size(const cds_list* list);

#endif