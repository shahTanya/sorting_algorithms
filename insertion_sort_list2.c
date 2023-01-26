#include "sort.h"

void insert_middle(listint_t **tmp_next, listint_t *tmp_prev, listint_t *nxt);


/**
 * insertion_sort_list - sorts a doubly-linked list using insertion sort.
 * @list: the list to sort in ascending order of their integer data field.
 *
 * Note: this implementation only inserts when
 * the final location of the compared node is found.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *next_node, *tmp_next, *tmp_prev, *tmp_prev_bkup = NULL;
	int insert_start = 1;

	if (!list || *list == NULL || (*list)->next == NULL)
	{
		/* Empty or single-element list */
		return;
	}

	tmp_next = (*list)->next; /* start from second element in list */
	while (tmp_next)
	{
		if (tmp_next->n >= tmp_next->prev->n)
		{
			tmp_next = tmp_next->next;
			continue;
		}
		next_node = tmp_next->next; /* save next node to insert-sort */
		tmp_next->prev->next = next_node; /* close the gap created by tmp_next */
		if (next_node)
			next_node->prev = tmp_next->prev;
		tmp_prev = tmp_next->prev->prev; /* skipping the already-compared prev node*/
		if (tmp_prev != NULL)
		{
			while (tmp_prev)
			{
				if (tmp_next->n >= tmp_prev->n)
				{
					insert_middle(&tmp_next, tmp_prev, next_node);
					print_list(*list);
					insert_start = 0;
					break;
				}
				tmp_prev_bkup = tmp_prev;
				tmp_prev = tmp_prev->prev;
			}
		}
		if (insert_start)
		{
			if (tmp_prev_bkup)
			{
				tmp_next->next = tmp_prev_bkup;
				tmp_next->prev = NULL;
				tmp_prev_bkup->prev = tmp_next;
				*list = tmp_next; /* tmp_next now new head */
				tmp_next = next_node;
				print_list(*list);
				tmp_prev_bkup = NULL;
			}
			else
			{
				tmp_next->next = tmp_next->prev;
				tmp_next->prev = NULL;
				tmp_next->next->prev = tmp_next;
				*list = tmp_next; /* update list head */
				tmp_next = next_node;
				print_list(*list);
			}
		}
		insert_start = 1;
	}
}




/**
 * insert_middle - inserts a node inside a doubly-linked list.
 * @tmp_next: address of pointer to the listint_t node to insert.
 * @tmp_prev: pointer to node to insert @tmp_next in front of.
 * @nxt: the node to continue insertion sort from.
 *
 * Note: this is a helper function to insertion_sort_list().
 */
void insert_middle(listint_t **tmp_next, listint_t *tmp_prev, listint_t *nxt)
{
	(*tmp_next)->next = tmp_prev->next;
	(*tmp_next)->prev = tmp_prev;
	tmp_prev->next = *tmp_next;
	(*tmp_next)->next->prev = *tmp_next;
	*tmp_next = nxt;
}
