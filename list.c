#include <stdlib.h>
#include "list.h"

/* private node structure */
typedef struct node {
    int data;
    struct node* next;
} node;

/* list structure */
struct cds_list {
    node* head;
    node* tail;
    size_t size;
};

cds_list* list_create(void) {
    cds_list* list = (cds_list*)malloc(sizeof(cds_list));
    if (!list) return NULL;
    list->head = NULL;
    list->tail = NULL;

    list->size = 0;

    return list;
}

cds_status list_push_front(cds_list* list, int value) {
    if (!list) return CDS_NULL_PTR;

    node* new_node = (node*)malloc(sizeof(node));
    if (!new_node) return CDS_OUT_OF_MEMORY;

    new_node->data = value;
    new_node->next = list->head;

    list->head = new_node;

    if (list->size == 0) {
        list->tail = new_node;
    }

    list->size++;
    return CDS_SUCCESS;
}

cds_status list_push_back(cds_list* list, int value) {
    if (!list) return CDS_NULL_PTR;

    node* new_node = (node*)malloc(sizeof(node));
    if (!new_node) return CDS_OUT_OF_MEMORY;

    new_node->data = value;
    new_node->next = NULL;

    if (list->size == 0) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }

    list->size++;
    return CDS_SUCCESS;
}

cds_status list_pop_front(cds_list* list, int* out) {
    if (!list || !out) return CDS_NULL_PTR;
    if (list->size == 0) return CDS_EMPTY;

    node* temp = list->head;
    *out = temp->data;

    list->head = temp->next;
    free(temp);

    list->size--;

    if (list->size == 0) {
        list->tail = NULL;
    }

    return CDS_SUCCESS;
}


cds_status list_pop_back(cds_list* list, int* out){
    if(!list || !out) return CDS_NULL_PTR;
    if (list->size == 0) return CDS_EMPTY;

    node* current = list->head;
    node* prev = NULL;

    /* single element case */
    if (list->size == 1){
        *out = current->data;
        free(current);
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
        return CDS_SUCCESS;
    }

    /* traverse to last node */
    while (current->next != NULL){
        prev = current;
        current = current->next;
    }

    *out = current->data;
    free(current);

    prev->next = NULL;
    list->tail = prev;
    list->size--;

    return CDS_SUCCESS;
}

size_t list_size(const cds_list* list){
    if (!list) return 0;
    return list->size;
}

void list_destroy(cds_list* list){
    if(!list) return;

    node* current = list->head;
    while (current) {
        node* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

