#include "Container.h"
#include <iostream>
using namespace std;

Container::Container(){
    Container::used = 0;
    for (size_t i = 0; i < Container::CAPACITY; i++)
    {
        Container::data[i] = -1;
    }
}

Container::size_type Container::size() const{
    return Container::used;
}

bool Container::empty() const{
    for (size_t i = 0; i < CAPACITY; i++)
    {
        if (data[i] != -1)
        {
            return false;
        }
    }
    return true;
}

void Container::insert(const value_type& value){

    Container::data[Container::used] = value;
    Container::used += 1;
}

void Container::erase(const value_type& target){
    if (target != -1)
    {
        for (size_t i = 0; i < Container::used; i++)
        {
            if (Container::data[i] == target)
            {
                Container::data[i] = -1;
            }
        }
    }
}

void Container::clear(){
    for (size_t i = 0; i < Container::used; i++)
    {
        Container::data[Container::used] = 0;
    }
    Container::used = 0;
}

Container::size_type Container::count(const value_type& target) const{
    Container::size_type matches = 0;

    for (size_t i = 0; i < Container::used; i++)
    {
        if (Container::data[i] == target)
        {
            matches += 1;
        }
    }
    return matches;
}

bool Container::contains(const value_type& target) const{
    bool trueOrFalse = false;
    if (target != -1)
    {
        for (size_t i = 0; i < Container::used; i++)
        {
            if (Container::data[i] == target)
            {
                trueOrFalse = true;
            }
        }
    }
    
    return trueOrFalse;
}

void Container::write(std::ostream& output){
    output << "{";
    for (size_t i = 0; i < used; i++)
    {
        if(data[i] != -1){
            output << Container::data[i] << ",";
        }
    }
    output << "}" << endl;
}