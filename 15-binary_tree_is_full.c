#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	/* If tree is NULL, it's full by definition */
	if (tree == NULL)
		return (1);

	/* If the tree has no children, it's full */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* If the tree has both children, check recursively */
	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	/* If the tree has only one child, it's not full */
	return (0);
}
