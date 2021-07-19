#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: parent node.
 * @value: value of the new node.
 * Return: return a pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left;

	if (parent == NULL)
		return (NULL);

	left = binary_tree_node(parent, value);

	if (left == NULL)
		return (NULL);

	left->left = parent->left;

	if (left->left != NULL)
		left->left->parent = left;
	
	parent->left = left;

	return (left);
}
