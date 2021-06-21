#ifndef CONTAINER_H
#define CONTAINER_H

#include <cassert>
#include <iostream>


/// A Container is a general-purpose container that stores a set of possibly
/// non-unique values of type int. Internally, the items are not maintained
/// in any particular order.

class Container {
public:
    using value_type = int;
    using size_type  = std::size_t;

    static const size_type CAPACITY = 20;  ///< Maximum storage capacity.

    /// Constructs the Container.
    Container();

    /// Returns the number of items in the container.
    /// @returns The number of items in the container.
    size_type size() const;

    /// Checks if the container has no items, ie whether size() == 0
    /// @returns true if the container has no items, false otherwise.
    bool empty() const;

    /// Inserts an item into the container.
    /// Internally, the items are not maintained in any particular order.
    /// @pre size() < CAPACITY
    /// @param value Element value to insert.
    void insert(const value_type& value);

    /// Removes all items from the container equal to the target value.
    /// Internally, the items are not maintained in any particular order.
    /// @param target Key value of the items to remove.
    void erase(const value_type& target);

    /// After this call, size() returns zero.
    void clear();

    /// Returns the number of items equal to the target.
    /// @param target Key value of the item(s) to count.
    /// @returns Number of items with value equal to the target.
    size_type count(const value_type& target) const;

    /// Checks if there is an item with its value equal to the target.
    /// @param target Key value of the item to search for.
    /// @returns true if there is such an item, otherwise false.
    bool contains(const value_type& target) const;

    /// Writes all items to an output stream in the format: {42,73,0,-59,7}
    /// @param output The output stream (defaults to std::cout).
    void write(std::ostream& output = std::cout) const;

protected:
    size_type  used;            ///< Number of items in Container.
    value_type data[CAPACITY];  ///< Array of items.
};

#endif /* CONTAINER_H */