#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depht of a binary tree.
 * @tree: pointer to the root node of the tree to measure.
 * Return: return 0 if tree is NULL, otherwise return the depth.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL || tree->parent == NULL)
		return (0);

	return (binary_tree_depth(tree->parent) + 1);
}
