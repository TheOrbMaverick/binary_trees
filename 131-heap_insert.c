#include "binary_trees.h"

/**
 * heap_insert - Inserts a value in Max Binary Heap.
 * @root: A double pointer to the root node of the Heap.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	/* Create a new node */
	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);

	/* If the heap is empty, set the new node as the root */
	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}

	/* Find the parent of the new node */
	parent = *root;
	while (parent->left != NULL)
	{
		if (parent->right == NULL)
			break;
		parent = parent->left;
	}

	/* Insert the new node at the bottom level and to the rightmost position */
	if (parent->left == NULL)
		parent->left = new_node;
	else
		parent->right = new_node;

	new_node->parent = parent;

	/* Restore the Max Heap property */
	while (new_node->parent != NULL && new_node->n > new_node->parent->n)
	{
		/* Swap the new node with its parent */
		new_node->n ^= new_node->parent->n;
		new_node->parent->n ^= new_node->n;
		new_node->n ^= new_node->parent->n;

		new_node = new_node->parent;
	}

	return (new_node);
}
