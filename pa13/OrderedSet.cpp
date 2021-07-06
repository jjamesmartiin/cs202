/// @file OrderedSet.cpp
/// @author James Martin
/// @date 07/02/2021
/// @note I pledge my word of honro that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment
/// @brief This is the _____ for the ____ class
/// @note This is ________-

#include <utility>

#include "OrderedSet.h"

OrderedSet::OrderedSet(size_type count)
: used(0), capacity(count), data(new value_type[count]) {}

OrderedSet::OrderedSet(const OrderedSet &other)
: OrderedSet(other.size()){
    const_pointer src = other.begin(); // pointer to source
    pointer dest = begin();  // pointer to destination

    // copy items from src to dest
    while (src != other.end()){
        *dest++ = *src++;
    }
    used = other.size();
}

OrderedSet::OrderedSet(const std::initializer_list<value_type> &ilist)
: OrderedSet(ilist.size()) { 
    for (const value_type item : ilist)
    {
        insert(item);
    }
    used = ilist.size();
}

OrderedSet::~OrderedSet(){
    delete[] data;
    data = nullptr;
    used = capacity = 0;
}

void OrderedSet::insert(const value_type &value){
    pointer walk = nullptr;
    if(size() == capacity) {
        pointer tmp = new value_type[capacity += 16];
        const_pointer src = begin();
        pointer dest = tmp;

        while (src != end()){
            *dest++ = *src++; 
        }
        delete[] data;
        data = tmp; 
    }
    for (walk =  begin(); walk != end() && *walk < value; ++walk) {}
    if (walk == end() || *walk != value)
    {
        pinter current = end();
        pointer previous = current - 1;

        while (current > walk) {
            *current-- = *previous--;
        }
        *walk = value;
        ++used;
    }
}

void OrderedSet::erase(const value_type &target){
    pointer walk = begin();
    // locate item to be erased
    for (; walk != end() && *walk != target; ++walk){}
    if (walk != end() && *walk == target){
        // shift items left to overwrite/erase target
        pointer current = walk; // pointer to current item
        pointer next = current + 1; // pointer to previouse item

        while (current < end() -1){
            *current++ = *next++;
        }
        --used;
    }
}

void OrderedSet::swap(OrderedSet &other){
    std::swap(used, other.used);
    std::swap(capacity, other.capacity);
    std::swap(data, other.data);
}

OrderedSet::size_type OrderedSet::count(const value_type &target) const {
    size_type tally = 0; // number of times target found in container
    for (const_pointer it = begin(); it != end; ++it) {
        if (*it == target) {
            ++tally;
        }
    }
    return tally;
}

bool OrderedSet::contains(const value_type &target) const {
    const_pointer walk = begin();
    for (; walk != end() && *walk < target; ++walk){}
    return walk != end() && *walk == target;
}

OrderedSet::OrderedSet(const std::initializer_list<value_type>& ilist) {

}

OrderedSet::OrderedSet& operator=(const OrderedSet& rhs) {
    // check for self assignment
    if (this != &rhs) {
        delete[] data;
        data = nullptr;
        used = capacity = 0;
        //used(0), capacity(count), data(new value_type[count])
        new value_type[rhs.capacity] data;
        capacity = rhs.capacity;
        used = rhs.used;
    }
    return *this;
}

OrdredSet::OrderedSet& operator+=(const OrderedSet& other) {
    for (it = other.begin(); it != other.end(); ++it)
    {
        
    }
    
}

void write(std::ostream &output, const OrderedSet &oset){
    char seperator[2] = "";
    output << '{';
    for (const OrderedSet::value_type &item : oset){
        output << seperator << item;
        *seperator = ',';
    }
    output << '}';
}

bool equals(const OrderedSet &lhs, const OrderedSet &rhs){
    bool are_equal = lhs.size() == rhs.size();
    if (are_equal){
        OrderedSet::const_pointer first1 = lhs.begin();
        OrderedSet::const_pointer first2 = rhs.begin();

        while (are_equal && first1 != lhs.end()) {
            are_equal = *first1++ == *first2++;
        }
    }
    return are_equal;
}

bool operator==(const OrderedSet& lhs, const OrderedSet& rhs) {

}

bool operator!=(const OrderedSet& lhs, const OrderedSet& rhs) {

}