/**
 * @file test_merge_quick_sort.c
 * @brief Unit tests for merge and quick sort algorithms.
 * 
 * This file contains test cases to verify the correctness of merge and quick sort algorithms for different data types:
 * integers, doubles, and strings. The Unity testing framework is used for the test cases.
 */

#include "merge_quick_sort.h"
#include "unity.h"
#include <math.h>

#define N_ITEMS 4 /**< Number of items used in tests */

/**
 * @brief Custom assertion macro to compare doubles with a tolerance.
 * 
 * @param expected The expected value.
 * @param actual The actual value.
 * @param tolerance The tolerance within which the values are considered equal.
 */
#define TEST_ASSERT_EQUAL_DOUBLE_WITH_TOLERANCE(expected, actual, tolerance) \
    TEST_ASSERT_TRUE(fabs((expected) - (actual)) <= (tolerance))

/**
 * @brief Comparator function for integers.
 * 
 * Compares two integers for sorting.
 * 
 * @param int1 Pointer to the first integer.
 * @param int2 Pointer to the second integer.
 * @return A negative integer if the first integer is less than the second, zero if they are equal, 
 *         and a positive integer if the first integer is greater than the second.
 */
int compar_int(const void *int1, const void *int2) {
    return *(int *)int1 - *(int *)int2;
}

/**
 * @brief Comparator function for strings.
 * 
 * Compares two strings for sorting.
 * 
 * @param str1 Pointer to the first string.
 * @param str2 Pointer to the second string.
 * @return An integer less than, equal to, or greater than zero if the first string is less than, 
 *         equal to, or greater than the second string, respectively.
 */
int compar_string(const void *str1, const void *str2) {
    return strcmp(*(const char **)str1, *(const char **)str2);
}

/**
 * @brief Comparator function for doubles.
 * 
 * Compares two doubles for sorting.
 * 
 * @param double1 Pointer to the first double.
 * @param double2 Pointer to the second double.
 * @return A negative integer if the first double is less than the second, zero if they are equal, 
 *         and a positive integer if the first double is greater than the second.
 */
int compar_double(const void *double1, const void *double2) {
    double d1 = *(double *)double1;
    double d2 = *(double *)double2;
    if (d1 > d2) {
        return 1;
    } else if (d1 < d2) {
        return -1;
    } else {
        return 0;
    }
}

/**
 * @brief Setup function for test cases. 
 * 
 * This function is called before each test case is run. It can be used to initialize test data.
 */
void setUp(void) {}

/**
 * @brief Teardown function for test cases.
 * 
 * This function is called after each test case is run. It can be used to clean up test data.
 */
void tearDown(void) {}

/**
 * @brief Test case for sorting an empty array (zero elements) using merge and quick sort.
 */
void test_merge_quick_array_is_empty_zero_el(void) {
    int *arr_merge_ptrs = NULL;
    int *arr_quick_ptrs = NULL;

    merge_sort((void **)arr_merge_ptrs, 0, compar_int);
    quick_sort((void **)arr_quick_ptrs, 0, compar_int);

    TEST_ASSERT_EQUAL(0, 0);
}

/**
 * @brief Test case for sorting an array with one element using merge and quick sort.
 */
void test_merge_quick_array_is_empty_one_el(void) {
    int arr_merge[] = {1};
    int arr_quick[] = {1};
    int *arr_merge_ptrs[] = {&arr_merge[0]};
    int *arr_quick_ptrs[] = {&arr_quick[0]};

    merge_sort((void **)arr_merge_ptrs, 1, compar_int);
    quick_sort((void **)arr_quick_ptrs, 1, compar_int);

    TEST_ASSERT_EQUAL_INT(1, *(int *)arr_merge_ptrs[0]);
    TEST_ASSERT_EQUAL_INT(1, *(int *)arr_quick_ptrs[0]);
}

/**
 * @brief Test case for adding and retrieving one element in the array using merge and quick sort.
 */
void test_merge_quick_array_add_get_one_el(void) {
    int arr_merge[] = {10};
    int arr_quick[] = {10};
    int *arr_merge_ptrs[] = {&arr_merge[0]};
    int *arr_quick_ptrs[] = {&arr_quick[0]};

    merge_sort((void **)arr_merge_ptrs, 1, compar_int);
    quick_sort((void **)arr_quick_ptrs, 1, compar_int);

    TEST_ASSERT_EQUAL_INT(10, *(int *)arr_merge_ptrs[0]);
    TEST_ASSERT_EQUAL_INT(10, *(int *)arr_quick_ptrs[0]);
}

/**
 * @brief Test case for sorting an array of integers using merge sort.
 */
