#include "lists.h"
#include <stdlib.h>

dlistint_t
*insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int i = 0;
	dlistint_t *temp;
	dlistint_t *prnode;
	dlistint_t *head = *h;

	temp = malloc(sizeof(dlistint_t));
	if (!temp)
		return (NULL);
	if (head)
	{
		while (head->next)
		{
			if (idx == i)
			{
				prnode = head->prev;
				temp->n = n;
				temp->next = head;
				temp->prev = prnode;
				head->prev = temp;
				head = temp;
				prnode->next = head;
				return (head);
			}
			head = head->next;
			i++;
		}
		if (idx > i)
			return (NULL);
		return (head);
	}
	return (NULL);
}
