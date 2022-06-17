#ifndef MAGIC_CHANGE_BAG_H
#define MAGIC_CHANGE_BAG_H

#include <iostream>
#include "BagInterface.h"
#include "PlainBag.h"

template <class T>
class MagicChangeBag : public PlainBag<T>
{
protected:
    int index;
    bool isMagic;

public:
    MagicChangeBag();
    void insert(T newItem);
    void remove(T item);
};

/**
 * Default constructor will clear out the bag to make sure we start with a new bag.
 * we also initiate the value for a variable that we will use as a helper counter that is based
 * on the "state" of the bag "isMagic" or not.
 */
template <class T>
MagicChangeBag<T>::MagicChangeBag() : index(0) { PlainBag<T>::clear(); }

/**
 * When we insert an item into the bag, we will consider the state of the bag to be "isMagic".
 * This means that even tho the item is going to be inserted into the bag, it will appear as tho the item has disappeared from the bag
 * and appear empty.
 * @param newItem: The item that we will be inserting into the bag.
 * When the bag is in the state of being magic, we will be using the index variable as the counter so counter can be stable and we can
 * modify the index variable.
 */
template <class T>
void MagicChangeBag<T>::insert(T newItem)
{
    isMagic = true;
    if (index < PlainBag<T>::CAPACITY)
    {
        PlainBag<T>::data[index] = newItem;
        index++;
    }
    else
    {
        std::cout << "You can not insert anymore! The bag is full" << std::endl;
    }
}

/**
 * This is to remove the item from the bag
 * @param item: The item to be removed.
 * With the magic bag, when a remove() is called we are going to flip the "state" of
 * the bag by making it not a magic bag. When this occurs we are intending to show the values of the bag.
 */
template <class T>
void MagicChangeBag<T>::remove(T item)
{
    isMagic = false;
    for (int i = 0; i < PlainBag<T>::CAPACITY; i++)
    {
        if (PlainBag<T>::data[i] == item)
        {
            for (int j = i; j < PlainBag<T>::CAPACITY - 1; j++)
            {
                PlainBag<T>::data[j] = PlainBag<T>::data[j + 1];
            }
        }
    }
    PlainBag<T>::print();
    index--;
}

#endif // MAGIC_CHANGE_BAG_H