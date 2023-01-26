#include "sort.h"

void heapify(int *array, int size, int size0, int start_idx);

/**
 * heap_sort - sorts an array using heap sort implementation.
 * @array: the array to sort.
 * @size: size of @array.
 */
void heap_sort(int *array, size_t size)
{
	int i;
	size_t size_cpy = size;

	if (size < 2)
	{
		return;
	}

	/* printf("%da\n", a++); */
	/* Heapify @array into a max-heap representation */
	for (i = size / 2 - 1; i >= 0; i--)
	{
		/* printf("%dai\n", a++); */
		heapify(array, size, size, i);
	}

	/* printf("%db\n", a++); */
	/* Move the highest value to the end of array, reduce heap, heapify, repeat */
	while (1)
	{
		/* Swap first and last idx values of array, representing */
		/* the root and last nodes of the abstract heap. */
		swap(array + 0, array + (size_cpy - 1));
		print_array(array, size);

		/* Reduce size of array to effectively delete the last heap node */
		size_cpy--;
		if (size_cpy == 1)
		{
			return; /* sorting done */
		}

		heapify(array, size_cpy, size, 0); /* heapify, starting from the root */
	}
	/* printf("%dc\n", a++); */
}


/**
 * heapify - converts @array into a max-heap representation.
 * @array: array to convert into a max heap.
 * @size: size of array.
 * @size0: size of the original array.
 * @start_idx: index of the node to start heapification from.
 */
void heapify(int *array, int size, int size0, int start_idx)
{
	int largest, left_child_idx, right_child_idx;

	/* Compute parent and children indices */
	largest = start_idx;
	left_child_idx = 2 * start_idx + 1;
	right_child_idx = 2 * start_idx + 2;

	if (left_child_idx < size && array[left_child_idx] > array[largest])
	{
		largest = left_child_idx; /* record index with current largest value */
	}
	if (right_child_idx < size && array[right_child_idx] > array[largest])
	{
		largest = right_child_idx;
	}

	if (largest != start_idx)
	{
		/* Swapping must occur between parent and largest node */
		swap(array + start_idx, array + largest);
		print_array(array, size0);
		heapify(array, size, size0, largest); /* starting from prev largest node */
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
