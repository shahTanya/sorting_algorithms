#include "sort.h"

/**
 * swap - swaps to integers
 * @a: First integer
 * @b: Second integer
 * Return: Nothing
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sorts a given array in ascending order using
 * selection sort algorithm
 * @array: Array to be sorted
 * @size: Size of array
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t min, i, j;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		/* Compare min to other values in the array*/
		/* Reset min to any value lower than min*/
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		/* Check if there is a new min */
		/* if yes, then swap */
		if (min != i)
		{
			swap(&array[min], &array[i]);
			print_array(array, size);
		}
	}
}
