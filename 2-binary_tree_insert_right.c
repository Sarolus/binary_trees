#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: parent node.
 * @value: value of the new node.
 * Return: return a pointer to the created node, or NULL on failure
 * or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right;

	if (parent == NULL)
		return (NULL);

	right = binary_tree_node(parent, value);

	if (right == NULL)
		return (NULL);

	right->right = parent->right;

	if (right->right != NULL)
		right->right->parent = right;

	parent->right = right;

	return (right);
}
