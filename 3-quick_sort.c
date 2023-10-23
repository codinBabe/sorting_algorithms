#include "sort.h"
/**
 * swap -function that swap two variable
 * @a: first variable
 * @b: second variable
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * partion - function that sort array in bit
 * @array: array to be sorted
 * @lb: lower bound
 * @ub: upper bound
 * Return: end of array
 */
int partion(int *array, int lb, int ub)
{
	int pivot = array[ub];
	int j, i = lb - 1;

	for (j = lb; j <= ub - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[ub]);
	return (i + 1);
}
/**
 * quick_sort - a function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of @ array
 */
void quick_sort(int *array, size_t size)
{
	int index;

	if (size > 1)
		index = partion(array, 0, size - 1);

	print_array(array, size);
	quick_sort(array, index);
	quick_sort(array + index + 1, size - index - 1);
}
