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
 * @size: size of @array
 * @lb: lower bound
 * @ub: upper bound
 * Return: end of array
 */
int partion(int *array, size_t size, int lb, int ub)
{
	int pivot = array[ub];
	int j, i = lb - 1;

	for (j = lb; j <= ub - 1; j++)
	{
		if (array[j] <=  pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[ub]);
	print_array(array, size);
	return (i + 1);
}
/**
 * _quick_sort - a function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of @ array
 * @lb: lower bound of @array
 * @ub: upper bound of @array
 */
void _quick_sort(int *array, size_t size, int lb, int ub)
{
	int loc;

	if (lb < ub)
	{
		loc = partion(array, size, lb, ub);
		_quick_sort(array, size, lb, loc - 1);
		_quick_sort(array, size, loc + 1, ub);
	}
}
/**
 * quick_sort - this function call the above _quick_sort function
 * @array: the array
 * @size: size of @array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	_quick_sort(array, size, 0, size - 1);
}
