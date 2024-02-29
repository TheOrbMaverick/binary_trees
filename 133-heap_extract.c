#include "binary_trees.h"


binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;
	
	new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

/**
 * heap_size - Computes the size of a heap tree
 * @tree: Pointer to the root node of the heap
 *
 * Return: Size of the heap
 */
size_t heap_size(const heap_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + heap_size(tree->left) + heap_size(tree->right));
}

/**
 * get_last_node - Finds the last node of the heap
 * @root: Pointer to the root node of the heap
 *
 * Return: Pointer to the last node of the heap
 */
heap_t *get_last_node(heap_t *root)
{
	if (root == NULL)
		return (NULL);

	if (root->left == NULL && root->right == NULL)
		return (root);

	if (heap_size(root->left) > heap_size(root->right))
		return (get_last_node(root->left));
	else
		return (get_last_node(root->right));
}

/**
 * heapify_down - Heapify the heap down from the root
 * @root: Pointer to the root node of the heap
 */
void heapify_down(heap_t **root)
{
	heap_t *current = *root;
	heap_t *max_child = NULL;
	int temp;

	while (1)
	{
		max_child = current->left;

		if (max_child == NULL)
			break;

		if (current->right != NULL && current->right->n > max_child->n)
			max_child = current->right;

		if (max_child->n > current->n)
		{
			temp = current->n;
			current->n = max_child->n;
			max_child->n = temp;
			current = max_child;
		}
		else
		{
			break;
		}
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: The value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *last_node, *current;

	if (root == NULL || *root == NULL)
		return (0);

	value = (*root)->n;
	last_node = get_last_node(*root);

	if (*root == last_node)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	(*root)->n = last_node->n;

	current = last_node->parent;
	if (current->left == last_node)
		current->left = NULL;
	else
		current->right = NULL;

	free(last_node);

	heapify_down(root);

	return (value);
}
