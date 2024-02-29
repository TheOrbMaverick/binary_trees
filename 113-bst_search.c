#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree (BST)
 * @tree: Pointer to the root node of the BST to search
 * @value: Value to search in the BST
 *
 * Return: Pointer to the node containing the value, or NULL if not found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
    /* Base cases: tree is NULL or value is found at the current node */
    if (tree == NULL || tree->n == value)
        return (bst_t *)tree;

    /* If value is less than the current node's value, search in the left subtree */
    if (value < tree->n)
        return bst_search(tree->left, value);

    /* If value is greater than the current node's value, search in the right subtree */
    return bst_search(tree->right, value);
}
