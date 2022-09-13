#include "Bag.h"

using value_type = int;
using size_type  = std::size_t;

Bag::Bag() {
    used = 0;
}

size_type Bag::size() const {
    return used;
}

bool Bag::empty() const {
    return (size() == 0);
}

void Bag::insert(const value_type& value) {
    if(size() == CAPACITY) {
        std::cout << "Sorry but there is no more room." << std::endl;
    }
    else {
        data[size()] = value;
        used++;
    }
}

bool Bag::erase_one(const value_type& target) {
    for(int i = 0; i < size(); i++) {
        if(data[i] == target) {
            int temp = data[i];            
            for(int pos = i; pos < size(); pos++) {
                data[pos] = data[pos + 1];
            }
            data[size()] = temp;
            used--;
            return true;
        }
    }
    return false;
}

void Bag::clear() { 
    used = 0;
}

size_type Bag::count(const value_type& target) const { 
    size_type amount = 0; // hold the amount of target
    for(int i = 0; i < size(); i++) {
        if(data[i] == target) {
            amount++;
        }
    }
    return amount;
}

void Bag::write(std::ostream& output) const {
    std::cout << "{";
    int i = 0;
    for(; i < size() - 1; i++) { 
        std::cout << data[i] << ",";
    }
    std::cout << data[used - 1];
    std::cout << "}";
}