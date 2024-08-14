# Makefile for a simple project

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -g

# Source files
SRC = src/*.c

# Executable name
EXEC = fm

# Default target: build the executable
build:
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC)

# Run the executable
run: build
	./$(EXEC)

# Clean up
clean:
	rm -f $(EXEC)

# PHONY targets to prevent issues with files named 'build', 'run', or 'clean'
.PHONY: build run clean

