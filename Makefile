# Makefile for LinkedList Implementation
# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

# Target executable
TARGET = linkedlist

# Source files
SOURCES = linkedlist.c

# Header files
HEADERS = linkedlist.h

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean up generated files
clean:
	rm -f $(TARGET)

# Help target
help:
	@echo "Available targets:"
	@echo "  all     - Build the linkedlist executable (default)"
	@echo "  run     - Build and run the program"
	@echo "  clean   - Remove generated files"
	@echo "  help    - Show this help message"

.PHONY: all run clean help