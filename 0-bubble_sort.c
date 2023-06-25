#include "sort.h"

/**
 *bubble_sort - Bubble sort algorithm of an array
 *@array: Array of integers
 *@size: Size of array
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, counter = 0, len = size, j;

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
				for (j = 0; j < len; j++)
				{
					if (j > 0)
						printf(", ");
					printf("%d", array[j]);
				}
				printf("\n");
			}
		}
		size = counter;
	}
}
