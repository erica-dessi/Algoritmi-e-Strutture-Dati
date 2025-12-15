CC = gcc
all: bin/merge_quick_sort bin/merge_quick_sort_tests

CFLAGS = -g -Wall -Wextra -Wpedantic -Wconversion

INCLUDES = src/*.h

COMMON_DEPS = $(INCLUDES) Makefile

# Rule to compile .c files into .o files in the build directory
build/%.o: src/%.c $(COMMON_DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create the merge_quick_sort binary
bin/merge_quick_sort: build/merge_quick_sort.o build/merge_quick_sort_main.o $(COMMON_DEPS)
	$(CC) -o bin/merge_quick_sort build/merge_quick_sort.o build/merge_quick_sort_main.o

# Rule to create the merge_quick_sort_tests binary
bin/merge_quick_sort_tests: build/merge_quick_sort_tests.o build/merge_quick_sort.o build/unity.o $(COMMON_DEPS)
	$(CC) -o bin/merge_quick_sort_tests build/merge_quick_sort_tests.o build/merge_quick_sort.o build/unity.o

# Rule to clean up compiled files
clean:
	rm -f build/* bin/*
