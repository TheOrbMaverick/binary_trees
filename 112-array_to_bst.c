#include "binary_trees.h"

/**
 * array_to_bst_helper - Recursive function to build a BST from a sorted array
 * @array: Pointer to the first element of the array
 * @start: Index of the first element of the subarray
 * @end: Index of the last element of the subarray
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst_helper(int *array, int start, int end)
{
    bst_t *root;
    int mid;

    /* Base case: When start index exceeds end index */
    if (start > end)
        return (NULL);

    /* Calculate the index of the middle element */
    mid = start + (end - start) / 2;

    /* Create a new node with the middle element */
    root = binary_tree_node(NULL, array[mid]);
    if (root == NULL)
        return (NULL);

    /* Recursively build the left subtree with elements to the left of the middle */
    root->left = array_to_bst_helper(array, start, mid - 1);

    /* Recursively build the right subtree with elements to the right of the middle */
    root->right = array_to_bst_helper(array, mid + 1, end);

    return (root);
}

/**
 * array_to_bst - Builds a Binary Search Tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
    /* Check if the array is empty */
    if (array == NULL || size == 0)
        return (NULL);

    /* Sort the array (if needed) */

    /* Call the helper function to recursively build the BST */
    return (array_to_bst_helper(array, 0, size - 1));
}
