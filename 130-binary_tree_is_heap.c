#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree.
 * @index: The index of the current node.
 * @node_count: The total number of nodes in the tree.
 *
 * Return: If the tree is complete, 1, otherwise, 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **queue, *temp;
	int front, rear;
	int flag; /* This flag indicates if we have encountered a non-full node */

	front = 0;
	rear = 0;
	flag = 0;

	if (tree == NULL)
		return (0);

	/* Create a queue to perform level-order traversal */
	queue = malloc(sizeof(binary_tree_t *) * 1024);
	if (queue == NULL)
		return (0);

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		temp = queue[front++];

		/* If we have encountered a non-full node, all subsequent nodes must be leaf nodes */
		if (temp == NULL)
			flag = 1;
		else
		{
			/* If we have previously encountered a non-full node, but the current node is not a leaf, it's not a complete tree */
			if (flag == 1 && (temp->left != NULL || temp->right != NULL))
			{
				free(queue);
				return (0);
			}

			/* Enqueue left child */
			queue[rear++] = (binary_tree_t *)temp->left;

			/* Enqueue right child */
			queue[rear++] = (binary_tree_t *)temp->right;
		}
	}

	free(queue);
	return (1);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the tree, or 0 if tree is NULL.
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
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid Max Binary Heap, otherwise 0.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	size_t height;
	unsigned int index = 0, node_count = 0;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);

	while (index < height)
	{
		if (!binary_tree_is_complete(tree))
			return (0);

		index++;
		node_count = (2 * node_count) + 1;
	}

	return (1);
}
