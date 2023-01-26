include "sort.h"

void hoare_sort(int *array, size_t size, int *low_a, int *high_a);

/**
 * quick_sort_hoare - sorts an array of integers using hoare's quick sort.
 * @array: the array to sort.
 * @size: the size of @array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2 || !array)
	{
		return;
	}

	hoare_sort(array, size, array + 0, array + (size - 1));
}




/**
 * hoare_sort - implements hoare's partitioning scheme to recursive sort.
 * @array: the full array to sort.
 * @size: the size of @array.
 * @low_a: the first address of the current [sub]array to sort.
 * @high_a: the last address of the current [sub]array to sort.
 */
void hoare_sort(int *array, size_t size, int *low_a, int *high_a)
{
	int *left_a, *right_a, *pivot_a, exit_loop = 0, left_pivot = 0;

	if (low_a == high_a)
	{
		/* Single-element subarray - base case */
		return;
	}

	pivot_a = high_a;
	left_a = low_a;
	right_a = high_a;

	while (left_a != right_a && left_a != right_a + 1)
	{
		/* printf("a\n"); */
		while (1)
		{
			if (left_a != pivot_a && *left_a <= *pivot_a)
			{
				/* Value at left_a <= val at pivot_a, and left_a is before pivot_a */
				left_a++;
				if (left_a == pivot_a)
				{
					/* pivot_a to be reset after value swapping */
					left_pivot = 1;
				}
			}
			else
			{
				/* Value at left_a > value at pivot_a; *right_a set for cmp with *pivot */
				break;
			}

			if (left_a == right_a || left_a == right_a + 1)
			{
				/* Partition address set; time to partition at pivot_a */
				exit_loop = 1;
				break;
			}
		}
		/* printf("b\n"); */
		if (exit_loop)
		{
			/* printf("b1\n"); */
			exit_loop = 0; /* reset flag */
			break;
		}
		if (right_a == pivot_a)
		{
			/* printf("b2\n"); */
			/* Compare pivot_a value with left_a value instead of with right_a value */
			if (*pivot_a < *left_a)
			{
				/* printf("b2i\n"); */
				swap(pivot_a, left_a); /* swap values */
				print_array(array, size);
				pivot_a = left_a; /* reset pivot address to left_a */
			}
		}
		else
		{
			/* printf("b3\n"); */
			/* Compare pivot_a value with right_a value */
			while (1)
			{
				/* printf("b3i\n"); */
				if (*right_a <= *pivot_a)
				{
					swap(pivot_a, right_a); /* swap values */
					print_array(array, size);
					if (left_pivot)
					{
						/* Reset pivot address to right_a */
						pivot_a = right_a;
						left_pivot = 0; /* reset to default */
					}
					break;
				}
				right_a--; /* move to previous address */
				if (left_a == right_a || left_a == right_a + 1)
				{
					exit_loop = 1;
					break; /* partitioning time */
				}
				if (right_a == pivot_a)
				{
					if (*pivot_a < *left_a)
					{
						swap(pivot_a, left_a);
						print_array(array, size);
						pivot_a = left_a;
					}
					break;
				}
			}
			/* printf("b4\n"); */
		}
		/* printf("c\n"); */
		if (exit_loop)
		{
			/* printf("c1\n"); */
			exit_loop = 0;
			break; /* partitioning time */
		}
		left_a++, right_a--;
	}

	/* printf("d\n"); */
	/* Partition at pivot_a */
	if (low_a != pivot_a)
	{
		/* At least one element to the left of pivot */
		hoare_sort(array, size, low_a, pivot_a - 1);
	}
	/* printf("e\n"); */
	if (high_a != pivot_a)
	{
		/* At least one element to the right of pivot */
		hoare_sort(array, size, pivot_a + 1, high_a);
	}
	/* printf("f\n"); */
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
