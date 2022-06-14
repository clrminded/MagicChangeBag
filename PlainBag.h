#ifndef PLAINBAG_H
#define PLAINBAG_H

#include <iostream>
// uncomment to disable assert()
//#define NDEBUG
#include <cassert>
#include "BagInterface.h"

/** 
 * As you can see, the PlainBag class inherits from the BagInterface.
 * The PlainBag class is a concrete class because it can be instantiated.
 * There is still work that needs to be done on the private, public, and protected members between PlainBag and MagicChangeBag
 * but the remove() has been more optimized.
 */
template <class T>
class PlainBag:public BagInterface<T>
{
protected:
    static const int CAPACITY = 20;
    T data[CAPACITY];
    int count;
    virtual int size() const;
    virtual bool isEmpty() const;
    virtual bool isFull() const;
    virtual void print() const;

public:
    PlainBag();
    virtual void insert(T newItem);
    virtual bool contains(T item);
    virtual void remove(T item);
    virtual int itemCount(T item);
    virtual void clear();
    
};

/** 
 * Default constructor: when a PlainBag is instantiated the number of items will be 0. 
 * Meaning that we will always start out with an empty bag. 
 */
template <class T>
// This is the format to do a fast definition of a method.
PlainBag<T>::PlainBag() : count(0) {}

/** 
 * Insert an item of any type into a bag
 * @param newItem: when a new bag is initiated we start at index 0. 
 * Every time we insert an item into the bag, the counter variable will be incremented by 1. 
 */
template <class T>
void PlainBag<T>::insert(T newItem)
{
    if (!isFull())
    {
        data[count] = newItem;
        count++;
    }
    else 
    {
        std::cout << "Cannot insert any more items, the bag is full!" << std::endl;
    }
}

/** 
 * Tests whether this bag contains a given item.
 * @param item: The item to check if it is currently in the bag.
 * @return true if anItem is currently in the bag, otherwise false.
 * This can also be done using a for loop.
 */
template <class T>
bool PlainBag<T>::contains(T item)
{
    int i = 0;
    while (i < size())
    {
        if (data[i] == item)
        {
            return true;
        }
        i++;
    }
    return false;
}

/** 
 * This will remove an item from the bag
 * @param: item that we are trying to match and remove from the bag
 * while iterating through the bag, when we come across the item to remove, we will stop at that index,
 * then from that index we will assign the value of that index with the value of the index ahead of
 * it, thus removing the item from the list of contents in the bag. 
 */
template <class T>
void PlainBag<T>::remove(T item)
{
    // Check to make sure that the item is in the bag.
    if(!contains(item)) {
        std::cout << "The item does not exist, cannot remove an item that doesnt exist." << std::endl;
        return;
    }

    for(int i = 0; i < size(); i++) {
        if(data[i] == item) {
            for(int j = i; j < size()-1; j++) {
                data[j] = data[j+1];
            }
        }
    }
    count--;
}

/** 
 * Counts the number copies of this item that there are in the bag.
 * @param item: The item to be counted
 * @return the number of times item appears in the bag. 
 */
template <class T>
int PlainBag<T>::itemCount(T item)
{
    int num = 0;
    for (int i = 0; i < size(); i++)
        if (data[i] == item)
            num++;
    return num;
}

/** 
 * This will clear out the contents of the bag. Meaning that if
 * the current bag has items in it, the counter will reset to 0 
 */
template <class T>
void PlainBag<T>::clear()
{
    count = 0;
}

/** 
 * Gets the current number of items
 * @return The integer number of items currently in bag. 
 */
template <class T>
int PlainBag<T>::size() const
{
    return count;
}

/** 
 * Check to see if bag is empty
 * @return If the current bag has 0 items in it, we will consider the bag to be empty and will return true, 
 * otherwise will return false meaning that there are items in the bag. 
 */
template <class T>
bool PlainBag<T>::isEmpty() const 
{
    return count == 0;
}

/** 
 * Check to see if the bag is full
 * @return if there are 20 items in the bag, the bag is full and will
 * return true, otherwise return false 
 */
template <class T>
bool PlainBag<T>::isFull() const
{
    return count == CAPACITY;
}

/** 
 * The output will provide the contents that are currently in the bag 
 */
template <class T>
void PlainBag<T>::print() const
{
    std::cout << "\nBag content:";
    for (int i = 0; i < count; i++)
        std::cout << data[i] << " ";
}

#endif // PLAINBAG_H