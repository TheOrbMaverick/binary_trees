#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	/* Base cases */
	if (first == NULL || second == NULL)
		return (NULL);
	
	/* If either node is the ancestor of the other, return that node */
	if (first == second)
		return ((binary_tree_t *)first);
	
	/* Check if first is an ancestor of second */
	if (binary_tree_is_descendant(second, first))
		return ((binary_tree_t *)first);

	/* Check if second is an ancestor of first */
	if (binary_tree_is_descendant(first, second))
		return ((binary_tree_t *)second);

	/* Traverse upwards until we find a common ancestor */
	return (binary_trees_ancestor(first->parent, second->parent));
}

/**
 * binary_tree_is_descendant - Checks if a node is a descendant of another node
 * @node: Pointer to the potential descendant node
 * @ancestor: Pointer to the potential ancestor node
 *
 * Return: 1 if node is a descendant of ancestor, 0 otherwise
 */
int binary_tree_is_descendant(const binary_tree_t *node, const binary_tree_t *ancestor)
{
	if (node == NULL)
		return 0;
	if (node == ancestor)
		return 1;
	return (binary_tree_is_descendant(node->parent, ancestor));
}
