/** 
 * @file dll.h
 * @brief Header file for the Doubly Linked List implementation. 
 *
 * This file defines the data structures and function prototypes 
 * required for implementing a doubly linked list (DLL). It provides 
 * functionalities for inserting, removing, and searching nodes.
 * 
 * 
 * @authors Duarte Caldeira, Tiago Saraiva
 * @date 23 Mar 2025
 */

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define MAX_ELEMENTS 50
#define ELEMENT_SIZE 256

#define OK 0
#define DLL_FULL -1
#define NO_EMPTY_NODE -2
#define KEY_NOT_FOUND -3

/**
 * @struct DLL_Node
 * @brief Structure representing a node in the doubly linked list.
 *
 * This structure defines an individual node within the list.
 * Each node contains a unique key, stored data and pointers to the 
 * previous and next nodes in the sequence.
 */

typedef struct DLL_Node 
{
    uint16_t key;						/**< Unique key identifier for the node. */
    unsigned char data[ELEMENT_SIZE];	/**< Data stored in the node. */
    struct DLL_Node *prev;				/**< Pointer to the previous node. */
    struct DLL_Node *next;				/**< Pointer to the next node. */
    bool occupied;						/**< Flag to indicate if the node is in use. */
    
} DLL_Node;

/**
 * @struct DoublyLinkedList
 * @brief Structure representing the doubly linked list (DLL).
 *
 * This structure defines a doubly linked list (DLL).
 * It includes a statically allocated array of nodes, the current size 
 * of the list, and pointers to the first and last nodes.
 */

typedef struct 
{
	DLL_Node nodes[MAX_ELEMENTS];		/**< Array of nodes. */
    DLL_Node *head;						/**< Pointer to the first node in the list. */
    DLL_Node *tail;						/**< Pointer to the last node in the list. */
    int size;							/**< Current number of elements in the list. */
    int maxElements;					/**< Maximum number of elements allowed in the list. */
    
} DoublyLinkedList;

// Funções da DLL

/**
 * @brief Initializes the DLL.
 *
 * This function sets up the initial values of the list, setting the 
 * size to 0, the head and tail pointers to NULL, and marking all nodes
 * as unoccupied.
 *
 * @param list Pointer to the doubly linked list.
 * @param maxElements Maximum number of elements the list can hold.
 * @param elementSize Size of each element.
 */

void MYDLLInit(DoublyLinkedList *list, int maxElements, int elementSize);

/**
 * @brief Inserts a new element into the DLL.
 *
 * Finds a free node, copies the data, and adjusts the pointers to 
 * insert the new element.
 * If the list is full, it returns an error.
 *
 * @param list Pointer to the doubly linked list.
 * @param key Unique key for the new element.
 * @param data Pointer to the data to be stored.
 * @param dataSize Size of the data.
 * @return OK on success, DLL_FULL if the list is full, NO_EMPTY_NODE if no empty node is available.
 */

int MYDLLInsert(DoublyLinkedList *list, uint16_t key, unsigned char *data, int dataSize);

/**
 * @brief Removes an element from the DLL.
 *
 * Finds the node corresponding to the given key, adjusts the pointers
 * to remove it, and marks the node as available for reuse.
 *
 * @param list Pointer to the doubly linked list.
 * @param key Unique key of the element to be removed.
 * @return OK on success, KEY_NOT_FOUND if the key does not exist.
 */

int MYDLLRemove(DoublyLinkedList *list, uint16_t key);

/**
 * @brief Finds an element in the DLL by key.
 *
 * Iterates through the list until the matching key is found and returns
 * the stored data.
 * If the key is not found, returns NULL.
 *
 * @param list Pointer to the doubly linked list.
 * @param key Unique key of the element to find.
 * @return Pointer to the data if found, NULL otherwise.
 */

unsigned char *MYDLLFind(DoublyLinkedList *list, uint16_t key);

/**
 * @brief Finds the next element in the list after a given key.
 * 
 * The function searches for the current element using the provided ID. 
 * If the element is found, it checks whether a next element exists in 
 * the list. If there is a next element, the function returns its 
 * associated data. If the current element is the last in the list or 
 * the provided ID does not match any existing element, the function 
 * returns NULL.
 *
 * @param list Pointer to the doubly linked list.
 * @param key Unique key of the current element.
 * @return Pointer to the data of the next element, or NULL if not found.
 * 
 */

unsigned char *MYDLLFindNext(DoublyLinkedList *list, uint16_t key);

/**
 * @brief Finds the previous element in the list before a given key.
 * 
 * The function locates the current element using the given ID. If the 
 * element is found, it determines whether a previous element exists in 
 * the list. If a previous element is found, the function returns its 
 * associated data. If the current element is the first in the list or 
 * the provided ID does not correspond to any existing element, the 
 * function returns NULL.
 * 
 * @param list Pointer to the doubly linked list.
 * @param key Unique key of the current element.
 * @return Pointer to the data of the previous element, or NULL if not found.
 * 
 */

unsigned char *MYDLLFindPrevious(DoublyLinkedList *list, uint16_t key);

#endif
