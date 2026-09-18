/**
 * Name: Kaustuv Rimal
 * Description: Implementation file for the templated LinkedList class.
 *              Contains the complete implementation of all class methods
 *              and explicit instantiations for the int data type.
 */

#include "LinkedList.h"

// Default constructor: empty list with null head/tail and zero count
template <typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
    count = 0;
}

// Destructor: traverses the list and deletes every node
template <typename T>
LinkedList<T>::~LinkedList() {
    ListNode<T>* current = head;
    while (current != nullptr) {
        ListNode<T>* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
    tail = nullptr;
    count = 0;
}

// Appends a new item to the end of the list
template <typename T>
void LinkedList<T>::addItem(T item) {
    ListNode<T>* newNode = new ListNode<T>;
    newNode->data = item;
    newNode->next = nullptr;

    if (head == nullptr) {
        // First node in the list
        head = newNode;
        tail = newNode;
    } else {
        // Link the new node after the current tail and update tail
        tail->next = newNode;
        tail = newNode;
    }
    count++;
}

// Removes the first occurrence of a given item from the list
template <typename T>
void LinkedList<T>::remove(T item) {
    // Empty list: nothing to remove
    if (head == nullptr) {
        return;
    }

    // Special case: removing the head node
    if (head->data == item) {
        ListNode<T>* nodeToDelete = head;
        head = head->next;
        // If the list becomes empty, tail must also be null
        if (head == nullptr) {
            tail = nullptr;
        }
        delete nodeToDelete;
        count--;
        return;
    }

    // General case: search for the item starting from the second node
    ListNode<T>* current = head;
    while (current->next != nullptr && current->next->data != item) {
        current = current->next;
    }

    // If found, unlink and delete the node
    if (current->next != nullptr) {
        ListNode<T>* nodeToDelete = current->next;
        current->next = nodeToDelete->next;
        // If we removed the tail, update tail pointer
        if (nodeToDelete == tail) {
            tail = current;
        }
        delete nodeToDelete;
        count--;
    }
}

// Returns true if the given item is present in the list
template <typename T>
bool LinkedList<T>::find(T item) const {
    ListNode<T>* current = head;
    while (current != nullptr) {
        if (current->data == item) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Returns the number of items in the list
template <typename T>
int LinkedList<T>::getSize() const {
    return count;
}

// Explicit instantiations for the int data type
template class LinkedList<int>;
