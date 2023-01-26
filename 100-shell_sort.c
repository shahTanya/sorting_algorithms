#include "sort.h"

/**
 * swap - Swaps two integers
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
 * shell_sort - Sorts an array using the shell sort
 * algorithm and knuth sequence
 *
 * @array: Array to be sorted
 * @size: Size of array
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;

	if (size < 2)
		return;

	while (gap < size / 3)
	{
		gap = 3 * gap + 1;
	}
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j >= gap; j -= gap)
			{
				if (array[j] < array[j - gap])
				{
					swap(&array[j], &array[j - gap]);
				}
			}
		}
		gap /= 3;
		print_array(array, size);
	}
}
