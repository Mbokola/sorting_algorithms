#include "sort.h"

/**
 * insertion_sort_list - sorting using insertion sort
 * @list: double pointer to head of the list to sort
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *current, *srt;

	if (*list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		temp = current->next;
		srt = current->prev;
		while (srt != NULL && srt->n > current->n)
		{
			srt->next = current->next;
			if (current->next != NULL)
				current->next->prev = srt;
			current->prev = srt->prev;
			current->next = srt;
			if (srt->prev != NULL)
				srt->prev->next = current;
			else
				*list = current;
			srt->prev = current;
			srt = current->prev;
			print_list(*list);
		}
		current = temp;
	}
}
