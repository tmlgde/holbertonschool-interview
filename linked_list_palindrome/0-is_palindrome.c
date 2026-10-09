#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: Pointer to the pointer to the first node of the list
 *
 * Return: 1 if it is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *current;
	int *tab;
	size_t size, i;

	if (head == NULL || *head == NULL)
		return (1);

	size = 0;
	current = *head;
	while (current != NULL)
	{
		current = current->next;
		size++;
	}

	tab = malloc(sizeof(int) * size);
	if (tab == NULL)
		return (0);

	current = *head;
	i = 0;
	while (current != NULL)
	{
		tab[i] = current->n;
		current = current->next;
		i++;
	}

	for (i = 0; i < size / 2; i++)
	{
		if (tab[i] != tab[size - 1 - i])
		{
			free(tab);
			return (0);
		}
	}

	free(tab);
	return (1);
}
