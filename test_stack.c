#include <assert.h>
#include "stack.h"

int main() {
    cds_stack* s = stack_create(3);
    assert(s != NULL);
    assert(stack_is_empty(s));

    stack_push(s, 10);
    stack_push(s, 20);
    stack_push(s, 30);

    assert(stack_is_full(s));

    int x;
    stack_pop(s, &x);
    assert(x == 30);

    stack_peek(s, &x);
    assert(x == 20);

    assert(stack_size(s) == 2);

    stack_destroy(s);
    return 0;
}
