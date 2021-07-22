#include "binary_trees.h"

/**
 * node_count - Count the number of node in a tree.
 *  @tree: pointer to the root node of the tree to measure.
 * Return: return the number of node.
 */
int node_count(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	
	return (1 + node_count(tree->left) + node_count(tree->right))
}

/**
 * is_complete - Check if a tree is complete.
 * @tree: pointer to the root node of the tree to check.
 * @index: index of the nodes.
 * @node: specified node.
 * Return: return 1 on success, otherwise 0.
 */
int is_complete(const binary_tree_t *tree, int index, int node)
{
	if (tree == NULL)
		return (1);
	
	if (index >= node)
		return (0);
	
	return (
		is_complete(tree->left, 2 * index + 1, node) &&
		is_complete(tree->right, 2 * index + 2, node)
	);
}

/**
 * binary_tree_is_complete - Check if a tree is complete
 * @tree: pointer to the root node of the tree to check.
 * Return: return 1 on success, otherwise 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int node = 0;

	if (tree == NULL)
		return (0);

	node = ;

	if (node > 0)
		return (is_complete(tree, 0, node))
	else
		return (0);
}
