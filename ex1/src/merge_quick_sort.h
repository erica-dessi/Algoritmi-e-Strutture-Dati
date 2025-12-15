/**
 * @file merge_quick_sort.h
 * @brief Header file for merge sort and quick sort algorithms.
 * 
 * This header file declares the functions for sorting arrays using merge sort
 * and quick sort algorithms. These functions operate on arrays of pointers
 * and use a comparison function to determine the order of elements.
 */

#ifndef MERGE_QUICK_SORT_H
#define MERGE_QUICK_SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * @brief Sorts an array of pointers using the merge sort algorithm.
 * 
 * Merge sort is a stable, comparison-based sorting algorithm that divides the
 * array into smaller subarrays, sorts those subarrays, and then merges them
 * back together in sorted order.
 * 
 * @param base Pointer to the array of pointers to be sorted.
 * @param nitems Number of elements in the array.
 * @param compar Function pointer to the comparison function. This function
 *               should return a negative value if the first element is less
 *               than the second, zero if they are equal, and a positive value
 *               if the first element is greater than the second.
 */
void merge_sort(void **base, size_t nitems, int (*compar)(const void*, const void*));

/**
 * @brief Sorts an array of pointers using the quick sort algorithm.
 * 
 * Quick sort is a fast, in-place sorting algorithm that uses a divide-and-conquer
 * approach. It selects a pivot element and partitions the array into elements
 * less than the pivot and elements greater than the pivot, then recursively sorts
 * the subarrays.
 * 
 * @param base Pointer to the array of pointers to be sorted.
 * @param nitems Number of elements in the array.
 * @param compar Function pointer to the comparison function. This function
 *               should return a negative value if the first element is less
 *               than the second, zero if they are equal, and a positive value
 *               if the first element is greater than the second.
 */
void quick_sort(void **base, size_t nitems, int (*compar)(const void*, const void*));

#endif /* MERGE_QUICK_SORT_H */
