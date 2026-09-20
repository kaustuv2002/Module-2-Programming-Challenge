/*
 * Name: Kaustuv Rimal
 * Description: Defines a templated singly linked list class. The list
 *              keeps head and tail pointers and a count of its items.
 *              Methods are implemented in LinkedList.cpp, except the
 *              friend insertion operator, which is implemented here.
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <typename T> struct ListNode {

   T data;

   ListNode* next;

};

template <typename T>
class LinkedList
{
private:
    ListNode<T>* head;   // first node in the list
    ListNode<T>* tail;   // last node in the list
    int size;            // number of items in the list

public:
    LinkedList();
    ~LinkedList();

    void addItem(T item);
    void remove(T item);
    bool find(T item) const;
    int getSize() const;

    // Outputs each value in the list to the given ostream
    friend std::ostream& operator<<(std::ostream& out,
                                    const LinkedList<T>& list)
    {
        ListNode<T>* current = list.head;

        while (current != nullptr)
        {
            out << current->data << " ";
            current = current->next;
        }

        return out;
    }
};

#endif