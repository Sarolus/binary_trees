#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to measure.
 * Return: return 0 if tree is NULL and not full, otherwise
 * return 1 if full.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	size_t height_l, height_r;

	if (tree == NULL)
		return (0);
	
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	height_l = binary_tree_is_full(tree->left);
	height_r = binary_tree_is_full(tree->right);

	return (height_l * height_r);
}
