#include <assert.h>
#include "list.h"

int main() {
    cds_list* list = list_create();
    assert(list != NULL);
    assert(list_size(list) == 0);

    list_push_front(list, 10);
    list_push_back(list, 20);
    list_push_front(list, 5);

    int x;
    list_pop_front(list, &x);
    assert(x == 5);

    list_pop_back(list, &x);
    assert(x == 20);

    assert(list_size(list) == 1);

    list_destroy(list);
    return 0;
}
