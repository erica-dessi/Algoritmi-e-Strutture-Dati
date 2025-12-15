CC = gcc
all: bin/edit_distance bin/test_ex2

CFLAGS = -g -Wall -Wextra -Wpedantic -Wconversion

INCLUDES = src/*.h

COMMON_DEPS = $(INCLUDES) Makefile

# Rule for compiling .c files into .o files in the build directory
build/%.o: src/%.c $(COMMON_DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for creating the edit_distance binary
bin/edit_distance: build/edit_distance.o build/main_ex2.o $(COMMON_DEPS)
	$(CC) -o bin/edit_distance build/edit_distance.o build/main_ex2.o

# Rule for creating the test_ex2 binary
bin/test_ex2: build/test_ex2.o build/edit_distance.o build/unity.o $(COMMON_DEPS)
	$(CC) -o bin/test_ex2 build/test_ex2.o build/edit_distance.o build/unity.o

# Rule to run the program with input files
run: bin/edit_distance
	./bin/edit_distance edit_distance_test/dictionary.txt edit_distance_test/correctme.txt

# Rule to clean up compiled files
clean:
	rm -f build/* bin/*