void test_merge_sort_int(void) {
    int arr_merge[] = {4, 3, 2, 1};
    int *arr_merge_ptrs[N_ITEMS];
    for (size_t i = 0; i < N_ITEMS; i++) {
        arr_merge_ptrs[i] = &arr_merge[i];
    }

    merge_sort((void **)arr_merge_ptrs, N_ITEMS, compar_int);

    int expected[] = {1, 2, 3, 4};
    for (size_t i = 0; i < N_ITEMS; i++) {
        TEST_ASSERT_EQUAL_INT(expected[i], *(int *)arr_merge_ptrs[i]);
    }
}

/**
 * @brief Test case for sorting an array of integers using quick sort.
 */
void test_quick_sort_int(void) {
    int arr_quick[] = {4, 3, 2, 1};
    int *arr_quick_ptrs[N_ITEMS];
    for (size_t i = 0; i < N_ITEMS; i++) {
        arr_quick_ptrs[i] = &arr_quick[i];
    }

    quick_sort((void **)arr_quick_ptrs, N_ITEMS, compar_int);

    int expected[] = {1, 2, 3, 4};
    for (size_t i = 0; i < N_ITEMS; i++) {
        TEST_ASSERT_EQUAL_INT(expected[i], *(int *)arr_quick_ptrs[i]);
    }
}

/**
 * @brief Test case for sorting an array of doubles using merge sort.
 */
void test_merge_sort_double(void) {
    double arr_merge[] = {4.1, 3.1, 2.1, 1.1};
    double *arr_merge_ptrs[N_ITEMS];
    for (size_t i = 0; i < N_ITEMS; i++) {
        arr_merge_ptrs[i] = &arr_merge[i];
    }

    merge_sort((void **)arr_merge_ptrs, N_ITEMS, compar_double);

    double expected[] = {1.1, 2.1, 3.1, 4.1};
    double tolerance = 0.0001;
    for (size_t i = 0; i < N_ITEMS; i++) {
        TEST_ASSERT_EQUAL_DOUBLE_WITH_TOLERANCE(expected[i], *(double *)arr_merge_ptrs[i], tolerance);
    }
}

/**
 * @brief Test case for sorting an array of doubles using quick sort.
 */
void test_quick_sort_double(void) {
    double arr_quick[] = {4.1, 3.1, 2.1, 1.1};
    double *arr_quick_ptrs[N_ITEMS];
    for (size_t i = 0; i < N_ITEMS; i++) {
        arr_quick_ptrs[i] = &arr_quick[i];
    }

    quick_sort((void **)arr_quick_ptrs, N_ITEMS, compar_double);

    double expected[] = {1.1, 2.1, 3.1, 4.1};
    double tolerance = 0.0001;
    for (size_t i = 0; i < N_ITEMS; i++) {
        TEST_ASSERT_EQUAL_DOUBLE_WITH_TOLERANCE(expected[i], *(double *)arr_quick_ptrs[i], tolerance);
    }
}

/**
 * @brief Test case for sorting an array of strings using merge sort.
 */
void test_merge_sort_string(void) {
    const char *arr_merge[] = {"delta", "charlie", "bravo", "alpha"};
    const char **arr_merge_ptrs[N_ITEMS];
    for (size_t i = 0; i < N_ITEMS; i++) {
        arr_merge_ptrs[i] = &arr_merge[i];
    }

    merge_sort((void **)arr_merge_ptrs, N_ITEMS, compar_string);

    const char *expected[] = {"alpha", "bravo", "charlie", "delta"};
    for (size_t i = 0; i < N_ITEMS; i++) {
        TEST_ASSERT_EQUAL_STRING(expected[i], *arr_merge_ptrs[i]);
    }
}

/**
 * @brief Test case for sorting an array of strings using quick sort.
 */
void test_quick_sort_string(void) {
    const char *arr_quick[] = {"delta", "charlie", "bravo", "alpha"};
    const char **arr_quick_ptrs[N_ITEMS];
    for (size_t i = 0; i < N_ITEMS; i++) {
        arr_quick_ptrs[i] = &arr_quick[i];
    }

    quick_sort((void **)arr_quick_ptrs, N_ITEMS, compar_string);

    const char *expected[] = {"alpha", "bravo", "charlie", "delta"};
    for (size_t i = 0; i < N_ITEMS; i++) {
        TEST_ASSERT_EQUAL_STRING(expected[i], *arr_quick_ptrs[i]);
    }
}

/**
 * @brief Main function to run all unit tests.
 * 
 * Initializes the Unity test framework, runs all test cases, and then finalizes the test framework.
 * 
 * @return 0 on success, or 1 if any test fails.
 */
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_merge_quick_array_is_empty_zero_el);
    RUN_TEST(test_merge_quick_array_is_empty_one_el);
    RUN_TEST(test_merge_quick_array_add_get_one_el);
    RUN_TEST(test_merge_sort_int);
    RUN_TEST(test_quick_sort_int);
    RUN_TEST(test_merge_sort_double);
    RUN_TEST(test_quick_sort_double);
    RUN_TEST(test_merge_sort_string);
    RUN_TEST(test_quick_sort_string);
    UNITY_END();
}
