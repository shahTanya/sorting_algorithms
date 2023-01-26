#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order.
 * @array: the int array to sort.
 * @size: the number of integers in @array.
 */
void bubble_sort(int *array, size_t size)
{
	int j, tmp, size_cpy, swap = 0;
	size_t i;

	if (size >= 2)
	{
		size_cpy = size;
		for (i = 0; i < size; i = 0)
		{
			for (j = 1; j < size_cpy; j++)
			{
				if (array[i] > array[j])
				{
					/* Swap values */
					tmp = array[i];
					array[i] = array[j];
					array[j] = tmp;
					swap = 1;
					print_array(array, size);
				}
				i++;
			}
			if (!swap || size_cpy == 2)
			{
				/* No sort this loop, or final sort just occured */
				return;
			}
			swap = 0;
			size_cpy--;
		}
	}
}
