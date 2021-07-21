#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: pointer to the root node of the tree to measure.
 * Return: return 0 if tree is NULL, otherwise return the height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l, height_r;

	if (tree == NULL)
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_height_level - Execute a function on the valid level.
 * @tree: pointer to the root node of the tree to browse.
 * @level: current level on a binary tree.
 * @func: pointer to a function to call for each node.
 */
void binary_tree_height_level(const binary_tree_t *tree,
			      size_t level, void(*func)(int))
{
	if (!tree || !func)
		return;

	if (level == 0)
		func(tree->n);
	else
	{
		binary_tree_height_level(tree->left, level - 1, func);
		binary_tree_height_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal.
 * @tree: pointer to the root node of the tree to browse.
 * @func: pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, height_level;

	if (!tree || !func)
		return;

	height = binary_tree_height(tree);

	for (height_level = 0; height_level <= height; height_level++)
	{
		binary_tree_height_level(tree, height_level, func);
	}
}
