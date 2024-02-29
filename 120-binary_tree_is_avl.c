#include "binary_trees.h"
#include <limits.h>

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree.
 * Return: Height of the tree, or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree);

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST.
 * @tree: Pointer to the root node of the tree.
 * @min: Minimum value allowed in the tree (optional).
 * @max: Maximum value allowed in the tree (optional).
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree, int min, int max);

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 * @tree: Pointer to the root node of the tree.
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (!binary_tree_is_bst(tree, INT_MIN, INT_MAX))
		return (0);

	if (abs(binary_tree_height(tree->left) - binary_tree_height(tree->right)) > 1)
		return (0);

	if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
		return (0);

	return (1);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
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
 * binary_tree_is_bst - Checks if a binary tree is a valid BST.
 */
int binary_tree_is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (binary_tree_is_bst(tree->left, min, tree->n) &&
			binary_tree_is_bst(tree->right, tree->n, max));
}
