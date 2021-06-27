#include "OrderedSet.h"
using namespace std;

OrderedSet::OrderedSet(){
}

void OrderedSet::insert(const value_type& value){
    size_type index = 0; // index of insertion point

    // locate insertion point
    for (; index < size() && data[index] < value; ++index){

    }
    if (index == size() || (index < size()) && data[index] != value){
        assert(size() < CAPACITY);

        // copy items "right" to make room for new item
        for (auto i = size(); i > index; --i)
        {
            data[index] = value;
            ++used;
        }
    }
}
void OrderedSet::erase(const value_type& target){
    size_type index = 0;

    for (; index < size() && data[index] != target; ++index){

    }

    if (index != size())
    {
        for (auto i = index; i < size(); ++i)
        {
            data[i] = data[i + 1];
        }
        --used;
    }
}

bool OrderedSet::contains(const value_type& target) const{
    size_type index = 0;

    for (; index < size() && data[index] < target; ++index){

    }
    return index != size() && data[index] == target;
}
