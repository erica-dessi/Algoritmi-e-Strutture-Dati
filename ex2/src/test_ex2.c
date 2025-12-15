#include <stdio.h>
#include <string.h>
#include "edit_distance.h"
#define UNITY_H
#include "unity.h"

/**
 * @brief Runs tests for the `edit_distance` function.
 * 
 * This function executes a series of tests to verify the correctness of the `edit_distance`
 * function. It prints the results of each test, comparing the output of the function with
 * the expected values.
 */
void run_edit_distance_tests() {
    printf("--- Running edit_distance tests ---\n");
    printf("edit_distance(\"casa\", \"cassa\") = %d (expected 1)\n", edit_distance("casa", "cassa"));
    printf("edit_distance(\"casa\", \"cara\") = %d (expected 2)\n", edit_distance("casa", "cara"));
    printf("edit_distance(\"vinaio\", \"vino\") = %d (expected 2)\n", edit_distance("vinaio", "vino"));
    printf("edit_distance(\"tassa\", \"passato\") = %d (expected 4)\n", edit_distance("tassa", "passato"));
    printf("edit_distance(\"pioppo\", \"pioppo\") = %d (expected 0)\n", edit_distance("pioppo", "pioppo"));
}

/**
 * @brief Runs tests for the `edit_distance_dyn` function.
 * 
 * This function executes a series of tests to verify the correctness of the `edit_distance_dyn`
 * function. It prints the results of each test, comparing the output of the function with
 * the expected values.
 */
void run_edit_distance_dyn_tests() {
    printf("--- Running edit_distance_dyn tests ---\n");
    printf("edit_distance_dyn(\"casa\", \"cassa\") = %d (expected 1)\n", edit_distance_dyn("casa", "cassa"));
    printf("edit_distance_dyn(\"casa\", \"cara\") = %d (expected 2)\n", edit_distance_dyn("casa", "cara"));
    printf("edit_distance_dyn(\"vinaio\", \"vino\") = %d (expected 2)\n", edit_distance_dyn("vinaio", "vino"));
    printf("edit_distance_dyn(\"tassa\", \"passato\") = %d (expected 4)\n", edit_distance_dyn("tassa", "passato"));
    printf("edit_distance_dyn(\"pioppo\", \"pioppo\") = %d (expected 0)\n", edit_distance_dyn("pioppo", "pioppo"));
}

/**
 * @brief Main function to execute all tests.
 * 
 * This function calls the test functions for both `edit_distance` and `edit_distance_dyn` to
 * ensure their correctness. It serves as the entry point for running the tests.
 * 
 * @return Exit status of the program.
 */
int main() {
    run_edit_distance_tests();
    run_edit_distance_dyn_tests();
    return 0;
}
