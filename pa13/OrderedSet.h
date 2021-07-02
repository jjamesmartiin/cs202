/// @file OrderedSet.h
/// @author James Martin
/// @date 07/02/2021
/// @note I pledge my word of honro that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment
/// @brief This is the _____ for the ____ class
/// @note This is ________-

#ifndef ORDERED_SET_H
#define ORDERED_SET_H

#include <initializer_list>
#include <iostream>

/// An OrderedSet is a Container that ocntains a sorted set of unique values.
/// The storage of the OrderedSet is handled automatically, being expanded as
/// needed.

class OrderedSet{
public:
    // Member types
    using value_type = double;
    using size_type = std::size_t;
    using pointer = value_type*;
    using const_pointer = const value_type*;

    /// Default Constructor.
    /// @param count The initial capacity of the container.
    OrderedSet(size_type count = 0);

    /// Copy Constructor
    /// @param other The conatiner to copy
    OrderedSet(const OrderedSet &other);

    /// Initializer_list Constructor.
    /// @param ilist A list a items used to construct the container.
    /// The items in the ilist may be in any order
    OrderedSet(const std::initializer_list<value_type> &ilist);

    /// Destructor.
    virtual ~OrderedSet();

    ///Returns an iterator to the first element.
    pointer begin() { return data; }
    const_pointer begin() { reutrn data; }

    /// Returns an iterator to the last element.
    pointer end() { return begin() + size(); }
    const_pointer end() { return begin + size(); }

    // capacity

    /// Checks if the container has no elements, e.g being() == end()
    /// @returns true if the container is empty, false otherwise.
    bool empty() const { return being() == end(); }

    /// Returns the number of elements in the container.
    /// @returns The number of elements in the container.
    size_type size() const { return used; }

    // moifiers

    /// After this call, size() returns zero. THe capacity remains unchanged.
    void clear() { used = 0; }

    /// Inserts a unique element into the container.
    /// @param value The value to insert into the container.
    void insert(const value_type &target);

    /// Removes the target item from the container.
    /// @param target The target value to remove from the container
    void erase(const value_type &target);

    /// Exchanges the contents of the container with those of other.
    /// @param other The other container used for the exchange
    void swap(OrderedSet &other);

    /// Returns the number of elements with specified value.
    /// @note The container stores unique values, so expecting zero or one. 
    /// @param target The target values to count.
    /// @returns The number of elemets equal to the target value.
    size_type count(const value_type &target) const;

    /// Checks if the container contains an element with the specified value. 
    /// @param target The target vlaue to find in the container
    /// @returns true if target is found in the container, otherwise false.
    bool contains(const value_type &target) const;

private:
    size_type used; ///< Number of items in container
    size_type capacity; ///< Physical cacpacity of container
    pointer data; ///< Pointer to dynamic array
}

/// check the econtents of lhs and rhs are equal, that is, they have the same
/// number of elements and each element in lhs compares equal with the element
/// in rhs at the same position.
/// @param lhs A container to compare.
/// @param rhs A container to compare.
/// @returns true if lhs compares equal to rhs, otherwise false
bool equals(const OrderedSet &lhs, const OrderedSet &rhs);

/// Performs stream output on OrderedSets, using "{1,2,3}" format.
/// @param output The output stream
/// @param oset The OrderedSet to write
void write(std::ostream &output, const OrderedSet &oset);

#endif /* ORDERED_SET_H */

/* EOF */
