#include "lists.h"

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

	if (head == NULL)
		return (0); /* Return 0 for an empty list */

	current = head;

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;

		/* Handle integer overflow */
		if (sum < 0) /* Overflow occurred */
		{
			/* Print an error message or handle the overflow as needed */
			return (0); /* Return 0 to indicate failure */
		}
	}

	return (sum);
}

