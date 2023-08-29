#include "lists.h"
#include <limits.h> /* For INT_MAX */

/**
 * sum_listint - Returns the sum of all the data (n)
 * of a listint_t linked list.
 * @head: Pointer to the head of the linked list.
 * Return: The sum of all the data (n) or 0 if the list is empty.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *current;

	/* Return 0 for an empty list */
	if (head == NULL)
		return (0);

	current = head;

	while (current != NULL)
	{
		/* Handle integer overflow */
		if (sum > INT_MAX - current->n)
		{
			/* Handle overflow here, e.g., print error message or return an error code */
			return (0);
		}

		sum += current->n;
		current = current->next;
	}

	return (sum);
}

