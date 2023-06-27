#include "sort.h"
/**
 *selection_sort - selectoion sort algo implementation
 *@array: array to sort
 *@size : size of array
 *
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, tmp = 0;

	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[i] && !tmp)
				tmp = j;
			if (array[j] < array[tmp] && tmp)
				tmp = j;
		}
		if (tmp)
		{
			array[i] ^= array[tmp];
			array[tmp] ^= array[i];
			array[i] ^= array[tmp];
			tmp = 0;
			print_array(array, size);
		}
	}
}
