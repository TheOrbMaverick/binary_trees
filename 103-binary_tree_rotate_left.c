#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root = tree->right;
	binary_tree_t *temp = new_root->left;
	if (tree == NULL || tree->right == NULL)
		return (NULL);

	binary_tree_t *new_root = tree->right;
	binary_tree_t *temp = new_root->left;

	new_root->left = tree;
	tree->parent = new_root;
	tree->right = temp;

	if (temp != NULL)
		temp->parent = tree;

	new_root->parent = NULL;

	return (new_root);
}