#include "sort.h"

void copy2array(int *dest, int dest_size, int *source);
void swap_keys(int *array);
void split_sort_merge(int *array, size_t size, int *tmp_arr);



/**
 * merge_sort - sorts an array of integers using merge sort algorithm.
 * @array: array to sort.
 * @size: size of @array.
 */
void merge_sort(int *array, size_t size)
{
	int *tmp_arr;

	if (size < 2 || array == NULL)
	{
		return;
	}

	tmp_arr = calloc2(sizeof(int) * size);
	if (!tmp_arr)
	{
		return;
	}

	split_sort_merge(array, size, tmp_arr);
	free(tmp_arr);
}



/**
 * split_sort_merge - implements recursive split, sort, and merge for mergesort
 * @array: the array to split, sort and merge.
 * @size: size of @array.
 * @tmp_arr: array for temporarily holding sorted data. Of same size as @array.
 */
void split_sort_merge(int *array, size_t size, int *tmp_arr)
{
	int i, j, k, left_arr_size, right_arr_size, *left_arr, *right_arr;

	/* Recursion base case */
	if (size == 2)
	{
		printf("Merging...\n[left]: %d\n[right]: %d\n", array[0], array[1]);
		if (array[0] > array[1])
			swap_keys(array);
		printf("[Done]: ");
		print_array(array, 2);
		return;
	}

	/* Split array >= 3 */
	left_arr_size = size / 2;
	left_arr = array + 0; /* left_arr == array */
	right_arr_size = size - left_arr_size;
	right_arr = array + left_arr_size;


	if (left_arr_size > 1)
	{
		split_sort_merge(left_arr, left_arr_size, tmp_arr); /* sort left arrs 1st */
	}
	if (right_arr_size > 1)
	{
		split_sort_merge(right_arr, right_arr_size, tmp_arr); /* recursive sort */
	}

	/* Sort implementation for sorted sub-arrays */
	printf("Merging...\n[left]: ");
	print_array(left_arr, left_arr_size);
	printf("[right]: ");
	print_array(right_arr, right_arr_size);
	for (i = 0, j = 0, k = 0;;)
	{
		if (left_arr[i] <= right_arr[j])
		{
			/* First item of left array less than first of right array */
			tmp_arr[k++] = left_arr[i]; /* copy lesser key to next index in tmp_arr */
			++i;
		}
		else
		{
			tmp_arr[k++] = right_arr[j];
			++j;
		}
		if (i >= left_arr_size)
		{
			/* Left array empty; copy remaining items in right_arr to tmp_arr */
			for (; j < right_arr_size; j++)
			{
				tmp_arr[k++] = right_arr[j];
			}
			copy2array(array, size, tmp_arr); /* merge with original array */
			printf("[Done]: ");
			print_array(array, size);
			return; /* [subarray] array now sorted */
		}
		if (j >= right_arr_size)
		{
			/* Right array empty */
			for (; i < left_arr_size; ++i)
			{
				tmp_arr[k++] = left_arr[i];
			}
			copy2array(array, size, tmp_arr);
			printf("[Done]: ");
			print_array(array, size);
			return;
		}
	}
}



/**
 * copy2array - copies data from one array to another.
 * @dest: the destination array.
 * @dest_size: the amount of data to copy from @source.
 * @source: the array to copy from.
 */
void copy2array(int *dest, int dest_size, int *source)
{
	int i;

	for (i = 0; i < dest_size; i++)
	{
		dest[i] = source[i];
	}
}


/**
 * swap_keys - swaps the keys in the first two array indices.
 * @array: the array who first two keys to swap.
 */
void swap_keys(int *array)
{
	int tmp_v;

	tmp_v = array[0];
	array[0] = array[1];
	array[1] = tmp_v;
}



/**
 * calloc2 - allocates and initializes memory of @size bytes.
 * @size: the number of contiguous bytes to allocate.
 *
 * Note: bytes are currently initialized to zero.
 * Return: a void pointer representing the address of the allocated space.
 */
void *calloc2(size_t size)
{
	void *ptr;
	char *ptc;
	size_t i;

	ptr = malloc(size);
	if (!ptr)
	{
		perror("calloc2");
		return (NULL);
	}

	ptc = (char *)ptr;
	for (i = 0; i < size; i++)
	{
		ptc[i] = 0;
	}

	return (ptr);
}
