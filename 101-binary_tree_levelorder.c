#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order
 *                          traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: This function traverses the binary tree using level-order
 *              traversal and calls the given function for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    binary_tree_t **queue;
    const binary_tree_t *current;

    if (tree == NULL || func == NULL)
        return;

    /* Create a queue to store nodes */
    queue = malloc(sizeof(binary_tree_t *) * 1024);
    if (queue == NULL)
        return;

    int front = 0, rear = 0;

    /* Enqueue the root node */
    queue[rear++] = (binary_tree_t *)tree;

    /* Perform level-order traversal */
    while (front < rear)
    {
        /* Dequeue a node and call the function */
        current = queue[front++];
        func(current->n);

        /* Enqueue left child if exists */
        if (current->left != NULL)
            queue[rear++] = (binary_tree_t *)current->left;

        /* Enqueue right child if exists */
        if (current->right != NULL)
            queue[rear++] = (binary_tree_t *)current->right;
    }

    free(queue);
}
