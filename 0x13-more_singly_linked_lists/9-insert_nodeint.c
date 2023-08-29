#include "lists.h"

/**
 * insert_nodeint_at_index - inserts new node at a given position
 * @head: pointer to the pointer to the head of the list
 * @idx: list where new node is added
 * @n: data of the new node
 * Return: address of new node, NULL on failure
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_nodes, *holmes;
	unsigned int u;

	if (head == NULL)
		return (NULL);

	new_nodes = malloc(sizeof(listint_t));

	if (new_nodes == NULL)
		return (NULL);

	new_nodes->n = n;

	if (idx == 0)
	{
		new_nodes->next = *head;
		*head = new_nodes;

		return (new_nodes);
	}
	holmes = *head;

	for (u = 0; u < idx - 1 && holmes != NULL; u++)
	{
		holmes = holmes->next;
	}

	if (holmes == NULL)
	{
		free(new_nodes);
		return (NULL);
	}

	new_nodes->next = holmes->next;
	holmes->next = new_nodes;

	return (new_nodes);
}
