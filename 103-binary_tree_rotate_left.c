#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree.
 * @tree: pointer to the root node of the tree to rotate.
 * Return: return a pointer to the new root node of the tree once rotated
 * otherwise NULL it there's no tree.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *parent, *child_r;

	if (tree == NULL)
		return (NULL);

	parent = tree->parent;
	child_r = tree->right;
	tree->right = child_r->left;

	child_r->left = tree;
	tree->parent = child_r;
	child_r->parent = parent;

	return (child_r);
}
