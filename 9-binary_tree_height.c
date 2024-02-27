#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left, height_right;

	/* If tree is NULL or has no children, return 0 */
	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	/* Recursively compute the height of the left subtree */
	height_left = binary_tree_height(tree->left);

	/* Recursively compute the height of the right subtree */
	height_right = binary_tree_height(tree->right);

	/** Return the maximum height of the left and right subtrees, plus 1 */
	return ((height_left > height_right ? height_left : height_right) + 1);
}
