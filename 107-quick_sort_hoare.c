#include "sort.h"

void hoare_sort(int *array, size_t size, int *low_a, int *high_a);
void shiftIfNot(int **addr, int *cmp_a, char dir);

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
	int *left_a, *right_a, *pivot_a, exit_loop = 0, shifted = 0;

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
		while (1)
		{
			if (*left_a <= *pivot_a)
			{
				/* Value at left_a <= val at pivot_a */
				left_a++;
				if (left_a == pivot_a)
				{
					break; /* left_a will not be updated so long its == pivot_a */
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
		if (exit_loop)
		{
			exit_loop = 0; /* reset flag */
			break;
		}

		/* Compare pivot_a value with right_a value */
		while (1)
		{
			if (left_a == pivot_a)
			{
				while (left_a == pivot_a)
				{
					/* Compare with right_a value */
					if (*right_a <= *left_a)
					{
						swap(right_a, left_a); /* swap left==pivot value with right value */
						pivot_a = right_a; /* set pivot address to right_a */
						shiftIfNot(&left_a, high_a, '+');
						shifted = 1;
						break;
					}
					right_a--;
					if (left_a == right_a || left_a == right_a + 1)
					{
						exit_loop = 1;
						break; /* partitioning time */
					}
				}
				if (left_a == right_a || left_a == right_a + 1)
				{
					exit_loop = 1;
					break; /* partitioning time */
				}
			}
			if (exit_loop)
			{
				break;
			}

			if (right_a == pivot_a)
			{
				while (right_a == pivot_a)
				{
					/* Compare with left_a */
					if (*left_a > *right_a)
					{
						swap(right_a, left_a); /* swap right==pivot value with left value */
						pivot_a = left_a; /* set pivot address to left_a */
						shiftIfNot(&right_a, low_a, '-');
						shifted = 1;
						break;
					}
					left_a++;
					if (left_a == right_a || left_a == right_a + 1)
					{
						exit_loop = 1;
						break; /* partitioning time */
					}
				}
				if (left_a == right_a || left_a == right_a + 1)
				{
					exit_loop = 1;
					break; /* partitioning time */
				}
			}
			if (exit_loop)
			{
				break;
			}

			/* Pivot address not equal to any of left and right addresses */
			if (right_a != pivot_a && left_a != pivot_a)
			{
				if (*right_a <= *pivot_a)
				{
					swap(right_a, left_a);
				}
			}

			if (left_a != pivot_a && !shifted)
				left_a++;
			if (right_a != pivot_a && !shifted)
				right_a--;
			shifted = 0;
			if (left_a == right_a || left_a == right_a + 1)
			{
				exit_loop = 1;
				break; /* partitioning time */
			}
		}

		if (exit_loop)
		{
			exit_loop = 0;
			break; /* partitioning time */
		}
		if (left_a != pivot_a && !shifted)
			left_a++;
		if (right_a != pivot_a && !shifted)
			right_a--;
		shifted = 0;
	}

	/* Partition at pivot_a */
	if (low_a != pivot_a)
	{
		/* At least one element to the left of pivot */
		hoare_sort(array, size, low_a, pivot_a - 1);
	}
	if (high_a != pivot_a)
	{
		/* At least one element to the right of pivot */
		hoare_sort(array, size, pivot_a + 1, high_a);
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



/**
 * shiftIfNot - shifts the 1st address in the direction specified on condition.
 * @addr: the address of the pointer to potentially shift.
 * @cmp_a: the address to compare @addr to.
 * @dir: a char indicating the direction to shift @addr.
 */
void shiftIfNot(int **addr, int *cmp_a, char dir)
{
	if (*addr != cmp_a)
	{
		if (dir == '-')
		{
			*addr = *addr - 1;
		}

		if (dir == '+')
		{
			*addr = *addr + 1;
		}
	}
}
