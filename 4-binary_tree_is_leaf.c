#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf
 * @node: Pointer to the node to check
 *
 * Return: 1 if node is a leaf, 0 otherwise
 */

int binary_tree_is_leaf(const binary_tree_t *node) {
    /* If node is NULL, it is not a leaf */
    if (node == NULL) {
        return 0;
    }

    /* If node has no children, it is a leaf */
    if (node->left == NULL && node->right == NULL) {
        return 1;
    }

    /* If node has at least one child, it is not a leaf */
    return 0;
}
