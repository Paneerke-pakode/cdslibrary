#ifndef STACK_H
#define STACK_H

#include <stddef.h>
#include "common.h"

typedef struct cds_stack cds_stack;

/* creation and destruction */
cds_stack* stack_create(size_t capacity);
void stack_destroy(cds_stack* stack);

/* core operations */
cds_status stack_push(cds_stack* stack, int value);
cds_status stack_pop(cds_stack* stack, int* out);
cds_status stack_peek(const cds_stack* stack, int* out);

/* utility */
int stack_is_empty(const cds_stack* stack);
int stack_is_full(const cds_stack* stack);
size_t stack_size(const cds_stack* stack);

#endif