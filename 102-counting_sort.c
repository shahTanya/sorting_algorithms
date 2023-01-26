#include "sort.h"

int int_array_max(int *array, size_t size);

/**
 * counting_sort - sorts an array of integers using Counting Sort algorithm.
 * @array: the array to sort.
 * @size: the size of @array.
 */
void counting_sort(int *array, size_t size)
{
	int i, key, max, *count, *output;

	if (size < 2 || array == NULL)
	{
		return;
	}

	max = int_array_max(array, size);
	count = allocate(sizeof(int) * (max + 1));
	if (!count)
	{
		return;
	}
	output = allocate(sizeof(int) * size);
	if (!output)
	{
		return;
	}

	/* Store the count of each integer in @array */
	for (i = 0; i < (int)size; i++)
	{
		key = array[i]; /* get the integer at the array index as key */
		count[key] = count[key] + 1; /* increment the count for key */
	}

	/* Convert the counts to cumulative counts by prefix sum */
	for (i = 0; i < max + 1; i++)
	{
		count[i] += count[i - 1];
	}
	print_array(count, max + 1);

	/* Populate output array in a sorted way, starting from the last index...*/
	/*of @array in order to maintain original order i.e. implement a stable sort*/
	for (i = size - 1; i >= 0; i--)
	{
		key = array[i]; /* key == integer to place in sorted index in @output */
		count[key]--; /* reduce the cumulative count to get correct output index */
		output[count[key]] = key;
	}

	/* Finally, copy @output into @array */
	for (i = 0; i < (int)size; i++)
	{
		array[i] = output[i];
	}
	free(count);
	free(output);
}



/**
 * int_array_max - returns the maximum in an arrayof integers.
 * @array: the array to search.
 * @size: the size of @array.
 *
 * Return: max value in @array.
 */
int int_array_max(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}

	return (max);
}



/**
 * allocate - allocates and initializes memory of @size bytes.
 * @size: the number of contiguous bytes to allocate.
 *
 * Note: bytes are currently initialized to zero.
 * Return: a void pointer representing the address of the allocated space.
 */
void *allocate(size_t size)
{
	void *ptr;
	char *ptc;
	size_t i;

	ptr = malloc(size);
	if (!ptr)
	{
		return (NULL);
	}

	ptc = (char *)ptr;
	for (i = 0; i < size; i++)
	{
		ptc[i] = 0;
	}

	return (ptr);
}
