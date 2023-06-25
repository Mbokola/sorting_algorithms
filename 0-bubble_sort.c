#include "sort.h"

/**
 *bubble_sort - Bubble sort algorithm of an array
 *@array: Array of integers
 *@size: Size of array
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, counter, len = size;

	while (size > 1)
	{
		for (i = 1; i < size; i++)
		{
			if (array[i] < array[i - 1])
			{
				array[i - 1] ^= array[i];
				array[i] ^= array[i - 1];
				array[i - 1] ^= array[i];
				counter = i;
				print_array(array, len);
				continue;
			}
			counter--;
		}
		size = counter;
	}
}
