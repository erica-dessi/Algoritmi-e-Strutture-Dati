#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "edit_distance.h"

#define MAXLEN 100000 // Maximum length of strings considered
#define MAX_WORD_LENGTH 1000  // Maximum length of a word

/**
 * @brief Checks if a character is a letter.
 * 
 * This function determines if a given character is a letter (either uppercase or lowercase).
 * 
 * @param c Character to check.
 * @return Non-zero value if the character is a letter, zero otherwise.
 */
int is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

/**
 * @brief Removes punctuation from a word.
 * 
 * This function removes any non-letter characters from the input word.
 * 
 * @param word Pointer to the word from which punctuation should be removed.
 */
void remove_punctuation(char *word) {
    char *src = word, *dst = word;
    while (*src) {
        if (is_letter(*src)) {
            *dst++ = *src;
        }
        src++;
    }
    *dst = '\0';
}

/**
 * @brief Finds the closest word in the dictionary to the given word.
 * 
 * This function searches for the word in the dictionary that has the smallest edit distance
 * to the given word and is within the specified edit distance threshold.
 * 
 * @param word Pointer to the word to be corrected.
 * @param dictionary Array of pointers to dictionary words.
 * @param dict_size Number of words in the dictionary.
 * @param edit_distance_threshold Maximum allowed edit distance.
 * @return Pointer to the closest word found in the dictionary, or NULL if no close word is found.
 */
char* find_closest_word(char *word, char **dictionary, int dict_size, int edit_distance_threshold) {
    int min_distance = MAXLEN;
    char *closest_word = NULL;
    for (int i = 0; i < dict_size; ++i) {
        int dist = edit_distance_dyn(word, dictionary[i]);
        if (dist <= edit_distance_threshold && dist < min_distance) {
            min_distance = dist;
            closest_word = dictionary[i];
        }
    }
    return closest_word;
}

/**
 * @brief Corrects the text using the provided dictionary.
 * 
 * This function reads a text file, processes each word by removing punctuation, checks if the
 * word is in the dictionary, and if not, replaces it with the closest word from the dictionary
 * that is within the edit distance threshold. The corrected text is then written to an output file.
 * 
 * @param dictionary_file Path to the dictionary file.
 * @param text_file Path to the text file to be corrected.
 */
void correct_text(const char *dictionary_file, const char *text_file) {
    char **dictionary = NULL;
    int dict_size = 0;

    // Open the dictionary file
    FILE *dict = fopen(dictionary_file, "r");
    if (!dict) {
        perror("Error opening dictionary file");
        exit(EXIT_FAILURE);
    }

    printf("Dictionary file opened successfully.\n");

    // Read the dictionary
    char line[MAX_WORD_LENGTH];
    while (fgets(line, sizeof(line), dict)) {
        line[strcspn(line, "\n")] = '\0'; // Remove newline character
        // Reallocate memory for a new word
        char **temp = realloc(dictionary, (dict_size + 1) * sizeof(char *));
        if (!temp) {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }
        dictionary = temp;
        // Allocate memory for the new word
        dictionary[dict_size] = malloc(strlen(line) + 1);
        if (!dictionary[dict_size]) {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }
        // Copy the word into the dictionary
        strcpy(dictionary[dict_size], line);
        dict_size++;
    }
    fclose(dict);

    printf("Dictionary read successfully. Number of words: %d\n", dict_size);

    // Open the text file to correct
    FILE *text = fopen(text_file, "r");
    if (!text) {
        perror("Error opening text file to correct");
        exit(EXIT_FAILURE);
    }

    printf("Text file opened successfully.\n");

    FILE *output = fopen("corrected_text.txt", "w");
    if (!output) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    char line_text[MAXLEN];

    // Define the edit distance threshold
    int edit_distance_threshold = 2; // Can be adjusted as needed

    // Correct each line of the text
    while (fgets(line_text, sizeof(line_text), text)) {
        char *word = strtok(line_text, " \t\n");
        while (word != NULL) {
            char original_word[MAX_WORD_LENGTH];
            strcpy(original_word, word);
            char word_no_punct[MAX_WORD_LENGTH];
            strcpy(word_no_punct, word);
            remove_punctuation(word_no_punct);

            int in_dictionary = 0;

            // Check if the word is in the dictionary
            for (int i = 0; i < dict_size; ++i) {
                if (strcasecmp(word_no_punct, dictionary[i]) == 0) { // Case insensitive comparison
                    in_dictionary = 1;
                    break;
                }
            }

            // If the word is not in the dictionary, correct it
            if (!in_dictionary) {
                char *closest_word = find_closest_word(word_no_punct, dictionary, dict_size, edit_distance_threshold);

                // If an alternative word is found, replace it
                if (closest_word) {
                    printf("%s -> %s\n", original_word, closest_word);
                    fprintf(output, "%s ", closest_word);
                } else {
                    printf("%s\n", original_word);
                    fprintf(output, "%s ", original_word);
                }
            } else {
                printf("%s\n", original_word);
                fprintf(output, "%s ", original_word);
            }

            word = strtok(NULL, " \t\n");
        }
        fprintf(output, "\n");
    }

    // Free the memory allocated for the dictionary
    for (int i = 0; i < dict_size; ++i) {
        free(dictionary[i]);
    }
    free(dictionary);

    fclose(text);
    fclose(output);
}

/**
 * @brief Main function for the text correction program.
 * 
 * This function parses command-line arguments to obtain the paths for the dictionary file and the
 * text file to be corrected. It then calls the `correct_text` function to perform the correction.
 * 
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return Exit status of the program.
 */
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <dictionary_file> <text_file_to_correct>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char dictionary_path[MAXLEN];
    char text_path[MAXLEN];
    sprintf(dictionary_path, "%s", argv[1]);
    sprintf(text_path, "%s", argv[2]);

    printf("Dictionary path: %s\n", dictionary_path);
    printf("Text file to correct: %s\n", text_path);

    correct_text(dictionary_path, text_path);

    return EXIT_SUCCESS;
}
