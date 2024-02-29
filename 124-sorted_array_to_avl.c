#include "binary_trees.h"

avl_t *sorted_array_to_avl_helper(int *array, int start, int end);

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (sorted_array_to_avl_helper(array, 0, size - 1));
}

/**
 * sorted_array_to_avl_helper - Helper function to build AVL tree recursively
 * @array: Pointer to the first element of the array
 * @start: Index of the start of the subarray
 * @end: Index of the end of the subarray
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl_helper(int *array, int start, int end)
{
	int mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	/* Find middle element of the array */
	mid = (start + end) / 2;

	/* Create a new node with the middle element */
	root = binary_tree_node(NULL, array[mid]);
	if (root == NULL)
		return (NULL);

	/* Recursively construct left and right subtrees */
	root->left = sorted_array_to_avl_helper(array, start, mid - 1);
	root->right = sorted_array_to_avl_helper(array, mid + 1, end);

	/* Return the root of the constructed AVL tree */
	return (root);
}
