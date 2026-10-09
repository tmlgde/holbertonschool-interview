#include <stdlib.h>
#include "lists.h"

/**
 * reverse_listint - Reverses a singly linked list in place
 * @head: Pointer to the first node of the list
 *
 * Return: Pointer to the new first node
 */
listint_t *reverse_listint(listint_t *head)
{
	listint_t *prev;
	listint_t *next;

	prev = NULL;
	while (head != NULL)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}

	return (prev);
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: Pointer to the pointer to the first node of the list
 *
 * Return: 1 if it is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow, *fast, *second, *p1, *p2;
	int result;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return (1);

	slow = *head;
	fast = *head;
	while (fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	second = reverse_listint(slow->next);

	result = 1;
	p1 = *head;
	p2 = second;
	while (p2 != NULL)
	{
		if (p1->n != p2->n)
		{
			result = 0;
			break;
		}
		p1 = p1->next;
		p2 = p2->next;
	}

	slow->next = reverse_listint(second);

	return (result);
}
