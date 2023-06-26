#include "sort.h"
/**
 *insertion_sort_list - Sort list using insertion algo
 *@list: list to sort
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr;

	if (*list)
	{
		ptr = (*list)->next;
		while (ptr)
		{
			while (ptr->n < ptr->prev->n && ptr->prev->prev)
			{
				ptr->prev = ptr->prev->prev;
				ptr->prev->next->next = ptr->next;
				ptr->prev->next->prev = ptr;
				ptr->next = ptr->prev->next;
				ptr->prev->next = ptr;
				print_list(*list);
				if (ptr->next->next)
					ptr->next->next->prev = ptr->next;
				if (!ptr->prev->prev && ptr->n < ptr->prev->n)
				{

					ptr->prev->next = ptr->next;
					ptr->prev->prev = ptr;
					ptr->next->prev = ptr->prev;
					ptr->next = ptr->prev;
					ptr->prev = NULL;
					*list = ptr;
					print_list(*list);
					ptr = ptr->next;
				}

			}
			if (ptr)
				ptr = ptr->next;
		}
	}
}
