#include "sort.h"
/**
 * insertion_sort_list -  a function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 * @list: doubly linked head
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL;
	listint_t *current, *next, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = *list;
	while (current != NULL)
	{
		next = current->next;
		if (sorted == NULL || current->n <= sorted->n)
		{
			current->next = sorted;
			current->prev = NULL;
			if (sorted != NULL)
				sorted->prev = current;
		}
		else
		{
			temp = sorted;
			while (temp->next != NULL && current->n > temp->next->n)
				temp = temp->next;
			current->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = current;
			temp->next = current;
			current->prev = temp;
		}
		current = next;
	}
	*list = sorted;
}
