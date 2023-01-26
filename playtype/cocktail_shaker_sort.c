#include "sort.h"


/**
 * cocktail_sort - sorts inascending order using the Cocktail Shaker Sort.
 * @array: the array of integers to sort.
 * @size the size of @array.
 *
 * Description: this algorithm is basically a
 * bi-directional implementation of Bubble Sort.
 */
void cocktail_sort(int *array, size_t size)
{
	size_t left_stop = 0, right_stop = size;
	int i, j, tmp_v, swapped = 0;

	if (size < 2)
	{
		return;
	}

	for (i = 0;; i = left_stop)
	{
		for (j = i + 1; j < (int)right_stop; j++)
		{
			if (array[j] < array[i])
			{
				/* Swap values */
				tmp_v = array[j];
				array[j] = array[i];
				array[i] = tmp_v;
				swapped = 1;
			}
			i++;
		}
		if (!swapped)
		{
			return;
		}
		right_stop--;
		for (i--, j--; i >= (int)left_stop; i--, j--)
		{
			if (array[i] > array[j])
			{
				/* Swap values */
				tmp_v = array[j];
				array[j] = array[i];
				array[i] = tmp_v;
				swapped = 1;
			}
		}
		left_stop++;
		if (!swapped || left_stop >= right_stop - 1)
		{
			return;
		}
	}
}
