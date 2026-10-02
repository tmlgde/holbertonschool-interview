#include "binary_trees.h"

/**
 * binary_tree_size - Counts the nodes of a binary tree
 * @tree: Pointer to the root of the tree
 *
 * Return: Number of nodes, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) +
		binary_tree_size(tree->right));
}

/**
 * heap_get_node - Gets the node at a given index in a complete tree
 * @root: Pointer to the root of the heap
 * @index: Index of the node (root is 1, then level by level, left to right)
 *
 * Return: Pointer to the node at this index
 */
heap_t *heap_get_node(heap_t *root, size_t index)
{
	size_t mask;

	mask = 1;
	while (mask <= index / 2)
		mask <<= 1;
	mask >>= 1;

	while (mask > 0)
	{
		if (index & mask)
			root = root->right;
		else
			root = root->left;
		mask >>= 1;
	}

	return (root);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent;
	heap_t *new_node;
	size_t index;
	int tmp;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	index = binary_tree_size(*root) + 1;
	parent = heap_get_node(*root, index / 2);
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (index & 1)
		parent->right = new_node;
	else
		parent->left = new_node;

	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		tmp = new_node->n;
		new_node->n = new_node->parent->n;
		new_node->parent->n = tmp;
		new_node = new_node->parent;
	}

	return (new_node);
}
