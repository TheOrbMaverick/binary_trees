#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    size_t size_left, size_right;

    /* If tree is NULL, return 0 */
    if (tree == NULL)
        return 0;

    /* Recursively compute the size of the left subtree */
    size_left = binary_tree_size(tree->left);

    /* Recursively compute the size of the right subtree */
    size_right = binary_tree_size(tree->right);

    /* Return the sum of the sizes of the left and right subtrees, plus 1 for the current node */
    return size_left + size_right + 1;
}
