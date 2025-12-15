#include "edit_distance.h"
#include <stdio.h>
#include <string.h>
#define MAXLEN 1000 // Maximum length of strings considered

/**
 * @brief Returns the minimum of two integers.
 * 
 * @param a First integer.
 * @param b Second integer.
 * @return The smaller of the two integers.
 */
static int min(int a, int b) {
    return (a < b) ? a : b;
}

/**
 * @brief Recursively calculates the edit distance between two strings using memoization.
 * 
 * This function calculates the edit distance between two strings `s1` and `s2` by recursively
 * computing the cost of insertions, deletions, and substitutions, and storing the results in a
 * memoization table to avoid redundant computations.
 * 
 * @param s1 First string.
 * @param s2 Second string.
 * @param len1 Length of the first string.
 * @param len2 Length of the second string.
 * @param memo 2D array used for memoization.
 * @return The edit distance between the two strings.
 */
static int edit_distance_recursive(const char *s1, const char *s2, int len1, int len2, int memo[MAXLEN + 1][MAXLEN + 1]) {
    if (memo[len1][len2] != -1) return memo[len1][len2];

    if (len1 == 0) return len2;
    if (len2 == 0) return len1;

    if (s1[0] == s2[0]) {
        memo[len1][len2] = edit_distance_recursive(s1 + 1, s2 + 1, len1 - 1, len2 - 1, memo);
    } else {
        int insert = 1 + edit_distance_recursive(s1, s2 + 1, len1, len2 - 1, memo); // Insert
        int delete = 1 + edit_distance_recursive(s1 + 1, s2, len1 - 1, len2, memo); // Delete
        memo[len1][len2] = min(insert, delete);
    }

    return memo[len1][len2];
}

/**
 * @brief Computes the edit distance between two strings using recursive approach with memoization.
 * 
 * This function initializes the memoization table and calls the recursive function to calculate
 * the edit distance between `s1` and `s2`.
 * 
 * @param s1 First string.
 * @param s2 Second string.
 * @return The edit distance between the two strings.
 */
int edit_distance(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int memo[MAXLEN + 1][MAXLEN + 1];
    for (int i = 0; i <= len1; ++i)
        for (int j = 0; j <= len2; ++j)
            memo[i][j] = -1;

    return edit_distance_recursive(s1, s2, len1, len2, memo);
}

/**
 * @brief Computes the edit distance between two strings using dynamic programming.
 * 
 * This function calculates the edit distance between `s1` and `s2` by filling a dynamic
 * programming table based on the previous computations to determine the minimum number of
 * operations (insertions and deletions) required.
 * 
 * @param s1 First string.
 * @param s2 Second string.
 * @return The edit distance between the two strings.
 */
int edit_distance_dyn(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int memo[MAXLEN + 1][MAXLEN + 1];

    for (int i = 0; i <= len1; ++i) {
        for (int j = 0; j <= len2; ++j) {
            if (i == 0) {
                memo[i][j] = j; // If s1 is empty, all characters of s2 need to be inserted
            } else if (j == 0) {
                memo[i][j] = i; // If s2 is empty, all characters of s1 need to be deleted
            } else if (s1[i - 1] == s2[j - 1]) {
                memo[i][j] = memo[i - 1][j - 1]; // Characters match, no operation needed
            } else {
                memo[i][j] = 1 + min(memo[i - 1][j],  // Delete
                                    memo[i][j - 1]); // Insert
            }
        }
    }

    return memo[len1][len2];
}
