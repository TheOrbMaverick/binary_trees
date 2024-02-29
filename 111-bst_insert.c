#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: Value to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	/* If tree is NULL, allocate memory for a new node and make it the root */
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	/* If the value already exists in the tree, return NULL */
	if (value == (*tree)->n)
		return (NULL);

	/* If the value is less than the current node's value, insert it */
	if (value < (*tree)->n)
	{
		/* Recursively insert into the left subtree */
		if ((*tree)->left == NULL)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
		else
		{
			return (bst_insert(&((*tree)->left), value));
		}
	}
	/* If the value is greater than the current node's value, insert it */
	else
	{
		/* Recursively insert into the right subtree */
		if ((*tree)->right == NULL)
		{
			(*tree)->right = binary_tree_node(*tree, value);
			return ((*tree)->right);
		}
		else
		{
			return (bst_insert(&((*tree)->right), value));
		}
	}
}
