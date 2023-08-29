#include "lists.h"

/**
 * print_listint - Prints all elements of a listint_t linked list.
 * @h: Pointer to the head of the list.
 *
 * Return: Number of nodes in the list.
 */
size_t print_listint(const listint_t *h)
{
	size_t no_of_nodes = 0;

	if (h == NULL)
		return (0);

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		no_of_nodes++;
	}

	return (no_of_nodes);
}

