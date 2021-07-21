#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree.
 * @tree: pointer to the root node of the tree to rotate.
 * Return: return a pointer to the new root node of the tree once rotated
 * otherwise NULL it there's no tree.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *parent, *child_l;

	if (tree == NULL)
		return (NULL);

	if (tree->left)
	{
		parent = tree->parent;
		child_l = tree->left;
		tree->left = child_l->right;

		child_l->right = tree;
		tree->parent = child_l;
		child_l->parent = parent;
	}

	return (child_l);
}
