#include "sort.h"
/**
 * bubble_sort - bubble sort method of alogrithim
 * @array: the array to sort
 * @size: size of @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp;
	int flag;

	for (i = 0; i < size - 1; i++)
	{
		flag = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
		print_array(array, size);
	}
}
