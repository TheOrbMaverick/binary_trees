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

	/* If the tree has only one child, it's not full */
	if ((tree->left && !tree->right) || (!tree->left && tree->right))
		return (0);

	/* If the tree has both children, check recursively */
	return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
}

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
