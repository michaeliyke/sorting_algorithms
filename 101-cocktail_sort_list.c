#include "sort.h"

void cocktail_swap(listint_t *back, listint_t *front, listint_t **list);

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail shaker sort algorithm.
 * @list: A doubly linked list.
 *
 * Return: void.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node, *current;
	int flag;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list);
	do {
		flag = 0; /* set flag for swap to false */
		while (current->next)
		{
			node = current->next;
			/* compare node with next node in list */
			if (node && current->n > node->n)
			{
				cocktail_swap(current, node, list);
				flag = 1; /* update flag */
				print_list((*list));
			}
			else /* already sorted */
				current = current->next;
		}

		current = current->prev;
		while (current->prev)
		{
			node = current->prev;
			/* compare node with previous node in list */
			if (node && current->n < node->n)
			{
				cocktail_swap(node, current, list);
				flag = 1; /* update flag */
				print_list((*list));
			}
			else /* already sorted */
				current = current->prev;
		}
		current = current->next; /* set to unsorted part */
	} while (flag); /* loop till no swap */
}

/**
 * cocktail_swap - Swaps 2 adjacent nodes of a doubly-linked list.
 * @back: The address of the first node.
 * @front: The address of second node.
 * @list: A linked list.
 *
 * Return: void.
 */

void cocktail_swap(listint_t *back, listint_t *front, listint_t **list)
{
	if (!(back->prev)) /* if 'back' is the first node in list */
	{
		back->next = front->next;
		if (front->next) /* if 'front' is not the last node */
			front->next->prev = back;
		front->next = back;
		front->prev = NULL;
		back->prev = front;
		*list = front;
	}
	else /* if 'back' is not the first node in list */
	{
		front->prev->next = front->next;
		if (front->next) /* if 'front' is not the last node */
			front->next->prev = front->prev;
		back->prev->next = front;
		front->prev = back->prev;
		back->prev = front;
		front->next = back;
	}
}
