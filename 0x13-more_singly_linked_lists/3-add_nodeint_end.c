#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the end of a listint_t list.
 * @head: A pointer to a pointer to the head of the list.
 * @n: The value to be added to the new node.
 *
 * Return: Address of the new element, or NULL if it fails.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_end_node = malloc(sizeof(listint_t));

	if (new_end_node == NULL)
		return (NULL);

	new_end_node->n = n;
	new_end_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_end_node;
	}
	else
	{
		listint_t *current_node = *head;
	
		while (current_node->next != NULL)
		{
			current_node = current_node->next;
		}
		current_node->next = new_end_node;
	}

	return (new_end_node);
}
