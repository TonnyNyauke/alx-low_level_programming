#include "lists.h"

/**
 * add_node - Adds a new node at the beginning of a linked list.
 * @head: A pointer to the head of the linked list.
 * @str: The string to be duplicated and stored in the new node.
 *
 * Return: A pointer to the newly created node, or NULL on failure.
 */
list_t *add_node(list_t **head, const char *str)
{
	if (str == NULL)
		return (NULL);

	list_t *new_node;
	new_node = malloc(sizeof(list_t));

	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL) {
		free(new_node);
		return (NULL);
	}

	new_node->len = 0;
	while (str[new_node->len] != '\0') 
	{
		new_node->len++;
	}

	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
