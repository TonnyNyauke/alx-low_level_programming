#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position in a list.
 * @head: Pointer to a pointer to the head of the linked list.
 * @idx: Index where the new node should be inserted. Index starts at 0.
 * @n: Data to be stored in the new node.
 * Return: The address of the new node, or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int count = 0;
	listint_t *new_node, *current;

	if (head == NULL)
		return (NULL);

	if (idx == 0)
	{
		new_node = malloc(sizeof(listint_t));
		if (new_node == NULL)
			return (NULL);

		new_node->n = n;
		new_node->next = *h;
		*head = new_node;
		return (new_node);
	}

	current = *head;
	while (current != NULL)
	{
		if (count == idx - 1)
		{
			new_node = malloc(sizeof(listint_t));
			if (new_node == NULL)
				return (NULL);

			new_node->n = n;
			new_node->next = current->next;
			current->next = new_node;
			return (new_node);
		}

		current = current->next;
		count++;
	}

	return (NULL);
}

