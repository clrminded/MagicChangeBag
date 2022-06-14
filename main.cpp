#include <iostream>
#include "PlainBag.h"
#include "MagicChangeBag.h"

/**
 * PURPOSE:
 * This assignment will help you get practice with:  
 * 1. Abstract Data Types 
 * 2. Inheritance 
 * 3. Polymorphism 
 * 4. C++ pointers 
 * 5. C++ Classes 
 * 6. C++ virtual and pure virtual functions 
 * 7. C++ Class Templates 
 * 8. C++ Arrays 
 *
 * TASK:
 * A container class is a data type that is capable of holding a collection of items and provides 
 * functions to access them. Bag is an example of a container class. It is an unordered collection of 
 * items that may have duplicates.  
 * In this assignment, you are asked to design and develop an abstract Bag class, called 
 * BagInterface, with the following fixed collection of operations: 
 * 1. Insert an item of any type into a bag 
 * 2. Query the bag contents: two queries 
 *  o Is an item in the bag? 
 *  o How many copies of an item is in the bag? 
 * 3. Remove an item from the bag 
 * 4. Clear the bag 
 * 5. Get the size of the bag  
 *  o How many items are there in the bag? 
 * 6. Check if the bag is empty 
 * 7. Check if the bag is full 
 *  o Assume the bag capacity is 20 
 *
 * In addition to BagInterface, you are asked to implement two classes of bag
 * implementations: PlainBag and MagicChangeBag. PlainBag is a simple container that
 * holds items of any type using an array implementation. MagicChangeBag is also very similar
 * to PlainBag, with two exceptions. When an item is inserted into a magic change bag, it’ll
 * magically disappear, and bag looks empty. Whenever a remove operation is invoked, all the
 * items, except the one is removed will appear.  
 * 
 * IMPORTANT NOTES:
 * 1. You are not allowed to modify main.cpp implementation. Please use it as it is. 
 */

template <class T>
void testBag(BagInterface<T> &bag)
{
    T value;
    T item1 = 1;
    T item2 = 2;
    for (int i = 0; i < 20; i++)
    {
        value = rand() % 6 + 1;
        // assume storing integers for sake of simplicity
        bag.insert(value);
    }
    bag.print();
    std::cout << "\nNumber of items:" << bag.size();
    std::cout << "\nNumber of ones:" << bag.itemCount(item1);
    bag.remove(item1);
    bag.print();
    std::cout << "\nNumber of items:" << bag.size();
    std::cout << "\nNumber of ones:" << bag.itemCount(item1);
    std::cout << "\nNumber of twos:" << bag.itemCount(item2);
}

int main()
{
    std::cout << "\n..............................." << std::endl;
    std::cout << "Testing Plain Bag" << std::endl;
    BagInterface<int> *bag = new PlainBag<int>;
    testBag(*bag);
    std::cout << "\n..............................." << std::endl;
    std::cout << "Testing Magic Change Bag" << std::endl;
    bag = new MagicChangeBag<int>;
    testBag(*bag);
    return 0;
}


/**
 * SAMPLE RUN
 * ............................... 
 * Testing Plain Bag 
 *
 * Bag content:2 2 6 3 5 3 1 3 6 2 1 6 1 3 4 6 2 2 5 5  
 * Number of items:20 
 * Number of ones:3 
 * Bag content:2 2 6 3 5 3 3 6 2 1 6 1 3 4 6 2 2 5 5  
 * Number of items:19 
 * Number of ones:2 
 * Number of twos:5 
 * ............................... 
 * Testing Magic Change Bag 
 *  
 * Bag content: 
 * Number of items:0 
 * Number of ones:0 
 * Bag content:4 2 4 6 5 4 4 1 3 2 2 3 3 2 3 4 2 2 4 4  
 * Bag content:4 2 4 6 5 4 4 3 2 2 3 3 2 3 4 2 2 4 4  
 * Number of items:19 
 * Number of ones:0 
 * Number of twos:6
 */