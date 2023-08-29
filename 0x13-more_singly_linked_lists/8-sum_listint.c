#include "lists.h"

/**
 * sum_listint - returns the sum of all data of a listint_t linked list
 * @head: pointer to the head
 * Return: if list empty return 0
 */

int sum_listint(listint_t *head)
{
	int sums = 0;

	while (head != NULL)
	{
		sums += head->n;

		head = head->next;
	}

	return (sums);
}
