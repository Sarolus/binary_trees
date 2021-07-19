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
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes.
 * @first: pointer to the first node.
 * @second: pointer to the second node.
 * Return: return a pointer to the lowest common ancestor node, otherwise NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t first_height, second_height;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	first_height = binary_tree_height(first);
	second_height = binary_tree_height(second);

	if (first->parent && first_height < second_height)
		return (binary_trees_ancestor(first->parent, second));
	else if (second->parent && first_height > second_height)
		return (binary_trees_ancestor(first, second->parent));
	else if (first->parent && second->parent)
		return (binary_trees_ancestor(first->parent, second->parent));

	return (NULL);
}
