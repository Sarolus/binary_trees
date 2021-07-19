#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child
 * in a binary tree.
 * @tree: pointer to the root node of the tree to measure.
 * Return: return 0 if tree is NULL, otherwise return the number
 * of node with at least 1 child.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t height_l, height_r;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	height_l = binary_tree_nodes(tree->left);
	height_r = binary_tree_nodes(tree->right);

	return (height_l + height_r + 1);
}
