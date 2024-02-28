#include "binary_trees.h"

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
