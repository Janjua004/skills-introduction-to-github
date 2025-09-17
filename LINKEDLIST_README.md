# Enhanced LinkedList Implementation

This repository contains a comprehensive linked list implementation in C with additional features as requested.

## Features

The implementation includes the following enhanced functionalities:

### 1. **insertAtLast**
- Inserts a node at the end of the linked list
- Handles empty list cases
- Provides informative success messages
- Includes memory allocation error handling

### 2. **insertAfterPosition**
- Inserts a node after a specified position (0-indexed)
- Validates position input (checks for negative values)
- Handles edge cases (empty list, invalid positions)
- Provides detailed error messages for invalid operations

### 3. **findLength**
- Efficiently calculates and returns the length of the linked list
- Traverses the list once to count nodes
- Returns 0 for empty lists

### 4. **Enhanced display Function**
- Shows the complete linked list structure in a clear format
- Displays nodes with arrows showing connections
- Shows the total length of the list
- Handles empty list display gracefully

## File Structure

```
linkedlist.h    - Header file with function declarations and struct definitions
linkedlist.c    - Main implementation file with all functions and demo
Makefile        - Build configuration for easy compilation
```

## Building and Running

### Using Makefile (Recommended)

```bash
# Build the project
make

# Build and run
make run

# Clean generated files
make clean

# Show help
make help
```

### Manual Compilation

```bash
gcc -Wall -Wextra -std=c99 -g -o linkedlist linkedlist.c
./linkedlist
```

## Function Documentation

### `struct Node`
```c
struct Node {
    int data;
    struct Node* next;
};
```
Basic node structure containing integer data and pointer to next node.

### `insertAtLast(struct Node** head, int data)`
- **Parameters**: Double pointer to head, data to insert
- **Purpose**: Inserts a new node at the end of the list
- **Error Handling**: Checks for memory allocation failures

### `insertAfterPosition(struct Node* head, int position, int data)`
- **Parameters**: Head pointer, position (0-indexed), data to insert
- **Purpose**: Inserts a new node after the specified position
- **Error Handling**: Validates position, checks for empty list, handles out-of-bounds

### `findLength(struct Node* head)`
- **Parameters**: Head pointer
- **Returns**: Integer count of nodes in the list
- **Purpose**: Efficiently counts and returns the number of nodes

### `display(struct Node* head)`
- **Parameters**: Head pointer
- **Purpose**: Displays the complete list structure with visual arrows and length
- **Features**: Shows empty list status, node connections, and total count

## Demo Output

The program includes a comprehensive demo that tests all functions:

```
=== Linked List Implementation Demo ===

1. Testing empty list:
List is empty: NULL
Length: 0

2. Testing insertAtLast function:
Successfully inserted 10 as the first node.
Successfully inserted 20 at the end of the list.
...

List contents: [10] -> [15] -> [20] -> [25] -> [30] -> [40] -> NULL
Length: 6 nodes
```

## Error Handling

The implementation includes robust error handling for:
- Memory allocation failures
- Invalid position inputs (negative numbers)
- Operations on empty lists
- Out-of-bounds position access

## Memory Management

- All dynamically allocated memory is properly freed
- `freeList()` function safely deallocates all nodes
- No memory leaks when used correctly

## Code Quality Features

- **Comprehensive Comments**: All functions are well-documented
- **Error Messages**: Informative error messages for debugging
- **Modular Design**: Clean separation between header and implementation
- **Professional Structure**: Follows C programming best practices
- **Build System**: Makefile for easy compilation and testing