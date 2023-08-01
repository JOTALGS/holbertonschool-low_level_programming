#include "lists.h"
#include <stdlib.h>

dlistint_t
*insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int i = 0;
	dlistint_t *temp;
	dlistint_t *nxnode;
	dlistint_t *head = *h;

	temp = malloc(sizeof(dlistint_t));
	if (!temp)
		return (NULL);
	if (head)
	{
		while (head->next)
		{
			if (idx == i + 1)
			{
				nxnode = head->next;
				temp->n = n;
				temp->prev = head;
				temp->next = head->next;
				head->next = temp;
				head = temp;
				nxnode->prev = temp;
				return (*h);
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