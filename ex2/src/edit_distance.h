#ifndef EDIT_DISTANCE_H
#define EDIT_DISTANCE_H

/**
 * @brief Computes the edit distance between two strings using a recursive approach with memoization.
 * 
 * This function initializes the memoization table and calls the recursive function to calculate
 * the edit distance between the two strings `s1` and `s2`.
 * 
 * @param s1 Pointer to the first string.
 * @param s2 Pointer to the second string.
 * @return The edit distance between the two strings.
 */
int edit_distance(const char *s1, const char *s2);

/**
 * @brief Computes the edit distance between two strings using dynamic programming.
 * 
 * This function calculates the edit distance between `s1` and `s2` by filling a dynamic
 * programming table based on previous computations to determine the minimum number of
 * operations (insertions and deletions) required.
 * 
 * @param s1 Pointer to the first string.
 * @param s2 Pointer to the second string.
 * @return The edit distance between the two strings.
 */
int edit_distance_dyn(const char *s1, const char *s2);

#endif // EDIT_DISTANCE_H
