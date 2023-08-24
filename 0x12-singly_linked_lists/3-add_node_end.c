#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to the pointer to the head of the list
 * @str: string to be duplicated and stored in the new node
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_nodes;
	list_t *lst_nodes;
	size_t len = 0;

	new_nodes = malloc(sizeof(list_t));
	if (new_nodes == NULL)
	{
		return (NULL);
	}
	while (str[len] != '\0')
	{
		len++;
	}
	new_nodes->str = strdup(str);
	new_nodes->len = len;
	new_nodes->next = NULL;
	if (*head == NULL)
	{
		*head = new_nodes;
		return (new_nodes);
	}
	lst_nodes = *head;
	while (lst_nodes->next != NULL)
	{
		lst_nodes = lst_nodes->next;
	}
	lst_nodes->next = new_nodes;
	return (new_nodes);
}
