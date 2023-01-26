#include "sort.h"

int compare_nodes(listint_t *curr);
void swap_nodes(listint_t **list, listint_t *curr);

/**
 * insertion_sort_list - sorts a doubly-linked list using insertion sort.
 * @list: the list to sort in ascending order of their integer data field.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *next, *curr, *prev;
	int to_swap, a = 0;

	(void)a;
	if (!list || *list == NULL || (*list)->next == NULL)
	{
		/* Empty or single-element list */
		return;
	}

	next = (*list)->next;
	while (next)
	{
		curr = next;
		prev = next->prev;
		if (curr->n < prev->n)
		{
			/* Insertion/swapping to occur at some point */
			to_swap = 1;
			while (to_swap)
			{
				/* Recursively swap and compare until no swapping needs to be done */
				swap_nodes(list, curr); /* swap node @curr with previous node */
				print_list(*list);
				to_swap = compare_nodes(curr); /* check if node @curr needs swapping */
			}
		}
		next = next->next; /* always hold address of next node to compare */
	}
}



/**
 * swap_nodes - swap @curr node with previous node.
 * @list: address of head of doubly-linked list being sorted.
 * @curr: node to swap with its prev.
 */
void swap_nodes(listint_t **list, listint_t *curr)
{
	listint_t *currNext, *currPrev;

	currNext = curr->next;
	currPrev = curr->prev;

	if (currPrev == *list)
	{
		*list = curr; /* update list head */
	}

	/* Close gap left by @curr */
	currPrev->next = currNext;
	if (currNext)
	{
		currNext->prev = currPrev;
	}

	/* Insert @curr: left-linking */
	curr->prev = currPrev->prev;
	if (currPrev->prev)
	{
		/* While curr->prev is not expected to be NULL, as that is taken care of...*/
		/*...by compare_node() return value, currPrev->prev could be NULL */
		currPrev->prev->next = curr;
	}

	/* Insert @curr: right-linking */
	curr->next = currPrev;
	currPrev->prev = curr;
}


/**
 * compare_nodes - checks if the key of @curr is greater than previous node's.
 * @curr: the node whose key to compare.
 *
 * Return: 0 if the key of @curr is greater than previous node or previous
 * node is NULL; 1 otherwise, to indicate the need to swap.
 */
int compare_nodes(listint_t *curr)
{
	listint_t *currPrev;

	currPrev = curr->prev;

	if (currPrev == NULL || curr->n >= currPrev->n)
	{
		return (0);
	}

	return (1);
}
