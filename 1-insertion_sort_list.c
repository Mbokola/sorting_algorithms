#include "sort.h"
/**
 *insertion_sort_list - Sort list using insertion algo
 *@list: list to sort
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *ptr = NULL, *tmp;

	if (list)
		ptr = *list;
	if (ptr)
	{
		while (ptr->next)
		{
			if (ptr->n <= ptr->next->n)
				ptr = ptr->next;
			else
			{
				tmp = ptr->next;
				if (tmp->next)
					tmp->next->prev = ptr;
				if (ptr->prev)
					ptr->prev->next = tmp;
				tmp->prev = ptr->prev;
				ptr->next = tmp->next;
				tmp->next = ptr;
				ptr->prev = tmp;
				if (tmp->prev)
					ptr = tmp->prev;
				if (!tmp->prev)
					*list = tmp;
				print_list(*list);
			}
		}

	}
}
