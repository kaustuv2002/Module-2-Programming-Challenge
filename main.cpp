/*
 * Name: Kaustuv Rimal
 * Description: Driver program that tests the LinkedList class with
 *              integers. It adds many items, removes the first, last,
 *              and middle items, removes items that are not in the
 *              list, removes every item, and prints the size and
 *              contents of the list after each step.
 */

#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList<int> list;

    // Empty list
    cout << "Empty list" << endl;
    cout << "Size: " << list.getSize() << endl;
    cout << "List: " << list << endl;

    // Add a large number of items
    cout << "\nAdding 1 through 20" << endl;
    for (int i = 1; i <= 20; i++)
    {
        list.addItem(i);
    }
    cout << "Size: " << list.getSize() << endl;
    cout << "List: " << list << endl;

    // Find
    cout << "\nFind 10: " << (list.find(10) ? "found" : "not found") << endl;
    cout << "Find 500: " << (list.find(500) ? "found" : "not found") << endl;

    // Remove first, middle, and last items
    cout << "\nRemoving first item (1)" << endl;
    list.remove(1);
    cout << "Size: " << list.getSize() << endl;
    cout << "List: " << list << endl;

    cout << "\nRemoving middle item (10)" << endl;
    list.remove(10);
    cout << "Size: " << list.getSize() << endl;
    cout << "List: " << list << endl;

    cout << "\nRemoving last item (20)" << endl;
    list.remove(20);
    cout << "Size: " << list.getSize() << endl;
    cout << "List: " << list << endl;

    // Remove an item that is not in the list
    cout << "\nRemoving 500 (not in list)" << endl;
    list.remove(500);
    cout << "Size: " << list.getSize() << endl;
    cout << "List: " << list << endl;

    // Remove every item
    cout << "\nRemoving every item" << endl;
    for (int i = 1; i <= 20; i++)
    {
        list.remove(i);
    }
    cout << "Size: " << list.getSize() << endl;
    cout << "List: " << list << endl;

    return 0;
}