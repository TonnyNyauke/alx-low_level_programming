#include "lists.h"

/**
 * free_listint_safe - frees a linked list safely
 * @h: pointer to a pointer to the head of the list
 *
 * Return: the number of nodes in the list that were freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *slow, *fast, *temp;
	size_t count = 0;

	if (h == NULL || *h == NULL)
		return (0);

	slow = *h;
	fast = (*h)->next;

	while (fast != NULL && fast->next != NULL)
	{
		if (slow == fast)
			break;

		slow = slow->next;
		fast = fast->next->next;
	}

	if (slow == fast)
	{
		printf("Error: loop detected in linked list\n");
		return (0);
	}

	slow = *h;
	while (slow != NULL)
	{
		temp = slow;
		slow = slow->next;
		free(temp);
		count++;
	}

	*h = NULL;

	return (count);
}

