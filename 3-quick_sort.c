#include "sort.h"


void lomuto_sort(int *array, size_t size, int *low_a, int *high_a);


/**
 * quick_sort - implements Quick Sort using the Lamuto partitioning scheme.
 * @array: the array to sort.
 * @size: the number of integers in @array.
 */
void quick_sort(int *array, size_t size)
{
	int *low_a, *high_a;

	if (size < 2 || !array)
	{
		return;
	}

	low_a = array + 0; /* start of array */
	high_a = array + (size - 1); /* end of array */

	lomuto_sort(array, size, low_a, high_a);
}




/**
 * lomuto_sort - implements Lomuto partitioning and sort.
 * @array: array of integers being sorted.
 * @size: size of @array.
 * @low_a: start address of the (sub-)array to partition and sort.
 * @high_a: last address of the (sub-)array to partition and sort.
 */
void lomuto_sort(int *array, size_t size, int *low_a, int *high_a)
{
	int *partition_a, *pivot_a, *cmp_a, at_pivot = 0;

	if (low_a == high_a)
		return; /* only one item in subarray */

	pivot_a = high_a;
	partition_a = low_a;
	cmp_a = low_a;

	while (cmp_a != pivot_a)
	{
		if (*pivot_a < *cmp_a)
		{
			/* Probe for value less than pivot's to swap with partition's */
			while (1)
			{
				/* Loop will run till cmp_a == pivot_a */
				cmp_a++; /* move to next comparison address */
				if (cmp_a == pivot_a)
				{
					at_pivot = 1;
					break;
				}
				if (*cmp_a < *pivot_a)
				{
					/* Swap with value at partition_a */
					swap(cmp_a, partition_a);
					print_array(array, size);
					partition_a++;
				}
			}
		}
		if (at_pivot)
			break; /* swapping between pivot and partition to happen outside */
		cmp_a++, partition_a++;
	}
	if (pivot_a == partition_a)
	{
		/* No swapping due, and no subarray on right, only left */
		lomuto_sort(array, size, low_a, partition_a - 1);
	}
	if (at_pivot)
	{
		/* Swap pivot and partition values */
		swap(pivot_a, partition_a);
		print_array(array, size);
	}
	/* Partition at partition_a */
	if (low_a != partition_a)
	{
		/* Valid items on the left of partition point */
		lomuto_sort(array, size, low_a, partition_a - 1);
	}
	if (high_a != partition_a)
	{
		/* Valid items on the left */
		lomuto_sort(array, size, partition_a + 1, high_a);
	}
}




/**
 * swap - exchanges values between two addresses.
 * @add1: a pointer to int.
 * @add2: a pointer to int.
 */
void swap(int *add1, int *add2)
{
	int tmp_v;

	tmp_v = *add1;
	*add1 = *add2;
	*add2 = tmp_v;
}
