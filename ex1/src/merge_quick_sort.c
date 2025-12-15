/**
 * @file merge_quick_sort.c
 * @brief Implementations of merge sort and quick sort algorithms.
 * 
 * This file contains the implementation of merge sort and quick sort algorithms,
 * including helper functions for swapping elements, choosing pivots, and merging sorted subarrays.
 */

#include "merge_quick_sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/**
 * @brief Swaps two elements in an array of pointers.
 * 
 * @param a Pointer to the first element to swap.
 * @param b Pointer to the second element to swap.
 */
void swap(void **a, void **b) {
    void *temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Chooses a random pivot and moves it to the end of the array segment.
 * 
 * @param base Pointer to the array of pointers.
 * @param low The starting index of the segment.
 * @param high The ending index of the segment.
 */
void choose_random_pivot(void **base, size_t low, size_t high) {
    size_t pivot_index = low + (size_t)(rand() % ((int)(high - low + 1)));
    swap(&base[pivot_index], &base[high]);
}

/**
 * @brief Partitions the array segment around a pivot.
 * 
 * Elements less than the pivot are moved to the left, and elements greater than
 * the pivot are moved to the right.
 * 
 * @param base Pointer to the array of pointers.
 * @param low The starting index of the segment.
 * @param high The ending index of the segment.
 * @param compar Function pointer to the comparison function.
 * @return The index of the pivot after partitioning.
 */
size_t partition(void **base, size_t low, size_t high, int (*compar)(const void*, const void*)) {
    void *pivot = base[high];
    size_t i = low;

    for (size_t j = low; j < high; j++) {
        if (compar(base[j], pivot) < 0) {
            swap(&base[i], &base[j]);
            i++;
        }
    }
    swap(&base[i], &base[high]);
    return i;
}

/**
 * @brief Recursively sorts the array segment using the quick sort algorithm.
 * 
 * @param base Pointer to the array of pointers.
 * @param low The starting index of the segment.
 * @param high The ending index of the segment.
 * @param compar Function pointer to the comparison function.
 */
void quick_sort_rec(void **base, size_t low, size_t high, int (*compar)(const void*, const void*)) {
    if (low < high) {
        choose_random_pivot(base, low, high);
        size_t pi = partition(base, low, high, compar);

        if (pi > 0) {
            quick_sort_rec(base, low, pi - 1, compar);
        }
        quick_sort_rec(base, pi + 1, high, compar);
    }
}

/**
 * @brief Sorts an array of pointers using the quick sort algorithm.
 * 
 * Initializes the random number generator and calls the recursive quick sort function.
 * 
 * @param base Pointer to the array of pointers.
 * @param nitems Number of elements in the array.
 * @param compar Function pointer to the comparison function.
 */
void quick_sort(void **base, size_t nitems, int (*compar)(const void *, const void*)) {
    if (base == NULL || compar == NULL) {
        fprintf(stderr, "quick_sort: base and compar cannot be NULL\n");
        return;
    }

    if (nitems > 0) {
        srand((unsigned int)time(NULL)); // Seed the random number generator
        quick_sort_rec(base, 0, nitems - 1, compar);
    }
}

/**
 * @brief Merges two sorted subarrays into a single sorted array.
 * 
 * @param base Pointer to the array of pointers.
 * @param nitems Total number of elements in the array.
 * @param middle_i Index separating the two subarrays.
 * @param compar Function pointer to the comparison function.
 */
static void merge(void **base, size_t nitems, size_t middle_i, int (*compar)(const void*, const void*)) {
    void **temp = malloc(nitems * sizeof(void *));
    if (temp == NULL) {
        fprintf(stderr, "merge: memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    size_t i = 0, j = middle_i, k = 0;
    
    while (i < middle_i && j < nitems) {
        if (compar(base[i], base[j]) <= 0) {
            temp[k++] = base[i++];
        } else {
            temp[k++] = base[j++];
        }
    }

    while (i < middle_i) {
        temp[k++] = base[i++];
    }

    while (j < nitems) {
        temp[k++] = base[j++];
    }

    memcpy(base, temp, nitems * sizeof(void *));
    free(temp);
}

/**
 * @brief Recursively sorts an array segment using the merge sort algorithm.
 * 
 * @param base Pointer to the array of pointers.
 * @param nitems Number of elements in the segment.
 * @param compar Function pointer to the comparison function.
 */
static void merge_sort_rec(void **base, size_t nitems, int (*compar)(const void*, const void*)) {
    if (nitems > 1) {
        size_t middle_i = nitems / 2;
        
        merge_sort_rec(base, middle_i, compar);
        merge_sort_rec(base + middle_i, nitems - middle_i, compar);
        
        merge(base, nitems, middle_i, compar);
    }
}

/**
 * @brief Sorts an array of pointers using the merge sort algorithm.
 * 
 * @param base Pointer to the array of pointers.
 * @param nitems Number of elements in the array.
 * @param compar Function pointer to the comparison function.
 */
void merge_sort(void **base, size_t nitems, int (*compar)(const void *, const void*)) {
    if (base == NULL || compar == NULL) {
        fprintf(stderr, "merge_sort: base and compar cannot be NULL\n");
        return;
    }

    if (nitems >= 2) {
        merge_sort_rec(base, nitems, compar);
    }
}
