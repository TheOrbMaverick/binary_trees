#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right child of another node
 * @parent: Pointer to the parent node
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	/* If parent is NULL, return NULL */
	if (parent == NULL)
	{
		return (NULL);
	}

	/* Create a new node */
	binary_tree_t *new_node = binary_tree_node(parent, value);

	/* If parent already has a right child, adjust pointers */
	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		new_node->right->parent = new_node;
	}

	/* Set the new node as the right child of the parent */
	parent->right = new_node;

	return (new_node);
}
