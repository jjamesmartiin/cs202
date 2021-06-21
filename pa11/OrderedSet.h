    #ifndef ORDERED_SET_H
    #define ORDERED_SET_H

    #include "Container.h"

    /// An OrderedSet is a Container that stores a sorted set of unique values.

    class OrderedSet : public Container {
    public:
        OrderedSet();
        void insert(const value_type& value);
        void erase(const value_type& target);
        bool contains(const value_type& target) const;
    };

    #endif /* ORDERED_SET_H */