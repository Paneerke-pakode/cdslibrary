#include <stdlib.h>
#include "stack.h"

struct cds_stack
{
    int* data;
    int top;
    size_t capacity;
};

cds_stack* stack_create(size_t capacity)
{
    if (capacity == 0) return NULL;

    cds_stack* stack = (cds_stack*)malloc(sizeof(cds_stack));
    if (!stack) return NULL;

    stack->data = (int*)malloc(sizeof(int) * capacity);
    if (!stack->data)
    {
        free(stack);
        return NULL;
    }

    stack->capacity = capacity;
    stack->top = -1;

    return stack;
}

int stack_is_full(const cds_stack* stack) {
    if (!stack) return 0;
    return stack->top == (int)(stack->capacity - 1);
}


int stack_is_empty(const cds_stack* stack)
{
    if (!stack) return 1;
    return stack->top == -1; //null stack treated as empty
}

size_t stack_size(const cds_stack* stack)
{
    if (!stack) return 0;
    return (size_t)(stack->top+1);
}

cds_status stack_push(cds_stack* stack, int value)
{
    if (!stack) return CDS_NULL_PTR;
    if (stack_is_full(stack)) return CDS_FULL;

    stack->data[++stack->top] = value; // top moves -> value written
    return CDS_SUCCESS;
}

cds_status stack_pop(cds_stack* stack, int* out)
{
    if (!stack || !out) return CDS_NULL_PTR;
    if (stack_is_empty(stack)) return CDS_EMPTY;

    *out = stack->data[stack->top--]; //read current top  and then move pointer down
    return CDS_SUCCESS;
}

cds_status stack_peek(const cds_stack* stack, int* out)
{
    if (!stack || !out) return CDS_NULL_PTR;
    if (stack_is_empty(stack)) return CDS_EMPTY;

    *out = stack->data[stack->top];
    return CDS_SUCCESS;
}

void stack_destroy(cds_stack* stack)
{
    if (!stack) return;

    free(stack->data);
    free(stack);
}
