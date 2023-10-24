#include "sort.h"
/**
 * insertion_sort_list -  a function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 * @list: doubly linked head
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev_prev, *prev, *current_1, *current_next;

	if (list == NULL)
		return;
	current = *list;

	while (current)
	{
		if (current->prev && current->prev->n > current->n)
		{
			/**Store the necessary pointers for swapping**/
			prev_prev = current->prev->prev;
			prev = current->prev;
			current_1 = current;
			current_next = current->next;

			/**Adjust the pointers to swap the nodes**/
			prev->next = current_next;

			if (current_next)
				current_next->prev = prev;

			current_1->prev = prev_prev;
			current_1->next = prev;

			if (prev_prev)
				prev_prev->next = current_1;
			else
				*list = current_1;
			prev->prev = current_1;
			current = *list;
			print_list(*list);
			continue; /**Continue to the next iteration**/
		}
		else
			current = current->next;
	}
}
