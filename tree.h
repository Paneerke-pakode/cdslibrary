#ifndef TREE_H
#define TREE_H

#include "common.h"

typedef struct cds_bst cds_bst;

// creation and destruction
cds_bst* bst_create(void);
void bst_destroy(cds_bst* tree);

// core operations
cds_status bst_insert(cds_bst* tree, int value);
cds_status bst_search(const cds_bst* tree, int value);

// traversals (for debugging / verification)
void bst_inorder(const cds_bst* tree);

#endif


