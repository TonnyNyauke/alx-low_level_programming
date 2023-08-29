#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at a given index in a list.
 * @head: Pointer to a pointer to the head of the linked list.
 * @index: Index of the node to delete. Index starts at 0.
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int count = 0;
	listint_t *current, *temp;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	current = *head;
	while (current != NULL)
	{
		if (count == index - 1 && current->next != NULL)
		{
			temp = current->next;
			current->next = temp->next;
			free(temp);
			return (1);
		}

		current = current->next;
		count++;
	}

	return (-1);
}

