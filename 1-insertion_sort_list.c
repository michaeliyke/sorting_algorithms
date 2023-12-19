#include "sort.h"

void swapper(listint_t *back, listint_t *front);

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm.
 * @list: A doubly linked list.
 *
 * Return: void.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/*** create 'sorted' pocket on the left of the list ***/
	current = (*list)->next; /* start with 2nd node */

	while (current != NULL) /* iterate list from second node */
	{
		node = current;		 /* set working node */
		current = current->next; /* switch nodes while iterating */

		while (node && node->prev) /* iterate backwards */
		{
			/* compare node with last node in left pocket */
			if (node->prev->n > node->n) /* if not sorted */
			{
				/* swap */
				swapper(node->prev, node);
				if (node->prev == NULL)
					*list = node;

				print_list(*list);
			}
			else /* if sorted */
			{
				/* move backward in 'pocket' to compare */
				node = node->prev;
			}
		}
	}
}

/**
 * swapper - Swaps 2 adjacent nodes of a doubly-linked list.
 * @back: The address of the first node.
 * @front: The address of second node.
 *
 * Return: void.
 */

void swapper(listint_t *back, listint_t *front)
{
	if (back->prev)
		back->prev->next = front;
	if (front->next)
		front->next->prev = back;

	back->next = front->next;
	front->prev = back->prev;
	back->prev = front;
	front->next = back;

	/* ensure list remains connected after swap */
	if (back->next)
		back->next->prev = back;
	if (front->prev)
		front->prev->next = front;
}
