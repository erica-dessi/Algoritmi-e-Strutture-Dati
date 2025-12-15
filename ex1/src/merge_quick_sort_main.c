/**
 * @file merge_quick_sort.c
 * @brief This file contains implementations for sorting records using Merge Sort and Quick Sort.
 * 
 * The program reads records from an input CSV file, sorts them based on a specified field and sorting algorithm,
 * and writes the sorted records to an output CSV file.
 */

#include "merge_quick_sort.h"

#define MAX_RECORDS  20000000 /**< Maximum number of records to be handled */

/**
 * @struct Record
 * @brief Structure to represent a single record in the dataset.
 * 
 * Contains fields for an ID, a string field, an integer field, and a floating-point field.
 */
typedef struct {
    int id; /**< Unique identifier for the record */
    char string_field[20]; /**< String field of the record */
    int integer_field; /**< Integer field of the record */
    float floating_field; /**< Floating-point field of the record */
} Record;

/**
 * @typedef compare_func
 * @brief Function pointer type for comparison functions used in sorting.
 * 
 * Points to a function that compares two records and returns an integer value.
 */
typedef int (*compare_func)(const void*, const void*);

/**
 * @brief Handles error reporting and program termination.
 * 
 * @param filename The name of the source file where the error occurred.
 * @param line The line number in the source file where the error occurred.
 * @param message The error message to be reported.
 */
void handle_error(const char *filename, int line, const char *message) {
    fprintf(stderr, "%s:%d %s", filename, line, message);
    exit(1);
}

/**
 * @brief Comparator function for sorting by the string field of the record.
 * 
 * @param r1_p Pointer to the first record.
 * @param r2_p Pointer to the second record.
 * @return An integer less than, equal to, or greater than zero if the first record is less than, equal to,
 *         or greater than the second record, respectively.
 */
int comparator_record_string_field(const void *r1_p, const void *r2_p) {
    const char *rec1_p = ((Record *)r1_p)->string_field;
    const char *rec2_p = ((Record *)r2_p)->string_field;
    return strcmp(rec1_p, rec2_p);
}

/**
 * @brief Comparator function for sorting by the integer field of the record.
 * 
 * @param r1_p Pointer to the first record.
 * @param r2_p Pointer to the second record.
 * @return An integer less than, equal to, or greater than zero if the integer field of the first record is less 
 *         than, equal to, or greater than the integer field of the second record, respectively.
 */
int comparator_record_integer_field(const void *r1_p, const void *r2_p) {
    int rec1_p = ((Record *)r1_p)->integer_field;
    int rec2_p = ((Record *)r2_p)->integer_field;
    return rec1_p - rec2_p;
}

/**
 * @brief Comparator function for sorting by the floating-point field of the record.
 * 
 * @param r1_p Pointer to the first record.
 * @param r2_p Pointer to the second record.
 * @return An integer less than, equal to, or greater than zero if the floating-point field of the first record is 
 *         less than, equal to, or greater than the floating-point field of the second record, respectively.
 */
int comparator_record_floating_field(const void *r1_p, const void *r2_p) {
    float rec1_p = ((Record *)r1_p)->floating_field;
    float rec2_p = ((Record *)r2_p)->floating_field;
    if (rec1_p > rec2_p)
        return 1;
    else if (rec2_p > rec1_p)
        return -1;
    else
        return 0;
}

/**
 * @brief Returns the appropriate comparator function based on the specified field.
 * 
 * @param field The field to be used for sorting (1 for string, 2 for integer, 3 for floating-point).
 * @return A pointer to the comparator function for the specified field.
 */
compare_func get_comparator_for_field(size_t field) {
    switch (field) {
        case 1:
            return comparator_record_string_field;
        case 2:
            return comparator_record_integer_field;
        case 3:
            return comparator_record_floating_field;
        default:
            handle_error(__FILE__, __LINE__, "Field should be 1 (string), 2 (integer) or 3 (double)\n");
            return NULL;
    }
}

/**
 * @brief Prints the records to the specified output file.
 * 
 * @param records Array of pointers to the records to be printed.
 * @param output_file The file to which records will be printed.
 */
