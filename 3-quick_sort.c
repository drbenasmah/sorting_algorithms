#include "sort.h"

/**
 * swap - swaps two integers in an array
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 */
void swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * lomuto_partition - partitions an array using the Lomuto partition scheme
 * @array: pointer to the array to partition
 * @low: index of the lowest element of the partition to sort
 * @high: index of the highest element of the partition to sort
 * @size: size of the array to sort
 *
 * Return: index of the pivot element
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
    int pivot, i, j;

    pivot = array[high];
    i = low - 1;
    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                swap(&array[i], &array[j]);
                print_array(array, size);
            }
        }
    }
    if (array[high] < array[i + 1])
    {
        swap(&array[i + 1], &array[high]);
        print_array(array, size);
    }
    return (i + 1);
}

/**
 * quicksort - sorts an array of integers in ascending order using the quick
 *             sort algorithm
 * @array: pointer to the array to sort
 * @low: index of the lowest element of the partition to sort
 * @high: index of the highest element of the partition to sort
 * @size: size of the array to sort
 */
void quicksort(int *array, int low, int high, size_t size)
{
    size_t p;

    if (low < high)
    {
        p = lomuto_partition(array, low, high, size);
        quicksort(array, low, p - 1, size);
        quicksort(array, p + 1, high, size);
    }
}

/**
 * quick_sort - sorts an array of integers in ascending order using the quick
 *              sort algorithm
 * @array: pointer to the array to sort
 * @size: size of the array to sort
 */
void quick_sort(int *array, size_t size)
{
    if (array != NULL && size > 1)
        quicksort(array, 0, size - 1, size);
}
