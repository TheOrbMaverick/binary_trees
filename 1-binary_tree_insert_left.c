#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left child of another node
 * @parent: Pointer to the node to insert the left-child in
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	/* Check if the parent is NULL */
	if (parent == NULL)
	{
		return (NULL);
	}

	/* Create a new node */
	binary_tree_t *new_node = binary_tree_node(parent, value);

	/* If the parent already has a left child */
	if (parent->left != NULL)
	{
		/** Set the left child of the new node to the current
		 * left child of the parent 
		*/
		new_node->left = parent->left;
		/* Update the parent pointer of the current left child */
		new_node->left->parent = new_node;
	}

	/* Set the left child of the parent to the new node */
	parent->left = new_node;
	/* Return a pointer to the created node */
	return (new_node);
}