void print_records(Record *records[], FILE *output_file) {
    for (size_t j = 0; j < MAX_RECORDS ; j++) {
        fprintf(output_file, "%d,%s,%d,%f\n",
                records[j]->id,
                records[j]->string_field,
                records[j]->integer_field,
                records[j]->floating_field
        );
    }
}

/**
 * @brief Executes the sorting algorithm on the records based on the specified field.
 * 
 * @param field The field to be used for sorting (1 for string, 2 for integer, 3 for floating-point).
 * @param algo The sorting algorithm to be used (1 for Merge Sort, 2 for Quick Sort).
 * @param records Array of pointers to the records to be sorted.
 */
void execute_sorting_algorithm(size_t field, size_t algo, Record *records[]) {
    int (*compar)(const void*, const void*) = get_comparator_for_field(field);
    switch (algo) {
        case 1:
            merge_sort((void **)records, MAX_RECORDS , compar);
            break;
        case 2:
            quick_sort((void **)records, MAX_RECORDS , compar);
            break;
        default:
            handle_error(__FILE__, __LINE__, "Algorithm should be 1 (MergeSort) or 2 (QuickSort)\n");
    }
}

/**
 * @brief Loads records from the input file into the records array.
 * 
 * @param input_file The file from which records will be read.
 * @param records Array of pointers to the records to be populated.
 */
void load_records(FILE *input_file, Record *records[]) {
    size_t count = 0;
    int read_result;
    while (count < MAX_RECORDS  && (read_result = fscanf(input_file, "%d,%19[^,],%d,%f",
        &(records[count]->id), records[count]->string_field, &(records[count]->integer_field), &(records[count]->floating_field))) != EOF) {
        count++;
    }
}

/**
 * @brief Main function to handle sorting of records from an input file to an output file.
 * 
 * @param input_file The file containing records to be sorted.
 * @param output_file The file to which sorted records will be written.
 * @param field The field to be used for sorting (1 for string, 2 for integer, 3 for floating-point).
 * @param algo The sorting algorithm to be used (1 for Merge Sort, 2 for Quick Sort).
 */
void sort_records(FILE *input_file, FILE *output_file, size_t field, size_t algo) {
    clock_t clock_time;
    Record **records = (Record **) malloc(MAX_RECORDS  * sizeof(Record *));
    if (records != NULL) {
        for (size_t i = 0; i < MAX_RECORDS ; i++) {
            records[i] = (Record *) malloc(sizeof(Record));
            if (records[i] == NULL) {
                handle_error(__FILE__, __LINE__, "Memory allocation failed\n");
            }
        }

        printf("Loading data from records.csv...\n");
        load_records(input_file, records);
        
        clock_time = clock();
        execute_sorting_algorithm(field, algo, records);
        clock_time = clock() - clock_time;
        printf("Sorting took %ld seconds\n", clock_time / CLOCKS_PER_SEC);
        
        printf("Printing sorted records to sorted.csv...\n");
        print_records(records, output_file);

        for (size_t i = 0; i < MAX_RECORDS ; i++) {
            free(records[i]);
        }
        free(records);
    } else {
        handle_error(__FILE__, __LINE__, "Error! Insufficient memory to load all the records");
    }
}

/**
 * @brief Main entry point of the program.
 * 
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @return 0 on successful completion, or 1 if there is an error.
 */
int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <input_file>.csv <output_file>.csv 1(MergeSort)/2(QuickSort) 1(string)/2(integer)/3(double)\n", argv[0]);
        return 1;
    }

    char *input_filePath = argv[1];
    FILE *input_file;
    char *output_filePath = argv[2];
    FILE *output_file;
    int field = atoi(argv[3]);
    int algo = atoi(argv[4]);

    if (strcmp(input_filePath, output_filePath) == 0) {
        handle_error(__FILE__, __LINE__, "Input file and output file cannot be the same\n");
    }

    input_file = fopen(input_filePath, "r");
    if (input_file == NULL) {
        handle_error(__FILE__, __LINE__, "main: unable to open the input_file");
    }

    output_file = fopen(output_filePath, "w");
    if (output_file == NULL) {
        fclose(input_file);
        handle_error(__FILE__, __LINE__, "main: unable to open the output_file");
    }

    sort_records(input_file, output_file, (size_t)field, (size_t)algo);

    fclose(input_file);
    fclose(output_file);
    return 0;
}
