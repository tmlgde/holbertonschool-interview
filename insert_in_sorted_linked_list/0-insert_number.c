#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to pointer to the head of the list
 * @number: number to insert
 *
 * Return: address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new;
    listint_t *precedent;
    listint_t *courant;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);
    new->n = number;

    if (*head == NULL || number < (*head)->n)
    {
        new->next = *head;
        *head = new;
        return (new);
    }

    precedent = NULL;
    courant = *head;
    while (courant != NULL && number > courant->n)
    {
        precedent = courant;
        courant = courant->next;
    }

    new->next = courant;
    precedent->next = new;

    return (new);
}
