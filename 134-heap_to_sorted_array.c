#include "binary_trees.h"

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
	last_node = *root;

	while (last_node->left != NULL || last_node->right != NULL)
	{
		if (last_node->right == NULL || last_node->left->n > last_node->right->n)
			last_node = last_node->left;
		else
			last_node = last_node->right;
	}

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

/**
 * in_order_traversal - Performs in-order traversal of the heap
 * @heap: Pointer to the root node of the heap
 * @sorted_array: Pointer to the sorted array
 * @index: Pointer to the current index in the sorted array
 */
void in_order_traversal(const heap_t *heap, int *sorted_array, size_t *index)
{
	if (heap == NULL)
		return;

	in_order_traversal(heap->left, sorted_array, index);
	sorted_array[(*index)++] = heap->n;
	in_order_traversal(heap->right, sorted_array, index);
}

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
 * @heap: Pointer to the root node of the heap
 * @size: Pointer to store the size of the array
 *
 * Return: Pointer to the sorted array of integers
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *sorted_array;
	size_t array_size = 0;

	if (heap == NULL || size == NULL)
		return (NULL);

	array_size = heap_size(heap);
	sorted_array = malloc(sizeof(int) * array_size);
	if (sorted_array == NULL)
		return (NULL);

	*size = 0;
	in_order_traversal(heap, sorted_array, size);

	return (sorted_array);
}
