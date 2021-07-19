#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree.
 * @tree: pointer to the root node of the tree to measure.
 * Return: return 0 if tree is NULL, otherwise return the number of leaves.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t height_l, height_r;

	if (tree == NULL)
		return (0);

	height_l = binary_tree_leaves(tree->left);
	height_r = binary_tree_leaves(tree->right);

	if (!tree->left && !tree->right)
		return (1);

	return (height_l + height_r);
}
