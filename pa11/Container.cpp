#include "Container.h"
#include <iostream>
using namespace std;

// Container constructor function, sets array to -1 values since that number can't be achieved
Container::Container(){
    // sets index to 0 to start
    Container::used = 0;
    // for loop for looping through the array 
    for (size_t i = 0; i < Container::CAPACITY; i++)
    {
        // setting the indexed data array to -1
        Container::data[i] = -1;
    }
}

// function for returning the "size" of the arrary, actually just how many are used since it's a static array
Container::size_type Container::size() const{
    return Container::used;
}

// function for "emptying" the array, -1 is an ignored value and counts as 
bool Container::empty() const{
    // for loop for looping through CAPACTIY times and checking if data is -1 which is considered to be empty
    for (size_t i = 0; i < CAPACITY; i++)
    {
        if (data[i] != -1)
        {
            return false;
        }
    }
    // returns true normally 
    return true;
}

// insert function for inserting value at used and then incrementing it 
void Container::insert(const value_type& value){
    Container::data[Container::used] = value;
    Container::used += 1;
}

// Erase function for writing "-1" to every index of data[]
void Container::erase(const value_type& target){
    if (target != -1) // ignore -1
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

// clear function for "clearing" the array
void Container::clear(){
    for (size_t i = 0; i < Container::used; i++)
    {
        Container::data[Container::used] = -1; // sets the array to -1 to "clear" it
    }
    Container::used = 0; // sets incremented back to 0
}

// count function for counting how many times target matches something in the list
Container::size_type Container::count(const value_type& target) const{
    Container::size_type matches = 0;

    for (size_t i = 0; i < Container::used; i++)
    {
        if (Container::data[i] == target)
        {
            matches += 1; // increment matches
        }
    }
    return matches;
}

// contains function for checking if target exists inside of data[]
bool Container::contains(const value_type& target) const{
    bool trueOrFalse = false;
    if (target != -1) // ignore -1
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

// write function for writing the printing the entier data[] array to output
void Container::write(std::ostream& output) const{
    output << "{";
    for (size_t i = 0; i < used; i++)
    {
        if(data[i] != -1){
            output << Container::data[i] << ",";
        }
    }
    output << "}" << endl;
}