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

	if (tree == NULL)
		return (0);

	height_left = binary_tree_height(tree->left);
	height_right = binary_tree_height(tree->right);

	return ((height_left > height_right ? height_left : height_right) + 1);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, i;
	int perfect_left, perfect_right;

	/* If tree is NULL, it's not perfect */
	if (tree == NULL)
		return (0);

	/* Calculate the height of the tree */
	height = binary_tree_height(tree);

	/* Check if the tree is full */
	if (!binary_tree_is_full(tree))
		return (0);

	/* Check if all levels are fully filled */
	for (i = 0; i < height - 1; i++)
	{
		perfect_left = binary_tree_height(tree->left);
		perfect_right = binary_tree_height(tree->right);
		if (perfect_left != perfect_right)
			return (0);
		tree = tree->left;
	}

	return (1);
}
