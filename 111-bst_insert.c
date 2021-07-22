#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree.
 * @tree: pointer to the root node of the tree to check.
 * @value: value to insert.
 * Return: return a pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *tmp;

	if (*tree == NULL || tree == NULL)
	{
		new = binary_tree_node(NULL, value);
		*tree = new;
		return (new);
	}

	tmp = *tree;

	while (tmp != NULL)
	{
		if (value == tmp->n)
			return (NULL);

		if (tmp->n > value)
		{
			if (tmp->left == NULL)
			{
				tmp->left = binary_tree_node(tmp, value);
				return (tmp->left);
			}
			tmp = tmp->left;
		}
		else if (tmp->n < value)
		{
			if (tmp->right == NULL)
			{
				tmp->right = binary_tree_node(tmp, value);
				return (tmp->right);
			}
			tmp = tmp->right;
		}
	}

	return (NULL);
}
