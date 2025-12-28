#include <assert.h>
#include "tree.h"

int main() {
    cds_bst* tree = bst_create();
    assert(tree != NULL);

    /* Initially, search should fail */
    assert(bst_search(tree, 10) == CDS_FAILURE);

    /* Insert elements */
    assert(bst_insert(tree, 10) == CDS_SUCCESS);
    assert(bst_insert(tree, 5) == CDS_SUCCESS);
    assert(bst_insert(tree, 20) == CDS_SUCCESS);
    assert(bst_insert(tree, 15) == CDS_SUCCESS);
    assert(bst_insert(tree, 30) == CDS_SUCCESS);

    /* Duplicate insert should fail */
    assert(bst_insert(tree, 10) == CDS_FAILURE);

    /* Search existing elements */
    assert(bst_search(tree, 10) == CDS_SUCCESS);
    assert(bst_search(tree, 5) == CDS_SUCCESS);
    assert(bst_search(tree, 20) == CDS_SUCCESS);
    assert(bst_search(tree, 15) == CDS_SUCCESS);
    assert(bst_search(tree, 30) == CDS_SUCCESS);

    /* Search non-existing elements */
    assert(bst_search(tree, 0) == CDS_FAILURE);
    assert(bst_search(tree, 100) == CDS_FAILURE);

    /*
        Tree structure should be:

                10
               /  \
              5    20
                  /  \
                15    30

        Inorder traversal should print:
        5 10 15 20 30
    */

    bst_inorder(tree);  /* Visual verification */

    bst_destroy(tree);
    return 0;
}
