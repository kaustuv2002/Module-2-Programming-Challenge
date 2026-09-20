/*
 * Name: Kaustuv Rimal
 * Description: Implements the methods of the templated LinkedList
 *              class declared in LinkedList.h. Each method is
 *              instantiated for int at the bottom of the file.
 */

#include "LinkedList.h"

// Creates an empty list
template <typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// Deallocates every node in the list
template <typename T>
LinkedList<T>::~LinkedList()
{
    ListNode<T>* current = head;

    while (current != nullptr)
    {
        ListNode<T>* nextNode = current->next;   // save before deleting
        delete current;
        current = nextNode;
    }
}

// Appends a new item to the end of the list
template <typename T>
void LinkedList<T>::addItem(T item)
{
    ListNode<T>* newNode = new ListNode<T>;
    newNode->data = item;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        // Empty list: the new node is both head and tail
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }

    size++;
}

// Removes the first node holding item; no action if it is not found
template <typename T>
void LinkedList<T>::remove(T item)
{
    if (head == nullptr)
    {
        return;
    }

    // Item is in the first node
    if (head->data == item)
    {
        ListNode<T>* nodeToDelete = head;
        head = head->next;

        // List is now empty, so the tail must be reset too
        if (head == nullptr)
        {
            tail = nullptr;
        }

        delete nodeToDelete;
        size--;
        return;
    }

    // Find the node just before the one to remove
    ListNode<T>* previous = head;

    while (previous->next != nullptr && previous->next->data != item)
    {
        previous = previous->next;
    }

    // Item not found
    if (previous->next == nullptr)
    {
        return;
    }

    ListNode<T>* nodeToDelete = previous->next;
    previous->next = nodeToDelete->next;

    // If the last node was removed, update the tail
    if (nodeToDelete == tail)
    {
        tail = previous;
    }

    delete nodeToDelete;
    size--;
}

// Returns true if item is in the list
template <typename T>
bool LinkedList<T>::find(T item) const
{
    ListNode<T>* current = head;

    while (current != nullptr)
    {
        if (current->data == item)
        {
            return true;
        }
        current = current->next;
    }

    return false;
}

// Returns the number of items in the list
template <typename T>
int LinkedList<T>::getSize() const
{
    return size;
}

// Instantiate each method for int
template LinkedList<int>::LinkedList();
template LinkedList<int>::~LinkedList();
template void LinkedList<int>::addItem(int item);
template void LinkedList<int>::remove(int item);
template bool LinkedList<int>::find(int item) const;
template int LinkedList<int>::getSize() const;