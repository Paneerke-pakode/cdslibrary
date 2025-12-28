#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} node;

struct cds_bst
{
    node* root;
};

cds_bst* bst_create(void)
{
    cds_bst* tree = (cds_bst*)malloc(sizeof(cds_bst));
    if (!tree) return NULL;

    tree->root = NULL;
    return tree;
}

static node* create_node(int value)
{
    node* n = (node*)malloc(sizeof(node));
    if (!n) return NULL;

    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

static cds_status insert_node(node** root, int value)
{
    if ((*root) == NULL)
    {
        *root = create_node(value);
        return (*root) ? CDS_SUCCESS : CDS_OUT_OF_MEMORY;
    }

    if (value < (*root)->data)
        return insert_node(&(*root)->left, value);

    if (value > (*root)->data)
        return insert_node(&(*root)->right, value);

    return CDS_FAILURE; // duplicate
}

cds_status bst_insert(cds_bst* tree, int value)
{
    if (!tree) return CDS_NULL_PTR;
    return insert_node(&tree->root, value);
}

static cds_status search_node(const node* root, int value)
{
    if (!root) return CDS_FAILURE;

    if (value == root->data) return CDS_SUCCESS;

    if (value < root->data)
        return search_node(root->left, value);
    else
        return search_node(root->right, value);
}

cds_status bst_search(const cds_bst* tree, int value)
{
    if (!tree) return CDS_NULL_PTR;
    return search_node(tree->root, value);
}

static void inorder(const node* root)
{
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void bst_inorder(const cds_bst* tree) // inorder traversal -> sorted order. This is how we prove correctness
{
    if (!tree) return;
    inorder(tree->root);
    printf("\n");
}

static void destroy_nodes(node* root)
{
    if (root) return;

    destroy_nodes(root->left);
    destroy_nodes(root->right);
    free(root);
}

void bst_destroy(cds_bst* tree)
{
    if (!tree) return;
    destroy_nodes(tree->root);
    free(tree);
}
