#ifndef BAG_H
#define BAG_H
	
#include <cassert>
#include <iostream>
	
/// A Bag is a general-purpose container that stores a set of possibly
/// non-unique values of type int. Internally, the items are not maintained
/// in any particular order.
	
class Bag {
public:
    using value_type = int;
    using size_type  = std::size_t;
	
    static const size_type CAPACITY = 16;  ///< Maximum storage capacity.
	
    /// Constructs the Bag.
    Bag();
	
    /// Returns the number of items in the bag.
    /// @returns The number of items in the bag.
    size_type size() const;
	
    /// Checks if the bag has no items, ie whether size() == 0
    /// @returns true if the bag has no items, false otherwise.
    bool empty() const;
	
    /// Inserts an item into the bag.
    /// Internally, the items are not maintained in any particular order.
    /// @pre size() < CAPACITY
    /// @param value Element value to insert.
    void insert(const value_type& value);
	
    /// If target was in the bag, then one copy has been removed;
    /// otherwise the bag is unchanged.
    /// Internally, the items are not maintained in any particular order.
    /// @param target Key value of the items to remove.
    /// @return true if one copy was removed; false if nothing removed.
    bool erase_one(const value_type& target);
	
    /// After this call, size() returns zero.
    void clear();
	
    /// Returns the number of items equal to the target.
    /// @param target Key value of the item(s) to count.
    /// @returns Number of items with value equal to the target.
    size_type count(const value_type& target) const;

    /// Writes all items to an output stream in the format: {42,73,0,-59,7}
    /// @param output The output stream (defaults to std::cout).
    void write(std::ostream& output = std::cout) const;
	
private:
    size_type  used;            ///< Number of items in Bag.
    value_type data[CAPACITY];  ///< Array of items.
};
	
#endif /* BAG_H */