/** @file BagInterface.h 
 * An interface describes the behavior or capabilities of a C++ class without committing to a particular implementation of that class.
 *
 * The C++ interfaces are implemented using abstract classes and these abstract classes should not be confused with data abstraction,
 * which is a concept of keeping implementation details separate from associated data.
 * 
 * A class is made abstract by declaring at least one of its functions as pure virtual function. 
 * A pure virtual function is specified by placing "= 0" in its declaration as follows
 *
 * The purpose of an abstract class (often referred to as an ABC) is to provide an appropriate base class from which other classes can inherit.   * Abstract classes cannot be used to instantiate objects and serves only as an interface. 
 * Attempting to instantiate an object of an abstract class causes a compilation error
 *
 * Thus, if a subclass of an ABC needs to be instantiated, it has to implement each of the virtual functions, which means that it supports the
 * interface declared by the ABC. Failure to override a pure virtual function in a derived class, then attempting to instantiate objects of that
 * class, is a compilation error.
 * 
 * Classes that can be used to instantiate objects are called concrete classes.
 * 
 * An object-oriented system might use an abstract base class to provide a common and standardized interface appropriate for all the external
 * applications. Then, through inheritance from that abstract base class, derived classes are formed that operate similarly.
 * 
 * The capabilities (i.e., the public functions) offered by the external applications are provided as pure virtual functions in the abstract
 * base class. The implementations of these pure virtual functions are provided in the derived classes that correspond to the specific types 
 * of the application.
 * 
 * This architecture also allows new applications to be added to a system easily, even after the system has been defined.
 */
#ifndef BAG_INTERFACE_H
#define BAG_INTERFACE_H

#include <cstdlib> // included this to make the rand() in main.cpp function properly.

template <class T>
class BagInterface
{
public:
    /** 
     * insert an item of type T into a bag 
     * @param newItem: The item that will be inserted into the bag. 
     */
    virtual void insert(T newItem) = 0;

    /** 
     * Tests whether this bag contains a given item.
     * @param anItem: The item to check if it is currently in the bag.
     * @return true if anItem is currently in the bag, otherwise false. 
     */
    virtual bool contains(T anItem) = 0;


    /** 
     * remove one item from the bag 
     * @param anItem: The item that will be removed.
     */
    virtual void remove(T anItem) = 0;

    /** 
     * This will clear out all the items currently in the bag 
     */
    virtual void clear() = 0;

    /** 
     * Counts the number of times a given item appears in this bag.
     * @param anItem: The item to be counted
     * @return the number of times anEntry appears in the bag. 
     */
    virtual int itemCount(T anItem) = 0;

    /** 
     * Gets the current number of items
     * @return The integer number of items currently in bag. 
     */
    virtual int size() const = 0;

    /** check to see if bag is empty 
     * @return true if there are 0 items in the bag, otherwise false. 
     */
    virtual bool isEmpty() const = 0;

    /** check to see if the bag is full
     * @return true if if there are 20 items in the bag and there can 
     * be no more items allowed to be inserted into the bag without another being removed. 
     */
    virtual bool isFull() const = 0;

    /** 
     * print the output of the contents currently in the bag 
     */
    virtual void print() const = 0;
};
#endif // BAGINTERFACE_H
