#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/**
 * @file linkedlist.h
 * @brief Header file for enhanced linked list implementation
 * 
 * This header file contains declarations for a comprehensive linked list
 * implementation with insertion, length calculation, and display functions.
 */

/**
 * Node structure for the linked list
 * Contains data and a pointer to the next node
 */
struct Node {
    int data;
    struct Node* next;
};

/**
 * Function declarations for linked list operations
 */

/**
 * Creates a new node with given data
 * @param data: The integer value to store in the node
 * @return: Pointer to the newly created node, NULL if allocation fails
 */
struct Node* createNode(int data);

/**
 * Inserts a node at the end of the linked list
 * @param head: Double pointer to the head of the list
 * @param data: The data to insert
 */
void insertAtLast(struct Node** head, int data);

/**
 * Inserts a node after a specified position
 * @param head: Pointer to the head of the list
 * @param position: The position after which to insert (0-indexed)
 * @param data: The data to insert
 */
void insertAfterPosition(struct Node* head, int position, int data);

/**
 * Calculates and returns the length of the linked list
 * @param head: Pointer to the head of the list
 * @return: The number of nodes in the list
 */
int findLength(struct Node* head);

/**
 * Displays the linked list structure in a clear format
 * @param head: Pointer to the head of the list
 */
void display(struct Node* head);

/**
 * Frees all memory allocated for the linked list
 * @param head: Double pointer to the head of the list
 */
void freeList(struct Node** head);

#endif /* LINKEDLIST_H */