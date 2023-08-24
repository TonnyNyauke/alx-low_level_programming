#include "lists.h"

/**
 * free_list - Frees the memory of a linked list.
 * @head: A pointer to the head of the linked list.
 *
 * Description: This function frees the memory allocated for each node
 *              and the duplicated strings within the nodes of the linked list.
 */
void free_list(list_t *head)
{
	list_t *current = head;

	while (current != NULL)
	{
		list_t *temp = current;
		current = current->next;
		free(temp->str);
		free(temp);
	}
}
