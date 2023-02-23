#include "sort.h"

/**
 * swap_ints - Swaps two ints. in an array.
 * @a: The first int. to be swapped.
 * @b: The second int. to be swapped.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Sort the array of ints. in an ascending
 *              order using the shell sort algorithm.
 * @array: An array of int.
 * @size: Size of the array.
 *
 * Description: Uses the Knuth interval sequence arrangement.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_ints(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
