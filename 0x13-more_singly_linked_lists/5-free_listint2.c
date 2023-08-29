#include "lists.h"

/**
 * free_listint2 - Frees a listint_t linked list and sets the head to NULL
 * @head: Pointer to a pointer to the head of the linked list
 *
 * This function frees all the nodes in a linked list and sets the head pointer
 * to NULL to indicate that the list is now empty.
 */
void free_listint2(listint_t **head)
{
	listint_t *current;

	/* Check if the head pointer is NULL or points to NULL */
	if (head == NULL || *head == NULL)
		return;
	/* Loop through the linked list and free each node */
	while (*head != NULL)
	{
		current = *head;         /* Store the current node in current */
		*head = (*head)->next;   /* Update head to point to the next node */
		free(current);           /* Free the current node */
	}
}
