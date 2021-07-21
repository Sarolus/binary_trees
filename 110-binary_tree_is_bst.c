#include "binary_trees.h"

/**
 * binary_tree_check_node - Compare node in order to check if a given
 * binary tree is valid or not.
 * @tree: pointer to the root node of the tree to check.
 * @min: min allowed value.
 * @max: max allowed value.
 * Return: return 1 if the node comparison is valid, otherwise return 0.
 */
int binary_tree_check_node(const binary_tree_t *tree, int min, int max)
{

	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (
	    binary_tree_check_node(tree->left, min, tree->n - 1) &&
	    binary_tree_check_node(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree.
 * @tree: pointer to the root node of the tree to check.
 * Return: return 1 if the tree is a valid binary search tree.
 * otherwise return 0.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_check_node(tree, INT_MIN, INT_MAX));
}
