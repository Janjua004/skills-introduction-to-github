#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

/**
 * Function to create a new node with given data
 * @param data: The integer value to store in the node
 * @return: Pointer to the newly created node
 */
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/**
 * Function to insert a node at the end of the linked list
 * @param head: Double pointer to the head of the list
 * @param data: The data to insert
 */
void insertAtLast(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL) {
        return; // Memory allocation failed
    }
    
    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = newNode;
        printf("Successfully inserted %d as the first node.\n", data);
        return;
    }
    
    // Traverse to the last node
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    // Link the new node at the end
    current->next = newNode;
    printf("Successfully inserted %d at the end of the list.\n", data);
}

/**
 * Function to insert a node after a specified position
 * @param head: Pointer to the head of the list
 * @param position: The position after which to insert (0-indexed)
 * @param data: The data to insert
 */
void insertAfterPosition(struct Node* head, int position, int data) {
    // Check if position is valid (non-negative)
    if (position < 0) {
        printf("Error: Position cannot be negative!\n");
        return;
    }
    
    // Check if list is empty
    if (head == NULL) {
        printf("Error: Cannot insert after position %d in an empty list!\n", position);
        return;
    }
    
    struct Node* current = head;
    int currentPos = 0;
    
    // Traverse to the specified position
    while (current != NULL && currentPos < position) {
        current = current->next;
        currentPos++;
    }
    
    // Check if position exists
    if (current == NULL) {
        printf("Error: Position %d does not exist in the list!\n", position);
        return;
    }
    
    // Create new node
    struct Node* newNode = createNode(data);
    if (newNode == NULL) {
        return; // Memory allocation failed
    }
    
    // Insert the new node after the current position
    newNode->next = current->next;
    current->next = newNode;
    printf("Successfully inserted %d after position %d.\n", data, position);
}

/**
 * Function to calculate and return the length of the linked list
 * @param head: Pointer to the head of the list
 * @return: The number of nodes in the list
 */
int findLength(struct Node* head) {
    int length = 0;
    struct Node* current = head;
    
    // Traverse the entire list and count nodes
    while (current != NULL) {
        length++;
        current = current->next;
    }
    
    return length;
}

/**
 * Function to display the linked list structure in a clear format
 * @param head: Pointer to the head of the list
 */
void display(struct Node* head) {
    printf("\n=== Linked List Structure ===\n");
    
    if (head == NULL) {
        printf("List is empty: NULL\n");
        printf("Length: 0\n");
        return;
    }
    
    struct Node* current = head;
    int position = 0;
    
    printf("List contents: ");
    while (current != NULL) {
        printf("[%d]", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
        position++;
    }
    printf(" -> NULL\n");
    
    printf("Length: %d nodes\n", findLength(head));
    printf("=============================\n\n");
}

/**
 * Function to free all memory allocated for the linked list
 * @param head: Double pointer to the head of the list
 */
void freeList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    *head = NULL;
    printf("Memory successfully freed.\n");
}

/**
 * Main function to demonstrate all linked list operations
 */
int main() {
    struct Node* head = NULL;
    
    printf("=== Linked List Implementation Demo ===\n\n");
    
    // Test 1: Display empty list
    printf("1. Testing empty list:\n");
    display(head);
    
    // Test 2: Insert nodes at the end
    printf("2. Testing insertAtLast function:\n");
    insertAtLast(&head, 10);
    insertAtLast(&head, 20);
    insertAtLast(&head, 30);
    insertAtLast(&head, 40);
    display(head);
    
    // Test 3: Test findLength function
    printf("3. Testing findLength function:\n");
    int length = findLength(head);
    printf("Current list length: %d\n\n", length);
    
    // Test 4: Insert after specific positions
    printf("4. Testing insertAfterPosition function:\n");
    
    // Insert after position 0 (after first node)
    insertAfterPosition(head, 0, 15);
    display(head);
    
    // Insert after position 2
    insertAfterPosition(head, 2, 25);
    display(head);
    
    // Test edge cases for insertAfterPosition
    printf("5. Testing edge cases for insertAfterPosition:\n");
    
    // Try to insert after invalid position
    insertAfterPosition(head, 10, 99);
    
    // Try to insert after negative position
    insertAfterPosition(head, -1, 99);
    
    // Test with empty list
    struct Node* emptyHead = NULL;
    insertAfterPosition(emptyHead, 0, 99);
    
    // Final display
    printf("\n6. Final list state:\n");
    display(head);
    
    // Test final length
    printf("7. Final length check:\n");
    printf("Final list length: %d\n\n", findLength(head));
    
    // Clean up memory
    printf("8. Cleaning up memory:\n");
    freeList(&head);
    display(head);
    
    printf("=== Demo completed successfully! ===\n");
    
    return 0;
}