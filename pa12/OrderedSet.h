#ifndef ORDERED_SET_H
#define ORDERED_SET_H
#include <iostream>

/// An OrderedSet is a Container that contains a sorted set of unique values.
/// The storage of the OrderedSet is handled automatically, being expanded as
/// needed.

class OrderedSet {
public:
    /// Member types.
    using value_type    = double;
    using size_type     = std::size_t;
    using pointer       = value_type*;
    using const_pointer = const value_type*;

    /// Default Constructor.
    OrderedSet(size_type count = 0);

    /// Copy Constructor.
    OrderedSet(const OrderedSet& other);

    /// Destructor.
    virtual ~OrderedSet();

    /// Returns a pointer to the first element.
    pointer begin() { return data; }
    const_pointer begin() const { return data; }

    /// Returns a pointer to the end (the element following the last element).
    pointer end() { return begin() + size(); }
    const_pointer end() const { return begin() + size(); }

    /// Checks if the container has no elements, e.g begin() == end()
    /// @returns true if the container is empty, false otherwise.
    bool empty() const;

    /// Returns the number of elements in the container.
    /// @returns The number of elements in the container.
    size_type size() const;

    /// After this call, size() returns zero. The capacity remains unchanged.
    void clear();

    /// Inserts a unique element into the container.
    void insert(const value_type& value);

    /// Removes the target item from the container.
    void erase(const value_type& target);

    /// Exchanges the contents of the container with those of other.
    void swap(OrderedSet& other);

    /// Returns the number of elements with specified value.
    size_type count(const value_type& target) const;

    /// Checks if the container contains an element with the specified value.
    bool contains(const value_type& target) const;

private:
    size_type used;      ///< Number of items in container.
    size_type capacity;  ///< Physical capacity of container.
    pointer   data;      ///< Array of items.
};

// related non-member functions

/// Checks the contents of lhs and rhs are equal, that is, they have the same
/// number of elements and each element in lhs compres equal with the element
/// in rhs at the same position.
bool equals(const OrderedSet& lhs, const OrderedSet& rhs);

/// Performs stream output on OrderedSets, using "{1,2,3}" format.
void write(std::ostream& output, const OrderedSet& oset);
#endif /* ORDERED_SET_H */