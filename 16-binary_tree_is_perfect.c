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
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to measure.
 * Return: return 0 if tree is NULL and not perfect, otherwise
 * return 1 if perfect.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height_l, height_r, height_check, perfect_l, perfect_r;

	if (tree == NULL)
		return (0);

	height_l = binary_tree_height(tree->left);
	height_r = binary_tree_height(tree->right);
	height_check = height_l == height_r ? 1 : 0;

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	perfect_l = binary_tree_is_perfect(tree->left);
	perfect_r = binary_tree_is_perfect(tree->right);

	return (height_l * height_r * height_check);
}
